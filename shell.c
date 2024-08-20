#include "main_header.h"

/**
  * read_command - read the command entered by user.
  * @line: ptr to the buffer where we stock the command.
  * @len: ptr to the size of the buffer.
  * Return: the number of char which are read, or -1
  * in case of issue.
  */
ssize_t read_command(char **line, size_t *len)
{
	ssize_t nread;

	printf(PROMPT);

	nread = getline(line, len, stdin);

	if (nread == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}

	if ((*line)[nread - 1] == '\n')
	{
		(*line)[nread - 1] = '\0';
	}

	return (nread);
}

/**
  * exec_command - this func executes the command entered.
  * @line: the command to execute.
  */
void exec_command(char *line)
{
	char *args[2];

	args[0] = line;
	args[1] = NULL;

	if (fork() == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror(line);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}



/**
  * main - this is the main function for simple shell.
  * The prompt will be displayed "#cisfun$"
  * So the user can enter a command like /bin/ls.
  * And the command entered will be executed.
  * Return: 0 in case of success.
  */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	while (1)
	{

		nread = read_command(&line, &len);

		if (nread == -1)
		{
			break;
		}
		if (strcmp(line, EXIT_COMMAND) == 0)
		{
			break;
		}

		exec_command(line);
	}


	free(line);
	return (0);
}