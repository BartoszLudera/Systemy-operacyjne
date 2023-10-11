/*
Autor: Bartosz Ludera

Program powielacz.c tworzy podaną ilość kopii programu inkrementator.c, który implementuje 
problem korzystania z zasobu współdzielonego.
*/

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

#include "semafory.h"

#define SCIEZKA "./"

char semafor_name[20];
bool synchronizacja;

void wyjscie(void)
{
    if (synchronizacja)
    {
        usun_semafor(semafor_name);
    }
}

void sygnal_wyjscie(int signal)
{
    if (synchronizacja)
    {
        printf("Wykonano sygnał przerwania - usuwanie semafora\n");
        usun_semafor(semafor_name);
    }
    _exit(EXIT_SUCCESS);
}

// argumenty [0] nazwa_programu [1] nazwa_podprogramu [2] ilosc_inkrementatorow [3]
//ilosc_sekcji_krytycznych [4] plik_input/output [5] nazwa_semafora [6] synchronizacja

int main(int argc, char *argv[])
{

    if (argc != 7)
    {
        printf("Błąd : niepoprawna liczba argumentów!\n");
        printf("Wywołaj program wpisując: %s nazwa_podprogramu ilosc_inkrementatorow ilosc_sekcji_krytycznych plik_input/output nazwa_semafora czy_synchronizowac\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (atexit(wyjscie) != 0)
    {
        perror("atexit error");
        exit(EXIT_FAILURE);
    }

    if (signal(SIGINT, sygnal_wyjscie) == SIG_ERR)
    {
        perror("Błąd : signal");
        exit(EXIT_FAILURE);
    }

    int stat_lock;
    int ilosc_inkrementatorow;
    int file;

    char temp[strlen(SCIEZKA) + strlen(argv[1]) + 1];

    ilosc_inkrementatorow = atoi(argv[2]);

    strcpy(semafor_name, argv[5]);

    if (atoi(argv[6]) == 0)
    {
        synchronizacja = false;
    }
    else
    {
        synchronizacja = true;
    }

    if ((file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
    {
        printf("Błąd : otwarcia pliku %s do zapisu", argv[1]);
        perror("Błąd : pliku");
        exit(EXIT_FAILURE);
    }

    if (write(file, "0", 2) == -1)
    {
        perror("Błąd : write do pliku");
        exit(EXIT_FAILURE);
    }

    if (close(file) == -1)
    {
        perror("Błąd : zamknięcia pliku");
        exit(EXIT_FAILURE);
    }

    if (synchronizacja)
    {
        sem_t *semafor = stworz_semafor(semafor_name);
        int wartosc_semafora;
        wartosc_semafor(semafor, &wartosc_semafora);
        printf("Utworzono semafor %s (%p) o wartości %d\n", semafor_name, (void *)semafor, wartosc_semafora);
    }

    for (int i = 0; i < ilosc_inkrementatorow; i++)
    {

        switch (fork())
        {
        case -1:
            perror("fork error");
            exit(EXIT_FAILURE);
        case 0:
        //proces potomny

            sprintf(temp, "%s%s", SCIEZKA, argv[1]);
            execl(temp, argv[1], argv[3], argv[4], argv[5], argv[6], NULL);
            perror("execl error");
            exit(EXIT_FAILURE);

            break;

        default:
        //proces macierzysty

            break;
        }
    }

    for (int i = 0; i < ilosc_inkrementatorow; i++)
    {
        if (wait(&stat_lock) == -1)
        {
            perror("Błąd : wait");
            exit(EXIT_FAILURE);
        }
    }

    if ((file = open(argv[4], O_RDONLY, 0644)) == -1)
    {
        printf("Błąd : otwarcia pliku %s do odczytu", argv[4]);
        perror("Błąd : pliku");
        exit(EXIT_FAILURE);
    }

    int odczyt;
    char bufor[10];

    odczyt = read(file, &bufor, 10);
    if (odczyt == -1)
    {
        printf("Błąd : odczytu z pliku\n");
        exit(EXIT_FAILURE);
    }
    else if (odczyt == 0)
    {
        printf("Plik jest pusty.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        bufor[odczyt] = '\0';
        if (atoi(bufor) == (atoi(argv[2]) * atoi(argv[3])))
        {
            printf("\nInkrementacja sie udala. Liczba w pliku: %s\n", bufor);
        }
        else
        {
            printf("\nInkrementacja sie nie udala. Liczba w pliku: %s, oczekiwano: %d\n", bufor, (atoi(argv[2]) * atoi(argv[3])));
        }
    }

    if (close(file) == -1)
    {
        perror("Błąd : zamknięcia pliku");
        exit(EXIT_FAILURE);
    }

    return 0;
}