#include "sort.h"

/**
 *merge_sort- sort an array using the top-down merge algorithm.
 *@array:array to be sorted
 *@size:size of the array
 */

void merge_sort(int *array, size_t size)
{
	int n = size - 1;
	int i;
	int *receive;

	if (array == NULL || size < 2)
		return;
	receive = mergesort(array, 0, n);
	for (i = 0; i < (n + 1); i++)
	{
		array[i] = receive[i];
	}
}

/**
 *quicksort - do recursive operation to partiion
 *@array:array to be sorted
 *@lo: low index
 *@hi: higher index of the list
 *@size:size of the array
 */

int *mergesort(int *array, int lo, int hi)
{
	int m;

	if (lo > hi)
		return array;


	m = (lo + hi)/ 2;
	mergesort(array, lo, m);
	mergesort(array, m + 1, hi);
	return (merge(array, lo, m, hi));
}

/**
 *swap_arr - swaps two array elements
 *@a: first element
 *@b: second element
 *@array:array to be sorted
 *@size:size of the array
 */

int *merge(int *array, int lo, int m, int hi)
{
	int *receive;
	int i = 0;


	printf("Merging...\n");
	receive = malloc(sizeof(int) * (hi + 1));
	for (i = lo; i < hi; i++)
	{
		if (array[i] < array[i + m])
		{
			receive[i] = array[i];
		}
		else
		{
			receive[i] = array[i + m];
		}
		i++;
	}
	return (receive);
}
