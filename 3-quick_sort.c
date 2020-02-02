#include "sort.h"

/**
 *quick_sort- sort an array using the Lomuto partition scheme.
 *@array:array to be sorted
 *@size:size of the array
 */

void quick_sort(int *array, size_t size)
{
	int n = size - 1;

	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, n, size);
}

/**
 *partition_step - split the list based on pivot position.
 *@array:array to be sorted
 *@lo: low index
 *@hi: higher index of the list
 *@size:size of the array
 *Return: returns the pivot right position
 */

int partition_step(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo, j;

	for (j = lo; j <= hi; j++)
	{
		if (array[j] < pivot)
		{
			swap_arr(&array[i], &array[j], array, size);
			i++;
		}
	}
	swap_arr(&array[hi], &array[i], array, size);
	return (i);
}

/**
 *quicksort - do recursive operation to partiion
 *@array:array to be sorted
 *@lo: low index
 *@hi: higher index of the list
 *@size:size of the array
 */

void quicksort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition_step(array, lo, hi, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);
	}
}

/**
 *swap_arr - swaps two array elements
 *@a: first element
 *@b: second element
 *@array:array to be sorted
 *@size:size of the array
 */

void swap_arr(int *a, int *b, int *array, size_t size)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
	print_array(array, size);
}
