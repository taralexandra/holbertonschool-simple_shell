#include "main.h"

/**
* execute_command - Executes a command in a child process
* @name: name of prompt
* @command: The command to execute
* @line: A pointer to the line buffer (used to free memory in case of error)
* @env: The environment variables
*
* Return: void
*/

void execute_command(char *name, char *command, char **line, char **env)
{
	char *args[3], *command_copy;
	pid_t pid;
	int status;

	command_copy = strdup(command);
	if (command_copy == NULL)
	{
		perror(name);
		free(*line);
		exit(EXIT_FAILURE);
	}
	args[0] = strtok(command_copy, " ");
	args[1] = strtok(NULL, " ");
	args[2] = NULL;

	pid = fork();
	if (pid == -1)
	{
		perror(name);
		free(*line);
		free(command_copy);
		return;
	}
	else if (pid == 0)
	{
		if (execvp(args[0], args, env) == -1)
		{
			perror(name);
			free(*line);
			free(command_copy);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		free(command_copy);
	}
}
