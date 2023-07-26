#include "shell.h"

/**
 * path_checker - Used to check full path of a command
 * @token: Array of strings
 * Return: Full path
 */

char *path_checker(char **token)
{
	char *full_path, *get_path;
	char *tok_path;
	int i;

	get_path = _strdup(_getenv("PATH"));
	tok_path = _strtok(get_path, ":");
	full_path = NULL;

	for (i = 0; tok_path != NULL; i++)
	{
		full_path = malloc(_strlen(tok_path) + _strlen(token[0]) + 2);
		if (full_path == NULL)
		{
			perror("Memory allocation error for full path");
			exit(EXIT_FAILURE);
		}
		_strcpy(full_path, tok_path);
		_strcat(full_path, "/");
		_strcat(full_path, token[0]);
		if (access(full_path, X_OK) == 0)
		{
			free(get_path);
			return (full_path);
		}
		free(full_path);
		tok_path = _strtok(NULL, ":");
	}
	free(get_path);
	return (NULL);
}

/**
 * command_path - To determine the full path of a command
 * @token: Array of strings
 * Return: NULL
 */

char *command_path(char **token)
{
	char *com_path = NULL;

	if (_strchr(token[0], '/') != NULL)
	{
		if (access(token[0], X_OK) == 0)
		{
			com_path = _strdup(token[0]);
		}
	}
	else
	{
		com_path = path_checker(token);
	}
	if (com_path == NULL)
	{
		return (NULL);
	}
	return (com_path);
}
