#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: The number of command line arguments
 * @argv: An array containing the command line arguments
 *
 * Return: 0 for success, 1 for error
 */
int main(int argc, char **argv)
{
	int cents, coins;

	/* Check for correct number of arguments */
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	/* Convert argument to integer */
	cents = atoi(argv[1]);

	/* Check for negative input */
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	/* Calculate the number of coins needed */
	coins = cents / 25;
	cents %= 25;

	coins += cents / 10;
	cents %= 10;

	coins += cents / 5;
	cents %= 5;

	coins += cents / 2;
	cents %= 2;

	coins += cents;

	/* Print the result */
	printf("%d\n", coins);

	return (0);
}
