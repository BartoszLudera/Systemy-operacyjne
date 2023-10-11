#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "processes.h"

int main()
{
    pid_t cpid;
    int i;

    printf("Porces macierzysty: \n");
    processes();
    printf("Porces potomny: \n");

    for (i = 1; i <= 3; i++)
    {
        switch (fork())
        {
        case -1:
            perror("fork error");
            exit(1);
            break;
        case 0:
            printf("%d. ", i);
            processes();
            break;
            
        default:
            cpid = wait(0);
            break;
        };
    }
    return 0;
}

