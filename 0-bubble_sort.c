#include "sort.h"

/**
 * sw_int - Swap two integers in an array.
 * @a: The first parameter
 * @b: The second parameter
 */
void sw_int(int *a, int *b)
{
        int c;

        c = *a;
        *a = *b;
        *b = c;
}

/**
 * bubble_sort - Sort an array of integers in ascending order
 * @array: the parameter array
 * @size: The parameter size of the array
 * Description: the function prints the sorted array
 */
void bubble_sort(int *array, size_t size)
{
        size_t i, lenght = size;
        bool b = false;

        if (array == NULL || size < 2)
                return;

        while (b == false)
        {
                b = true;
                for (i = 0; i < lenght - 1; i++)
                {
                        if (array[i] > array[i + 1])
                        {
                                sw_int(array + i, array + i + 1);
                                print_array(array, size);
                                b = false;
                        }
                }
                lenght--;
        }
}
