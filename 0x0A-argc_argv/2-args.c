#include <stdio.h>

/**
 * main - Entry point
 * @argc: The number of command line arguements
 * @argv: ana array containing the arguements
 * Return: Always (0)
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
