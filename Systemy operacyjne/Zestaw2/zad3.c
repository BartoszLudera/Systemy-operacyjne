/*

Autor: Bartosz Ludera

Program uruchamia w procesie macierzysytm proces potomny i sprawdza czy 
stał się liderem nowej grupy procesów (poprzez funkcje stpgid).

Uruchomienie:
wpisz: make runzad3 o=[d,i,w] s=[nr_sygnalu] ./zad3a ./(nazwa programu zad1))

*/

#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[])
{

    int childPid = 0, groupChildPid = 0;

    if (argc < 5)
    {
        printf("Błąd: Za mala ilosc argumentow!");
        exit(EXIT_FAILURE);
    }
    else if (argc > 5)
    {
        printf("Błąd: Za duza ilosc argumentow!");
        exit(EXIT_FAILURE);
    }

    printf("PID procesu: %d\n", getpid());

    switch (childPid = fork())
    {
    case -1:
        perror("fork error");
        exit(EXIT_FAILURE);
    case 0:
        if (execl(argv[3], argv[3], argv[2], argv[1], argv[4], NULL) == -1)
        {
            perror("execl error");
            exit(EXIT_FAILURE);
        }

        break;

    default://proces macierzysty
        sleep(1);

        groupChildPid = getpgid(childPid);

        if (kill(-1 * groupChildPid, 0) == -1)
        {
            perror("Child doesn't exist");
            exit(EXIT_FAILURE);
        }

        if (kill(-1 * groupChildPid, atoi(argv[1])))
        {
            perror("kill error");
            exit(EXIT_FAILURE);
        }
    };

    sleep(1);

    if (strcmp(argv[2], "i") == 0)
    {
        printf("Program zakończył się, a nadal istnieją procesy zombie\n");
        printf("Wysyłanie sygnału SIGKILL do grupy procesów zombie\n");
        kill(-1 * groupChildPid, SIGKILL);
    }
}