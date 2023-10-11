#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef FUNKCJA
#define FUNKCJA

void processes()
{
    printf("UID: %d, GID: %d, PID: %d, PPID: %d, PGID: %d\n", getuid(), getgid(), getpid(), getppid(), getpgrp());
}

#endif