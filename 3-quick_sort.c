#include "sort.h"

/**
 *quick_sort- sort an array using the Lomuto partition scheme.
 *@array:array to be sorted
 *@size:size of the array
 */

void quick_sort(int *array, size_t size)
{
	int n = size - 1;

	quicksort(array, 0, n, size);
}

int partition_step(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo, temp, j;

	for (j = lo; j <= hi; j++)
	{
		if (array[j] < pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
			i++;
		}
	}
	temp = array[hi];
	array[hi] = array[i];
	array[i] = temp;
	print_array(array, size);
	return (i);
}

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
