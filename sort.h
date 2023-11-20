#ifndef SORT_H
#define SORT_H
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/*bubble_sort */
void bubble_sort(int *array, size_t size);

/*insertion_sort */
void insertion_sort_list(listint_t **list);

/*selection_sort*/
void selection_sort(int *array, size_t size);

/*quick_sort_lomuto*/
void quick_sort(int *array, size_t size);
void quick_sort_rec(int *array, size_t size, int low, int hight);
int partition_lomuto(int *array, size_t size, int low, int hight);

/*quick_sort_hoare*/
void quick_sort_hoare(int *array, size_t size);
void quick_sort_hoare_rec(int *array, size_t size, int low, int hight);
int partition_hoare(int *array, size_t size, int low, int hight);

/*merge sort*/
void merge_sort(int *array, size_t size);
void merge_sort_rec(int *array, int left, int right);
void merge(int *array, int left, int mid, int right);

void swap(int *a, int *b);

#endif /*SORT_H*/
