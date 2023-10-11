/*
Autor: Bartosz Ludera

Własna biblioteka prostych funkcji do tworzenia, otwierania, uzyskiwania wartości, 
operowania, zamykania i usuwania semafora.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

sem_t *stworz_semafor(const char *name)
{
    sem_t *semafor_adress;
    if ((semafor_adress = sem_open(name, O_CREAT | O_EXCL, 0644, 1)) == SEM_FAILED)
    {
        perror("błąd : tworzenia semafora");
        exit(EXIT_FAILURE);
    }
    else
    {
        return semafor_adress;
    }
}

sem_t *otworz_semafor(const char *name)
{
    sem_t *semafor_adress;
    if ((semafor_adress = sem_open(name, 0)) == SEM_FAILED)
    {
        perror("błąd : otworzenia semafora");
        exit(EXIT_FAILURE);
    }
    else
    {
        return semafor_adress;
    }
}

void zamknij_semafor(sem_t *sem_t)
{
    if (sem_close(sem_t) == -1)
    {
        perror("błąd : zamykania semafora");
        exit(EXIT_FAILURE);
    }
}

void wartosc_semafor(sem_t *sem, int *sval)
{
    if (sem_getvalue(sem, sval) == -1)
    {
        perror("błąd : odczytywania wartości semafora");
        exit(EXIT_FAILURE);
    }
}

void podnies_semafor(sem_t *sem)
{
    if (sem_post(sem) == -1)
    {
        perror("błąd : podnoszenia semafora");
        exit(EXIT_FAILURE);
    }
}

void opusc_semafor(sem_t *sem)
{
    if (sem_wait(sem) == -1)
    {
        perror("błąd :  opuszczania semafora");
        exit(EXIT_FAILURE);
    }
}

void usun_semafor(const char *name)
{
    if (sem_unlink(name) == -1)
    {
        perror("błąd : usuwania semafora");
        exit(EXIT_FAILURE);
    }
}