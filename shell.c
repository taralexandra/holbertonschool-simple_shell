#include "main.h"

/**
* main - Simple Shell, reads input from user, and executes input as command,
* stops if the user types exit, or when an error occurs while reading input
* @argc: Argument count
* @argv: Argument vector
* @env: Environment variables
*
* Return: Always 0
*/

int main(int argc, char *argv[], char *env[])
{

	size_t len = 0;
	ssize_t nread;
	char *line = NULL;
	(void)argc;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("($) ");

		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		if (line[0] == '\0' || _strspn(line, " \t") == strlen(line))
			continue;

		if (strcmp(line, "exit") == 0)
		{
			free(line);
			line = NULL;
			exit(2);
		}

		if (line[0])
			execute_command(argv[0], line, &line, env);
	}

	free(line);
	return (0);
}
