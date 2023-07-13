#include <stdio.h>
#include <stdlib.h>

/**
 * main - main function
 * Return: 0 or failure
 */

int main(void)
{
	ssize_t n, line;
	char *buffer = NULL;

	printf("$");

	buffer = malloc(n);
	if (buffer == NULL)
	{
		free(buffer);
		return (0);
	}

	line = getline(&buffer, &n, stdin);
	if (line == -1)
	{
		free(buffer);
		printf("error");
	}
	printf("%s %ld\n", buffer, line);
	free(buffer);
	return (0);
}
