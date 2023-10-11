#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#include "processes.h"


int main(int argc, char *argv[])
{
    char pathname[PATHNAME_MAX];
    char filename[FILENAME_MAX];

    if (argc != 2)
    {
        exit(1);
    }
    else
    {
        strcpy(filename, argv[1]);
        sprintf(pathname, "%s%s", PATH, filename);
    }
    printf("Proces macierzysty:\n");
    processes();

    printf("\nProces potomne:\n");
    for (int i = 0; i < 3; i++)
    {
        switch (fork())
        {
        case -1:
            perror("fork error");
            exit(1);
        case 0:
            execlp(pathname, filename, NULL);
            perror("execl error");
            _exit(2);
            break;
        default:
        if(wait(NULL)==-1)
        {
                perror("wait() error");
                    exit(1);
        }
        break;
        }
    }

    return 0;
}