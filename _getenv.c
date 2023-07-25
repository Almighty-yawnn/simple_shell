#include "shell.h"

/**
 * _getenv - To get the environment variables
 * @var: Variable to be retrieved
 * Return: Path
 */

char *_getenv(char *var)
{
	char **env = environ;
	size_t var_len = _strlen(var);
	char *path = NULL;

	while (*env != NULL)
	{
		if (_strncmp(*env, var, var_len) == 0 && (*env)[var_len] == '=')
		{
			path = malloc(_strlen(*env) - var_len);
			if (path == NULL)
			{
				perror("Memory allocation error");
				exit(EXIT_FAILURE);
			}
			_strcpy(path, *env + var_len + 1);
			break;
		}
		env++;
	}
	return (path);
}

/**
 * _realloc - A custom realloc implementation
 * @p: A pointer to the memory block
 * @size: New size of the memory block
 * Return: New pointer to memory block
 */

void *_realloc(void *p, size_t size)
{
	void *n_ptr;
	size_t o, n, i;

	if (size == 0)
	{
		free(p);
		return (NULL);
	}
	if (p == NULL)
		return (malloc(size));
	n_ptr = malloc(size);
	if (n_ptr == NULL)
		return (NULL);
	o = malloc_usable_size(p);
	n = (o < size) ? o : size;
	for (i = 0; i < n; i++)
	{
		((char *)n_ptr)[i] = ((char *)p)[i];
	}
	free(p);
	return (n_ptr);
}

/**
 * _strncmp - A custom implementation of string compare
 * @s1: Pointer to first string to be compared
 * @s2: Pointer to second string to be compared
 * @n: number of characters to be compared
 * Return: first point - second pointer
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	while (n > 0 && *s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
	{
		return (0);
	}
	return (*s1 - *s2);
}

ssize_t _getline(char **line, size_t *n, FILE *str)
{
	size_t i, size;
	char buffer[1024], *n_line;
	ssize_t byte, j;
	
	if (!line || !n || !str)
		return (-1);
	size = *n;
	if (*line == NULL || *n == 0)
	{
		size = 1024;
		*line = malloc(size);
		if (*line == NULL)
			return (-1);
		*n = size;
	}
	i = 0;
	while ((byte = read(fileno(str), buffer, sizeof(buffer))) > 0)
	{
		for (j = 0; j < byte; j++)
		{
			if (i + 1 >= size)
			{
				size *= 2;
				n_line = _realloc(*line, size);
				if (n_line == NULL)
				{
					free(*line);
					*line = NULL;
					return (-1);
				}
				*line = n_line;
				*n = size;
				(*line)[i++] = buffer[j];
				if (buffer[j] == '\0')
				{
					(*line)[i] = '\0';
					return (i);
				}
			}
		}
	}
	if (i == 0 && byte == 0)
	{
		free(*line);
		*line = NULL;
		return (-1);
	}
	(*line)[i] = '\0';
	return (i);
}
