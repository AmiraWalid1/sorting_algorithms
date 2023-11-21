#include "sort.h"
#include <stdlib.h>
/**
 * merge - merge to subarrays.
 * @array: array.
 * @temp_arr: temporary array
 * @left: left index.
 * @mid: mid index.
 * @right: right index.
 * return: void
*/
void merge(int *array, int *temp_arr, int left, int mid, int right)
{
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, (mid - left + 1));
	printf("[right]: ");
	print_array(array + (mid + 1), (right - mid));

	for (i  = left; i <= right; i++)
	{
		temp_arr[i] = array[i];
	}

	i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right)
	{
		if (temp_arr[i] < temp_arr[j])
			array[k++] = temp_arr[i++];
		else
			array[k++] = temp_arr[j++];
	}
	while (i <= mid)
		array[k++] = temp_arr[i++];

	while (j <= right)
		array[k++] = temp_arr[j++];

	printf("[Done]: ");
	print_array(array + left, (right - left + 1));
}
/**
 * merge_sort_rec - function that sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: array.
 * @temp_arr: temporary array
 * @left: left index.
 * @right: right index.
 * return: void
*/
void merge_sort_rec(int *array, int *temp_arr, int left, int right)
{
	int mid;

	if (left >= right)
		return;
	mid = ((left + right) / 2) + ((left + right) % 2) - 1;
	merge_sort_rec(array, temp_arr, left, mid);
	merge_sort_rec(array, temp_arr, mid + 1, right);
	merge(array, temp_arr, left, mid, right);

}
/**
 * merge_sort - function that call merge_sort_rec to sort array using
 * merge sort algorithm.
 * @array: array.
 * @size: size of array.
 * Return: void
*/
void merge_sort(int *array, size_t size)
{
	int *temp_arr = malloc(size * sizeof(int));

	merge_sort_rec(array, temp_arr, 0, size - 1);
	free(temp_arr);
}
