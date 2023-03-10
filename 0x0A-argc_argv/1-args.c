#include <stdio.h>

/**
 * main - Entry point
 *
 * @argc: the number of command line arguments
 * @argv: an array containing the arguements
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	(void)argv;
	printf("%d\n", argc - 1);

	return (0);
}
