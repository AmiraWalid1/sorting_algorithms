#include "sort.h"
#include <stdlib.h>
/**
 * merge - merge to subarrays.
 * @array: array.
 * @left: left index.
 * @mid: mid index.
 * @right: right index.
 * return: void
*/
void merge(int *array, int left, int mid, int right)
{
	int arrL_sz = (mid - left + 1), arrR_sz = (right - mid);
	int *temp_arr = malloc((arrL_sz + arrR_sz) * sizeof(int));
	int i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	for (i  = 0; i < arrL_sz ; i++)
	{
		temp_arr[i] = array[left + i];
		printf("%d%s", temp_arr[i], i == arrL_sz - 1 ? "\n" : ", ");
	}
	printf("[right]: ");
	for (j = arrL_sz; j < arrL_sz + arrR_sz; j++)
	{
		temp_arr[j] = array[left + j];
		printf("%d%s", temp_arr[j], j == arrL_sz + arrR_sz - 1 ? "\n" : ", ");
	}
	i = 0, j = arrL_sz, k = left;
	printf("[Done]: ");
	while (i < arrL_sz && j < arrR_sz + arrL_sz)
	{
		if (temp_arr[i] < temp_arr[j])
			array[k] = temp_arr[i++];
		else
			array[k] = temp_arr[j++];
		printf("%s%d", k != left ? ", " : "", array[k]);
		k++;
	}
	while (i < arrL_sz)
	{
		printf(", %d", array[i]);
		array[k++] = temp_arr[i++];
	}
	while (j < arrR_sz + arrL_sz)
	{
		printf(", %d", array[j]);
		array[k++] = temp_arr[j++];
	}
	printf("\n");
	free(temp_arr);
}
/**
 * merge_sort_rec - function that sorts an array of integers in ascending order
 * using the Merge sort algorithm.
 * @array: array.
 * @left: left index.
 * @right: right index.
 * return: void
*/
void merge_sort_rec(int *array, int left, int right)
{
	int mid;

	if (left >= right)
		return;
	mid = ((left + right) / 2) + ((left + right) % 2) - 1;
	merge_sort_rec(array, left, mid);
	merge_sort_rec(array, mid + 1, right);
	merge(array, left, mid, right);

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
	merge_sort_rec(array, 0, size - 1);
}
