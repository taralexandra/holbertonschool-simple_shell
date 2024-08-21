#include "main.h"

/**
* execute_command - Executes a command in a child process
* @command: The command to execute
* @line: A pointer to the line buffer (used to free memory in case of error)
* @env: The environment variables
*
* Return: void
*/

void execute_command(char *command, char **line, char **env)
{
	char *args[2];
	pid_t pid;
	int status;

	args[0] = command;
	args[1] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return;
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, env) == -1)
		{
			perror("execve");
			free(*line);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
