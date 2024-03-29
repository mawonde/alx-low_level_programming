#include "main.h"

/**
 * create_file - Creates  File
 * @filename: Name of File to create.
 * @text_content: Content written  in File.
 *
 * Return: 1 if  successful. -1 if failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	int letters;
	int wr;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	if (fd == -1)
		return (-1);

	if (!text_content)
		text_content = "";

	for (letters = 0; text_content[letters]; letters++)
		;

	wr = write(fd, text_content, letters);

	if (wr == -1)
		return (-1);

	close(fd);

	return (1);
}
