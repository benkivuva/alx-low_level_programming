#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the maximum number of letters to read and print
 *
 * Return: the actual number of letters read and printed or 0 if an error.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fp, bytes_rd, bytes_wrt;
	char *buffer;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fp = open(filename, O_RDONLY);
	if (fp == -1)
	{
		free(buffer);
		return (0);
	}

	bytes_rd = read(fp, buffer, letters);
	if (bytes_rd == -1)
	{
		free(buffer);
		close(fp);
		return (0);
	}

	bytes_wrt = write(STDOUT_FILENO, buffer, bytes_rd);
	if (bytes_wrt == -1 || bytes_wrt != bytes_rd)
	{
		free(buffer);
		close(fp);
		return (0);
	}

	free(buffer);
	close(fp);

	return (bytes_wrt);
}
