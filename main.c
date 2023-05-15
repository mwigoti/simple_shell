#include "main.h"

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: Always 0 (Success)
 */
int main(int argc, char **argv)
{
	char *shellPrompt = "#cisfun$ ";
	size_t n = 0;

	for (; ;)
	{
		printf("%s", shellPrompt);
		if ((get_line(argv, &n, stdin)) == -1)
		{
			feof(stdin) ? exit(EXIT_SUCCESS) : exit(EXIT_FAILURE);
		}
		if (strcmp(argv[0], "exit") == 0)
		{
			free(*argv);
			exit(EXIT_SUCCESS);
		}
		if (strcmp(argv[0], "env") == 0)
		{
			my_env();
		}
		execute(*argv);
	}

	free(argv);

	return (0);
}
