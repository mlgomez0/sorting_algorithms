#ifndef SORT_H
#define SORT_H
#include <stdio.h>
#include <stdlib.h>

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
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void insert_top(listint_t *sort, listint_t *prog);
void insert_end(listint_t *sort, listint_t *prog);
void insert_middle(listint_t *sort, listint_t *prog);
void insert_uniq(listint_t *sort, listint_t *prog, listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition_step(int *array, int lo, int hi, size_t size);
void quicksort(int *array, int lo, int hi, size_t size);
void swap_arr(int *a, int *b, int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void mergesort(int *array, int lo, int hi);
void merge_arrays(int *array, int lo, int m, int hi);
void print_merge(int *array, int lo, int m, int hi, int flag);
void r_c(listint_t *prog, listint_t **list, listint_t **tail, int *check_s);
void l_c(listint_t *progt, listint_t **list, listint_t **tail, int *check_s);
void insert_all(listint_t **list, listint_t *sort, listint_t *prog, int ind);

#endif
