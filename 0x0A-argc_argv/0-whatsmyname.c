#include <stdio.h>

/**
 * main - Entry point
 * @argc: The number of command line arguements
 * @argv: An array containing the command line arguements
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
