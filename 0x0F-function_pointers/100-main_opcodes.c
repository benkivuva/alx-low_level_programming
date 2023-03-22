#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - prints the opcodes of the main function
 * @n_bytes: the number of bytes of opcodes to print
 */
void print_opcodes(int n_bytes);

/**
 * main - entry point of the program
 * @argc: the number of arguments passed to the program
 * @argv: an array of strings containing the arguments
 *
 * Return: 0 if successful, 1 if incorrect number of arguments, 2 if negative
 * number of bytes
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	int n_bytes = atoi(argv[1]);

	if (n_bytes < 0)
	{
		printf("Error\n");
		return (2);
	}

	print_opcodes(n_bytes);

	return (0);
}

/**
 * print_opcodes - prints the opcodes of the main function
 * @n_bytes: the number of bytes of opcodes to print
 */
void print_opcodes(int n_bytes)
{
	void (*main_ptr)(void) = (void (*)(void))&main;
	int i;

	for (i = 0; i < n_bytes; i++)
	{
		printf("%02x ", *((unsigned char *)main_ptr + i));
	}

	printf("\n");
}
