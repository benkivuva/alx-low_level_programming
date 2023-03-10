#include <stdio.h>
#include <string.h>

/**
 * main - Entry point
 * @argc: The number of command line arguements
 * @argv: An array containing the command line arguements
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	char *program_name = strrchr(argv[0], '/');
	(void)argc;

	if (program_name == NULL)
	{
		program_name = argv[0];
	}
	else
	{
		program_name++;
	}

	printf("%s\n", program_name);

	return (0);
}


