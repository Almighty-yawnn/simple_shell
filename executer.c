#include "shell.h"

/**
 * _exec - To execute specified command
 * @pathfinder: The path to the executable file of command to be executed
 * @token: Array of strings
 * Return: Nothing
 */

void _exec(char *pathfinder, char **token)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(pathfinder, token, NULL) == -1)
		{
			perror(token[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
