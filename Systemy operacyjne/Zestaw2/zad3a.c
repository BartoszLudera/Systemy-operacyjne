/*

Autor: Bartosz Ludera

Program pośredni który tworzy 3 procesy potomne poprzez funckje exec uruchamiając program 
z zad1.

Uruchomienie:
uruchomi się wraz z uruchomieniem programu zad3

*/

#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, char *argv[])
{

	if (argc < 4)
	{
		printf("Błąd: Za mala ilosc argumentow!");
		exit(EXIT_FAILURE);
	}
	else if (argc > 4)
	{
		printf("Błąd: Za duża ilosc argumentow");
		exit(EXIT_FAILURE);
	}

	setpgid(0, 0);
	int status = 0;

	printf("PID podprocesu: %d\n", getpgrp());

	for (int i = 0; i < 3; i++)
	{

		switch (fork())
		{
		case -1:
			perror("fork error");
			exit(EXIT_FAILURE);
		case 0:

			if (execl(argv[3], argv[3], argv[2], argv[1], NULL) == -1)
			{
				perror("execl error");
				exit(EXIT_FAILURE);
			}

			perror("execl error");
			exit(EXIT_FAILURE);

			break;

		default:

			break;
		};
	}

	if (signal(atoi(argv[1]), SIG_IGN) == SIG_ERR)
	{
		perror("Blad : Funkcji signal ma problem z SIGINT");
		exit(EXIT_FAILURE);
	}

	int pid;

	for (int i = 0; i < 3; i++)
	{
		if ((pid = wait(&status)) == -1)
		{
			perror("wait error");
			exit(EXIT_FAILURE);
		}
		printf("Proces o pid zakonczony statusem %d: %d\n", pid, status);
	}
}