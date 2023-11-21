#include "sort.h"

/**
 * shell_sort - this is one of the algorithm sorting methods
 * @array: this the array of integers
 * @size: it is the size of the array
 * Return - void (no return)
 */

void shell_sort(int *array, size_t size)
{
	size_t x, y, gab;
	int arr; /*variable for swap*/

	if (array == NULL || size < 2)
		return;

	gab = 1;

	while (gab <= size / 3)
		gab = gab * 3 + 1;

	while (gab > 0)
	{
		for (y = gab; y < size; y++)
		{
			arr = array[y];
			x = y;
			while (x > gab - 1 && array[x - gab] >= arr)
			{
				array[x] = array[x - gab];
				x = x - gab;
			}
			array[x] = arr;
		}
		gab = (gab - 1) / 3;
		print_array(array, size);
	}
}
