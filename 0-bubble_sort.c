#include "sort.h"

/**
 * bubble_sort - it is one of the algorithm sorting methods
 * @size: it is the size of the array
 * @array: this is the array of integers
 * Return: Void - No return
 */

void bubble_sort(int *array, size_t size)
{
	size_t x, y;
	int arr;

	for (x = 0; x < size - 1; x++)
	{
		for (y = 0; y < size - x - 1; y++)
		{
			if (array[y] > array[y + 1])
			{
				arr = array[y];
				array[y] = array[y + 1];
				array[y + 1] = arr;
				print_array(array, size);
			}
		}
	}
}
