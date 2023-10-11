/*

Autor: Bartosz Ludera

Program słyży do obsługi sygnałów:
1) operacja domyślna
2) operacja ignoraowania sygnały
3) własna obsługa sygnału

Uruchomienie:
wpisz: make runzad1 o=[d,i,w] s=[nr_sygnalu]

*/

#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>

void sig_hand(int syg)
{
    extern const char *const sys_siglist[];
    printf("Dotarł sygnał o nazwie: %s, i numerze: %d\n", sys_siglist[syg], syg);
}

int main(int argc, char *argv[])
{

    char *wykonaj = argv[1];
    int syg = atol(argv[2]);

    if (argc != 3 && argc != 2)
    {
        printf("aby uruchomic, wpisz: ./nazwa programu <operacja dla sygnalu> [nr_sygnalu]\n");
        printf("parametry:\n d - operacja domyslna\n i - ignorowanie\n w - obsluga wlasna\n");
        fprintf(stderr, "niepoprawna liczba argumentow!\n");
        exit(1);
    }
    printf("PID procesu: %d\n", getpid());

    if (strcmp(wykonaj, "d") == 0)
    {
        if (signal(syg, SIG_DFL) == SIG_ERR)
        {
            perror("operacja zakonczona niepowodzeniem\n");
            exit(1);
        }
        else
        {
            sig_hand(syg);

        }
    }
    else if (strcmp(wykonaj, "i") == 0)
    {
        if (signal(syg, SIG_IGN) == SIG_ERR)
        {
            perror("operacja zakonczona niepowodzeniem\n");
            exit(1);
        }
        else
        {
            sig_hand(syg);

        }
    }
    else if (strcmp(wykonaj, "w") == 0)
    {
        if (signal(syg, sig_hand) == SIG_ERR)
        {
            perror("operacja zakonczona niepowodzeniem\n");
            exit(1);
        }
        else
        {
            sig_hand(syg);

        }
    }
    else
    {
        pause();
    }
}
