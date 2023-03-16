#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * is_digit - checks if a string is a digit
 * @str: the string to check
 *
 * Return: 1 if the string is a digit, 0 otherwise
 */
int is_digit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * print_error - prints an error message and exits with status 98
 */
void print_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * multiply - multiplies two strings containing numbers
 * @num1: the first number as a string
 * @num2: the second number as a string
 *
 * Return: the product of num1 and num2 as a string
 */
char *multiply(char *num1, char *num2)
{
	char *result;
	int len1, len2, i, j, n1, n2, carry, sum;

	len1 = strlen(num1);
	len2 = strlen(num2);
	result = calloc(len1 + len2 + 1, sizeof(char));
	if (!result)
		return (NULL);

	for (i = len1 - 1; i >= 0; i--)
	{
		if (!is_digit(&num1[i]))
			print_error();
		n1 = num1[i] - '0';
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			if (!is_digit(&num2[j]))
				print_error();
			n2 = num2[j] - '0';
			sum = n1 * n2 + result[i + j + 1] + carry;
			result[i + j + 1] = sum % 10;
			carry = sum / 10;
		}
		result[i + j + 1] = carry;
	}
	i = 0;
	while (result[i] == 0)
		i++;
	if (i == len1 + len2)
		i--;
	for (j = i; j < len1 + len2; j++)
		result[j] += '0';

	return (result + i);
}

/**
 * main - multiplies two positive numbers
 * @argc: the number of arguments
 * @argv: the array of arguments
 *
 * Return: 0 if successful, 98 otherwise
 */
int main(int argc, char **argv)
{
	char *num1, *num2, *result;

	if (argc != 3)
	{
		print_error();
	}
	num1 = argv[1];
	num2 = argv[2];
	if (!is_digit(num1) || !is_digit(num2))
	{
		print_error();
	}
	result = multiply(num1, num2);
	printf("%s\n", result);
	free(result);
	return (0);
}
