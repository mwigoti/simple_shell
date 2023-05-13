#ifndef MAIN_H
#define MAIN_H
#define _POSIX_C_SOURCE 200809L

/* standard library functions */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;
pid_t execute(char *command);


#endif /* MAIN_H */