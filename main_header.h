#ifndef MAIN_HEADER_H
#define MAIN_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/**
  * define PROMPT - here, we define the constant prompt that will
  * be displayed when we execute the program
  * and before to enter a command.
  */

#define PROMPT "#cisfun$ "

/**
  * define EXIT_COMMAND - this command "exit" allow to quit the program.
  */

#define EXIT_COMMAND "exit"


ssize_t read_command(char **line, size_t *len);
void exec_command(char *line);
void handle_signal(int sig);

#endif
