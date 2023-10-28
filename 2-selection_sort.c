#include "sort.h"

/**
 * sw_int - Swap two integers in an array.
 * @a: The first parameter integer
 * @b: The second parameter integer
 */
void sw_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * selection_sort - Sort an array of integers in ascending order
 * @array: An array parameter of integers
 * @size: The size parameyter of the array
 * Description: Prints the array after each swap
 */
void selection_sort(int *array, size_t size)
{
	int *a;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		a = array + i;
		for (j = i + 1; j < size; j++)
			a = (array[j] < *a) ? (array + j) : a;

		if ((array + i) != a)
		{
			sw_int(array + i, a);
			print_array(array, size);
		}
	}
}
