#include "main.h"

/**
 * append_text_to_file - Appends text to end of file
 * @filename: Name of file to append text to
 * @text_content: Text to be appended to file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fp, lenth = 0, written;

	if (!filename)
		return (-1);

	fp = open(filename, O_WRONLY | O_APPEND);
	if (fp == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[lenth])
			lenth++;

		written = write(fp, text_content, lenth);
		if (written == -1)
			return (-1);
	}

	close(fp);

	return (1);
}
