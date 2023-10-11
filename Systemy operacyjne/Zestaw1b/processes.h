#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#ifndef FUNKCJA
#define FUNKCJA
#define PATH "./"
#define PATHNAME_MAX 4096
#define FILENAME_MAX 4096

void processes()
{
    printf("UID: %d, GID: %d, PID: %d, PPID: %d, PGID: %d\n", getuid(), getgid(), getpid(), getppid(), getpgrp());
}

#endif