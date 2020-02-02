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

int partition_step(int *array, int lo, int hi)
{
	int pivot = array[hi];
	int i = lo - 1, temp, j;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
	}
	temp = array[hi];
	array[hi] = array[i + 1];
	array[i + 1] = temp;
	return (i + 1);
}

void quicksort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition_step(array, lo, hi);
		print_array(array, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);
	}
}
