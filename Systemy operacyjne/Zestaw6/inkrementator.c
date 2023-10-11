/*
Autor: Bartosz Ludera

Program inkrementator.c odczytuje plik numer.txt, inkrementuje zawartą w nim liczbę i zapisuje ją z powrotem do pliku
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>

#include "semafory.h"

// argumenty [0] nazwa_programu [1] ilosc_sekcji_krytycznych
//[2] plik_input_output [3] nazwa_semafora [4] synchronizacja
int main(int argc, char *argv[])
{

    char bufor[100];
    char info[200];
    int odczyt;
    int ilosc_sekcji_krytycznych;
    int value;
    int wartosc_semafora;
    int file;
    bool synchronizacja;
    sem_t *semafor;
    const double wait_len = 2.5;

    if (argc != 5)
    {
        printf("Błąd : niepoprawna liczba argumentów!\n");
        printf("Wywołaj podprogram wpisując: %s ilosc_sekcji_krytycznych plik_input_output nazwa_semafora czy_synchronizowac\n", argv[0]);
        _exit(EXIT_FAILURE);
    }

    ilosc_sekcji_krytycznych = atoi(argv[1]);

    if (atoi(argv[4]) == 0)
    {
        synchronizacja = false;
    }
    else
    {
        synchronizacja = true;
    }

    if (synchronizacja)
    {
        semafor = otworz_semafor(argv[3]);
    }

    for (int i = 0; i < ilosc_sekcji_krytycznych; i++)
    {
        srand(time(NULL));
        sleep((double)(rand() % (int)(wait_len * 100)) / 100);

        if (synchronizacja)
        {
            wartosc_semafor(semafor, &wartosc_semafora);
            printf("PID %d przed SK semafor: %d\n", getpid(), wartosc_semafora);
            opusc_semafor(semafor);
        }

        if ((file = open(argv[2], O_RDONLY, 0644)) == -1)
        {
            printf("Błąd : otwarcia pliku %s do odczytu", argv[2]);
            perror("Błąd : pliku");
            _exit(EXIT_FAILURE);
        }

        odczyt = read(file, bufor, 10);
        if (odczyt == -1)
        {
            printf("Błąd : odczytu z pliku\n");
            _exit(EXIT_FAILURE);
        }
        else if (odczyt == 0)
        {
            break;
        }
        else
        {
            bufor[odczyt] = '\0';
            wartosc_semafor(semafor, &wartosc_semafora);
            sprintf(info, "\tPID %d semafor %d odczytany numer: %s SK: %d", getpid(), wartosc_semafora, bufor, i);

            printf("%s\n", info);
        }

        if (close(file) == -1)
        {
            perror("Błąd : zamknięcia pliku");
            exit(EXIT_FAILURE);
        }

        value = atoi(bufor);
        value++;
        sprintf(bufor, "%d", value);
        printf("liczba: %d", value);

        sleep((double)(rand() % (int)(wait_len * 100)) / 100);

        if ((file = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
        {
            printf("Błąd : otwarcia pliku %s do zapisu", argv[1]);
            perror("Błąd : pliku");
            _exit(EXIT_FAILURE);
        }

        if (write(file, bufor, strlen(bufor)) == -1)
        {
            perror("Błąd : write do pliku");
            _exit(EXIT_FAILURE);
        }

        if (close(file) == -1)
        {
            perror("Błąd : zamknięcia pliku");
            exit(EXIT_FAILURE);
        }

        if (synchronizacja)
        {
            podnies_semafor(semafor);
            wartosc_semafor(semafor, &wartosc_semafora);
            printf("PID %d po SK semafor: %d\n", getpid(), wartosc_semafora);
        }
    }

    if (synchronizacja)
    {
        zamknij_semafor(semafor);
    }

    return 0;
}