#include <stddef.h>

/**
 * print_name - A function that prints a name
 *
 * @name: Pointer to the name to be printed
 * @f: function pointer to function that takes a character pointer as argument
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name != NULL && f != NULL)
	{
		f(name);
	}
}
