#include "shell.h"

int _env(void)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

int _builtin(char **tokens)
{
	built_cmd actions[] = {{"env", _env}, {NULL, NULL}};
	int i;

	for (i = 0; actions[i].cmd; i++)
	{
		if (_strcmp(actions[i].cmd, tokens[0]) == 0)
		{
			return (actions[i].act());
		}
	}
	return (-1);
}
