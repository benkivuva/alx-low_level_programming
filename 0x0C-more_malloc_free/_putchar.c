#include <unistd.h>

/**
 * _putchar - Writes a single character to stdout
 * @c: The character to write
 *
 * Return: 1 on success, -1 on failure
 */
int _putchar(char c)
{
  return (write(1, &c, 1) == 1 ? 1 : -1);
}

