#include "sort.h"
/**
 * partation_hoare - the hoare partition scheme to make quick sort.
 * @array: array.
 * @size: size of array.
 * @low: low index of sequence of array will be sorted.
 * @hight: hight index of sequence of array will be sorted.
 * Return: pivot.
*/
int partation_hoare(int *array, size_t size, int low, int hight)
{
	int pivot = array[hight];
	int i = low - 1, j = hight + 1, temp;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (i - 1);

		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		print_array((const int *)array, size);
	}
}


/**
 * quick_sort_hoare_rec - sorts an array of integers in ascending order using
 * the Quick sort algorithm implemented by the Hoare partition scheme.
 * @array: array.
 * @size: size of array.
 * @low: low index of sequence of array will be sorted.
 * @hight: hight index of sequence of array will be sorted.
 * Return: void
*/
void quick_sort_hoare_rec(int *array, size_t size, int low, int hight)
{
	if (low < hight)
	{
		int pi = partation_hoare(array, size, low, hight);

		quick_sort_hoare_rec(array, size, low, pi);
		quick_sort_hoare_rec(array, size, pi + 1, hight);

	}
}


/**
 * quick_sort_hoare - call quick_sort_hoare_rec function to make sort.
 * @array: array
 * @size: size
 * Return: void
*/
void quick_sort_hoare(int *array, size_t size)
{
	quick_sort_hoare_rec(array, size, 0, size - 1);

}

