#include "main.h"

/**
 * _atoi - converts a string to an integer.
 * @s: string to be converted.
 *
 * Return: integer value of the string.
 */
int _atoi(char *s)
{
	int sign = 1;
	int num = 0;
	int i = 0;

	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}

	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] - '0');

			/* Check for overflow */
			if ((num > 0 && num < INT_MIN / 10) ||
				(num < 0 && num > INT_MAX / 10))
			{
				return (0);
			}
		}
		else if (num != 0)
		{
			break;
		}

		i++;
	}

	return (num * sign);
}
