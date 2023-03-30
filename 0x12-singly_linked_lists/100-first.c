#include <stdio.h>

/**
 * pre_main - prints a message before main is executed
 */
void pre_main(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}

/**
 * main - entry point for the program
 *
 * Return: Always 0
 */
int main(void)
{
	pre_main();

	return (0);
}
