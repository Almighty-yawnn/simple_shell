#include <stdio.h>
#include <stdlib.h>

/**
 * main - main function
 * Return: 0 or failure
 */

int main(void)
{
	size_t n;
	ssize_t line;
	char *buffer = NULL;

	n = 1024;
	printf("$");

	buffer = malloc(n);
	if (buffer == NULL)
	{
		free(buffer);
		return (0);
	}

	line = 0;
	line = getline(&buffer, &n, stdin);
	if (line == -1)
	{
		exit(EXIT_FAILURE);
	}
 
	free(buffer);
	return (0);
}
