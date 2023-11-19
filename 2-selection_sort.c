#include "sort.h"
/**
 * selection_sort - this is one of the algorithm sorting methods
 * @array: this the array of integers
 * @size: it is the size of the array
 *
 * Return: Vois - No return
 */
void selection_sort(int *array, size_t size)
{
	size_t y, x, min_indx;
	int arr;

	for (x = 0; x < size - 1; x++)
	{
		min_indx = x;

		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min_indx])
			{
				min_indx = y;
				arr = array[x];
				array[x] = array[min_indx];
				array[min_indx] = arr;
				print_array(array, size);
			}
		}
	}
}
