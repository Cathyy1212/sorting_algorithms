#include "sort.h"

void sw_int(int *a, int *b);
int lomuto_part(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * sw_int - Swap two integers in an array.
 * @a: The first parameter integer to swap.
 * @b: The second parameter integer to swap.
 */
void sw_int(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

/**
 * lomuto_part - Order a subset of an array of integers
 * @array: The array parameter of integers.
 * @size: The size parameter of the array.
 * @left: The index et the begenning of the subset to order.
 * @right: The index at the end of the subset to order.
 * Return: The final index of the partition
 */
int lomuto_part(int *array, size_t size, int left, int right)
{
	int *pvt, bv, blw;

	pvt = array + right;
	for (bv = blw = left; blw < right; blw++)
	{
		if (array[blw] < *pvt)
		{
			if (bv < blw)
			{
				sw_int(array + blw, array + bv);
				print_array(array, size);
			}
			bv++;
		}
	}

	if (array[bv] > *pvt)
	{
		sw_int(array + bv, pvt);
		print_array(array, size);
	}

	return (bv);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion
 * @array: An array parameter of integers to sort
 * @size: The size parameter of the array
 * @left: The index at the start of the array partition to order
 * @right: The index at the end of the array partition to order
 * Description: Uses the Lomuto partition scheme
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int prt;

	if (right - left > 0)
	{
		prt = lomuto_part(array, size, left, right);
		lomuto_sort(array, size, left, prt - 1);
		lomuto_sort(array, size, prt + 1, right);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending ordere
 * @array: An array parameter of integers
 * @size: The size parameter of the array.
 * Description: Prints the array after each swap of two elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
