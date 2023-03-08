/**
 * is_prime_helper - helper function for is_prime_number
 * @n: the number to check for primality
 * @divisor: the current divisor being checked
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_helper(int n, int divisor)
{
	if (n < 2)
		return (0);
	if (divisor == n)
		return (1);
	if (n % divisor == 0)
		return (0);
	return (is_prime_helper(n, divisor + 1));
}

/**
 * is_prime_number - checks if a number is prime
 * @n: the number to check for primality
 * Return: 1 if n is prime, 0 otherwise
 */
int is_prime_number(int n)
{
	return (is_prime_helper(n, 2));
}
