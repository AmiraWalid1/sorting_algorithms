#include "sort.h"

/**
 * max_element - this is the maximum value in the array
 * @array: this the array of integers
 * @size: it is the size of the array
 * Return: the max value
 */

int max_element(int *array, size_t size)
{
	size_t x;
	int max_elem = 0;

	x = 0;
	while (x < size)
	{
		if (max_elem < array[x])
		{
			max_elem = array[x];
		}
		x++;
	}
	return (max_elem);
}

/**
 * counting_sort - this is one of the algorithm sorting methods
 * @array: this the array of integers
 * @size: it is the size of the array
 * Return: Void - No return
 */

void counting_sort(int *array, size_t size)
{
	int y, max_elem;
	int *c_array, *out_array;

	if (size <= 1)
		return;
	max_elem = 0;
	max_elem = max_element(array, size);
	c_array = malloc(sizeof(int) * (max_elem + 1));
	if (c_array == NULL)
		return;
	for (y = 0; y <= max_elem; y++)
		c_array[y] = 0;
	for (y = 0; y < size; y++)
	{
		int num = array[y];

		c_array[num] = c_array[num] + 1;
	}
	for (y = 0; y < max_elem; y++)
	{
		c_array[y] = c_array[y] + c_array[y - 1];
	}
	print_array(c_array, max_elem + 1);

	out_array = malloc(sizeof(int) * size);
	if (out_array == NULL)
	{
		free(out_array);
		return;
	}
	for (y = 0; y < size; y++)
		out_array[--c_array[array[y]]] = array[y];
	for (y = 0; y < size; y++)
		array[y] = out_array[y];

	free(c_array);
	free(out_array);
}
