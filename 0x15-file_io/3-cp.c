#include "main.h"
#include <stdio.h>

/**
 * file_for_errors - checks if files has errors which prevent opening.
 * @file_from: copy from a file.
 * @file_to: copy to a file.
 * @argv: Array of pointer to Arguments
 * Return: 0.
 */
void file_for_errors(int file_from, int file_to, char *argv[])
{
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
}

/**
 * main - Checks the code and copies contents to another file.
 * @argc: Number of arguments provided.
 * @argv: Array of pointer to Arguments .
 * Return:  0 for success.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, err_closing;
	ssize_t chars, wr;
	char buf[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to");
		exit(97);
	}

	file_from = open(argv[1], O_RDONLY);
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);
	file_for_errors(file_from, file_to, argv);

	chars = 1024;
	while (chars == 1024)
	{
		chars = read(file_from, buf, 1024);
		if (chars == -1)
			file_for_errors(-1, 0, argv);
		wr = write(file_to, buf, chars);
		if (wr == -1)
			file_for_errors(0, -1, argv);
	}

	err_closing = close(file_from);
	if (err_closing == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}

	err_closing = close(file_to);
	if (err_closing == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
		exit(100);
	}
	return (0);
}
