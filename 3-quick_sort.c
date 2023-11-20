#include "sort.h"
/**
 * partition_lomuto - the Lomuto partition scheme to make quick sort.
 * @array: array.
 * @size: size of array.
 * @low: low index of sequence of array will be sorted.
 * @hight: hight index of sequence of array will be sorted.
 * Return: index of pivot.
*/
int partition_lomuto(int *array, size_t size, int low, int hight)
{
	int pivot = array[hight];
	int i = low - 1, j;

	for (j = low ; j <= hight ; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(array + i, array + j);
				print_array((const int *)array, size);
			}
		}
	}
	return (i);

}


/**
 * quick_sort_rec - function that sorts an array of integers in ascending order
 * using the Quick sort algorithm implemented by the lomuto partition scheme.
 * @array: array.
 * @size: size of array.
 * @low: low index of sequence of array will be sorted.
 * @hight: hight index of sequence of array will be sorted.
 * Return: void
*/
void quick_sort_rec(int *array, size_t size, int low, int hight)
{
	if (low < hight)
	{
		int pivot = partition_lomuto(array, size, low, hight);

		quick_sort_rec(array, size, low, pivot - 1);
		quick_sort_rec(array, size, pivot + 1, hight);
	}
}


/**
 * quick_sort - function call quick_sort_rec.
 * @array: array
 * @size: size of array
 * Return: void
*/
void quick_sort(int *array, size_t size)
{
	quick_sort_rec(array, size, 0, size - 1);
}


/**
 * swap - swap the value pointed by  two pointer
 * @a: first pointer
 * @b: second pointer
 * Return: void
*/
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
