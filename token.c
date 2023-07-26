#include "shell.h"

/**
 * _strlen - A custom implementation of string length
 * @str: A pointer to the first character of a string
 * Return: The length of the string
 */

int _strlen(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		count++;
		str++;
	}
	return (count);
}
/**
 * _strtok - A custom implementation of string token
 * @s: The pointer to the input string
 * @delim: The pointer to a null-terminated string
 * Return: Res
 */

char *_strtok(char *s, const char *delim)
{
	char *res;
	static char *last;

	if (s != NULL)
		last = s;
	else
	{
		if (last == NULL)
		{
			return (NULL);
		}
		s = last;
	}

	while (*s != '\0' && _strchr((char *)delim, *s) != NULL)
	{
		s++;
	}
	if (*s == '\0')
	{
		last = NULL;
		return (NULL);
	}
	res = s;
	while (*s != '\0' && _strchr((char *)delim, *s) == NULL)
	{
		s++;
	}
	if (*s != '\0')
	{
		*s = '\0';
		last = s + 1;
	}
	else
	{
		last = NULL;
	}
	return (res);
}


/**
 * _tok - To tokenize a given string
 * @buffer: A pointer to the input string
 * @delim: A pointer to a null-terminated string
 * Return: Result
 */

char **_tok(char *buffer, const char *delim)
{
	size_t i;
	char **result;
	char *token;
	size_t token_size;
	char **temp;

	i = 0;
	token_size = 8;
	result = malloc((token_size) * sizeof(char *));
	if (result == NULL)
	{
		perror("Memoory allocation error for result");
		exit(EXIT_FAILURE);
	}
	token = _strtok(buffer, delim);
	while (token != NULL)
	{
		if (i >= token_size)
		{
			token_size *= 2;
			temp = _realloc(result, token_size * sizeof(char *));
			if (temp == NULL)
			{
				perror("Memory allocation error for temp");
				exit(EXIT_FAILURE);
			}
			result = temp;
		}
		result[i] = _strdup(token);
		i++;
		token = _strtok(NULL, delim);
	}
	result[i] = NULL;
	if (_strcmp(result[0], "exit") == 0)
	{
		for (i = 0; result[i] != NULL; i++)
		{
			free(result[i]);
		}
		free(result);
		exit(EXIT_SUCCESS);
	}
	return (result);
}
