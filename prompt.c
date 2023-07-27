#include "shell.h"

int main(int argc, char **argv)
{
	char *prompt, *program;

	program = argv[0];
	UNUSED_VAR(argc);
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
	{
		prompt = "c$";
	}
	run(prompt, program);
	return (0);
}
