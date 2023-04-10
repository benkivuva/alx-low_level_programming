#include <stddef.h>
#include "main.h"

/**
 * create_file - creates a file with the given name and writes the
 *
 * @filename: the name of the file to create
 * @text_content: the content to be writen to the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fp, result, len = 0;

	if (filename == NULL)
		return (-1);

	fp = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fp == -1)
		return (-1);

	if (text_content != NULL)
	{
		while (text_content[len])
			len++;

		result = write(fp, text_content, len);
		if (result == -1)
		{
			close(fp);
			return (-1);
		}
	}

	close(fp);
	return (1);
}
