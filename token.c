#include "shell.h"

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

char **_tok(char *buffer, const char* delim)
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

	token = strtok(buffer, delim);
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
		token = strtok(NULL, delim);

	}
	result[i] = NULL;
	if (_strcmp(result[0], "exit") == 0)
	{
		free(result);
		exit(EXIT_SUCCESS);
	}
        return (result);
}
