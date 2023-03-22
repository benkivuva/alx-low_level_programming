#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - Entry point for the calc program
 * @argc: The number of command-line arguments
 * @argv: An array of strings containing the command-line arguments
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	int num1, num2, result;
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	for (i = 0; ops[i].op != NULL; i++)
	{
		if (*ops[i].op == *argv[2] && *(argv[2] + 1) == '\0')
		{
			result = ops[i].f(num1, num2);
			printf("%d\n", result);
			return (0);
		}
	}

	printf("Error\n");
	exit(99);
}
