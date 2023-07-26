#include "shell.h"

/**
 * _getenv - To get the environment variables
 * @var: Variable to be retrieved
 * Return: Path
 */

char *_getenv(char *var)
{
	char **env = environ;
	size_t i, var_len;
	char *path;

	if (var == NULL || *var == '\0')
		return (NULL);
	while (*env != NULL)
	{
		var_len = _strlen(var);
		path = *env;
		i = 0;
		while(i < var_len && var[i] == path[i])
		{
			i++;
		}
		if (i == var_len && path[i] == '=')
		{
			return (path + i + 1);
		}
		env++;
	}
	return (NULL);
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

/**
 * _getline - A custom implementation of getline function
 * @line: A pointer to a pointer to store address of buffer
 * @n: A pointer to the size of the buffer
 * @str: The file to b read
 * Return: i
 */

ssize_t _getline(char **line, size_t *n, FILE *str)
{
	size_t i, size;
	static char buffer[1024];
	char *n_line;
	ssize_t byte;
	static ssize_t j;

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
			}
			(*line)[i++] = buffer[j];
			if (buffer[j] == '\n')
			{
				(*line)[i] = '\0';
				return (i);
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
