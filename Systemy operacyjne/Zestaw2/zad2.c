/*

Autor: Bartosz Ludera

Program poprzez funkcję exec w procesie potomnym innego procesu wysyła 
do niego sygnał poprzez funkcję systemową kill.

Uruchomienie:
wpisz: make runzad2 o=[d,i,w] s=[nr_sygnalu] ./(nazwa zadania z podpunktu a))

*/

#define _XOPEN_SOURCE 500
#define _POSIX_C_SOURCE 200112L

#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

int main(int argc, char *argv[])
{

	int pid = 0;

	if (argc < 4)
	{
		printf("Błąd: Za mala ilosc argumentow!\n");
		exit(EXIT_FAILURE);
	}
	else if (argc > 4)
	{
		printf("Błąd: Za duza ilosc argumentow!\n");
		exit(EXIT_FAILURE);
	}

	printf("PID procesu: %d\n", getpid());

	switch (pid = fork())
	{
	//proces childa
	case -1:
		perror("fork error");
		exit(EXIT_FAILURE);
	case 0:
		if (execl(argv[3], argv[3], argv[2], argv[1], NULL) == -1)
		{
			perror("Blad: execl error");
			exit(EXIT_FAILURE);
		}

		break;

	default:
		//proces macierzysty

		sleep(1);

		if (kill(pid, 0) == -1)
		{
			perror("Blad: child nie istnieje");
			exit(EXIT_FAILURE);
		}

		if (kill(pid, atoi(argv[1])) == -1)
		{
			perror("kill error");
			exit(EXIT_FAILURE);
		}
	}

	if (strcmp(argv[1], "i") == 0)
	{
		sleep(1);

		printf("Program się zakończył ale wciaz istnieją proces zombie (umarly)\n");
		kill(pid, SIGKILL);
		printf("Sygnału SIGKILL zostal wyslany do procesu zombie\n");
	}
}