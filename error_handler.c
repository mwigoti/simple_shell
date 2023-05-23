#include "main.h"

/**
 * print_error - Entry point
 * @cmd: first argument
 * @msg: error message
 * @line_num: to track error
 * Return: Always 0 (Success)
 */
void print_error(const char *cmd, const char *msg, int line_num)
{
	const char *shell_name = "hsh";
	const char *separator = ": ";
	char line_number_str[16];
	unsigned long int i = 0;
	int j, n = line_num;
	size_t shell_name_len = strlen(shell_name);
	size_t separator_len = strlen(separator);

	write(STDERR_FILENO, shell_name, shell_name_len);
	write(STDERR_FILENO, separator, separator_len);

	if (n == 0)
	{
		line_number_str[i++] = '0';
	}
	else
	{
		while (n > 0 && i < sizeof(line_number_str) - 1)
		{
			line_number_str[i++] = '0' + (n % 10);
			n /= 10;
		}
	}
	for (j = i - 1; j >= 0; j--)
	{
		write(STDERR_FILENO, &line_number_str[j], 1);
	}

	write(STDERR_FILENO, separator, separator_len);
	write(STDERR_FILENO, cmd, strlen(cmd));
	write(STDERR_FILENO, separator, separator_len);
	write(STDERR_FILENO, msg, strlen(msg));
	write(STDERR_FILENO, "\n", 1);
}