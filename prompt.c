#include "shell.h"

/**
 * main - To check the code
 * @argc: argument count
 * @argv: argument vector
 * Return: 0
 */

int main(int argc, char **argv)
{
	char *prompt, *program;

	program = argv[0];
	UNUSED_VAR(argc);
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		prompt = "Cisfun$ ";
	}
	run(prompt, program);
	return (0);
}
