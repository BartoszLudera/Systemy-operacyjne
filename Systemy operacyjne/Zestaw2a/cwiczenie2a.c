/*
Autor: Bartosz Ludera

Program wypisujacy identyfikatory UID, GID, PID, PPID i PGID dla 
danego procesu używając fukcji clone.
*/


#define _XOPEN_SOURCE 500
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sched.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define SIZESTACK (1024 * 1024) //rozmiar stosu

void processes() //funkcja wypisująca identyfikatory procesu
{
	int PID = getpid();
	int UID = getuid();
	int GID = getgid();
	int PPID = getppid();
	int PGID = getpgid(PID);
	printf("UID %d / GID %d / PID %d / PPID %d / PGID %d\n", UID, GID, PID, PPID, PGID);
}

int child_proc(void *arg) // Uruchamia funkcję do sklonowania procesu potomnego
{
	sleep(3);
	return 0;
}

int main(int argc, char *argv[])
{
	char *stack;	 //dol stosu
	char *stackhead; //gora stosu

	char *str = "przykladowy tekst\n";

	pid_t pid;
	int status;

	stack = (char *)malloc(SIZESTACK); //zajecie pamieci na stosie

	if (!stack) //blad stosu
	{
		perror("blad : alokacja stosu");
		exit(1);
	}

	stackhead = stack + SIZESTACK - 1;

	//proces macierzysty
	printf("Macierzysty: \n");
	processes();

	//procesy potomne
	printf("Potomny: \n");

	int i = 0;
	for (i; i < 3; i++)
	{
		pid = clone(child_proc, stackhead, SIGCHLD, str); //uzycie funkcji clon()

		if (pid == -1) //blad funkcji clon
		{
			perror("blad : clone error");
			free(stack);
			exit(1);
		}
		printf("UID %d / GID %d / PID %d / PPID %d / PGID %d\n", getuid(), getgid(), pid, getppid(), getpgid(pid));

		waitpid(pid, &status, 0);
	}
}