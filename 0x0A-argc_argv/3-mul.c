#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: The number of the command line arguements
 * @argv: An array containing the arguements
 *
 * Return: 0 if success, 1 if it fails
 */
int main(int argc, char *argv[])
{
	int num1, num2, product;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	product = num1 * num2;

	printf("%d\n", product);

	return (0);
}
