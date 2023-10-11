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
        sleep(1);
        switch (fork())
        {
        case -1:
            perror("fork error");
            break;
        case 0:
            sleep(5-i);
            printf("%d. ", i);
            processes();
            break;

        default:
            break;
        };
    }
    return 0;
}
