/**
 * reverse_array - reverses the content of an array of integers
 * @a: pointer to an array of integers
 * @n: number of elements in the array
 */
void reverse_array(int *a, int n)
{
	int temp;
	int i;

	for (i = 0; i < n / 2; i++)
	{
		/* Swap the elements at position i and n - i - 1 */
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}
}
