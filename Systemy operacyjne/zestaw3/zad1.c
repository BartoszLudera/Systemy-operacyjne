/*
Autor: Bartosz Ludera

Przy pomocy potoków nienazwanych systemu UNIX zaimplementowa´c problem ,,Producenta i konsumenta”. Dla zademonstrowania, ˙ze nie dosz lo do utraty ani zwielokrotnienia towaru, niech Producent pobiera ,,surowiec” (np. porcje bajt´ow) z pliku tekstowego
i wstawia go jako towar do potoku, a Konsument niech umieszcza pobrany z potoku
towar w innym pliku tekstowym
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>

int main(int argc, char *argv[])
{

    char bufor[1024];
    char info[1038];
    int file;
    int filedes[2];
    int odczyt;
    const size_t producnetDataSize = 20; 
    const size_t konsumentDataSize= 10;
    int stat_lock;
    const double waitLen = 3.0;

    if (argc != 3)
    {
        printf("Błąd: niepoprawna liczba argumentów!\n");
        printf("Wywołaj program wpisując: %s plikin.txt plikout.txt\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (pipe(filedes) == -1)
    {
        perror("Błąd : potoku");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    switch (fork())
    {
    case -1:
        perror("fork error");
        exit(EXIT_FAILURE);
    case 0:

        if (close(filedes[1]) == -1)
        {
            perror("Błąd : zamknięcia potoku");
            exit(EXIT_FAILURE);
        }

        if ((file = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
        {
            printf("Błąd otwarcia pliku %s do zapisu", argv[2]);
            perror("Błąd : pliku");
            exit(EXIT_FAILURE);
        }

        while (1)
        {
            sleep((double)(rand() % (int)(waitLen * 100)) / 100);

            odczyt = read(filedes[0], &bufor, konsumentDataSize);
            if (odczyt == -1)
            {
                printf("Błąd odczytu z potoku\n");
                exit(EXIT_FAILURE);
            }
            else if (odczyt == 0)
            {
                break;
            }
            else
            {
                write(file, &bufor, odczyt);
                bufor[odczyt] = '\0';
                sprintf(info, "%s%s%s", "Konsumuje <= ", bufor, "\n");
                write(STDOUT_FILENO, info, strlen(info));
            }
        }

        if (close(file) == -1)
        {
            perror("Błąd zamknięcia pliku wyjścia");
            exit(EXIT_FAILURE);
        }

        if (close(filedes[0]) == -1)
        {
            perror("Błąd zamknięcia potoku");
            exit(EXIT_FAILURE);
        }

        break;

    default:

        if (close(filedes[0]) == -1)
        {
            perror("Błąd zamknięcia potoku");
            exit(EXIT_FAILURE);
        }

        if ((file = open(argv[1], O_RDONLY, 0644)) == -1)
        {
            printf("Błąd otwarcia pliku %s do odczytu", argv[1]);
            perror("Błąd pliku");
            exit(EXIT_FAILURE);
        }

        while (1)
        {

            sleep((double)(rand() % (int)(waitLen * 100)) / 100);

            odczyt = read(file, &bufor, producnetDataSize);
            if (odczyt == -1)
            {
                printf("Błąd odczytu z pliku\n");
                exit(EXIT_FAILURE);
            }
            else if (odczyt == 0)
            {
                break;
            }
            else
            {
                write(filedes[1], &bufor, odczyt);
                bufor[odczyt] = '\0';
                sprintf(info, "%s%s%s", "Produkuje -> ", bufor, "\n");
                write(STDOUT_FILENO, info, strlen(info));
            }
        }

        if (close(file) == -1)
        {
            perror("Błąd : zamknięcia pliku wyjścia");
            exit(EXIT_FAILURE);
        }

        if (close(filedes[1]) == -1)
        {
            perror("Błąd : zamknięcia potoku");
            exit(EXIT_FAILURE);
        }

        if (wait(&stat_lock) == -1)
        {
            perror("Błąd : wait");
            exit(EXIT_FAILURE);
        }

        break;
    }

    return 0;
}
