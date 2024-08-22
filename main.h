#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char *argv[], char *env[]);
void execute_command(char *name, char *command, char **line, char **env);
unsigned int _strspn(char *s, char *accept);

#endif
