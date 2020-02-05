#include "sort.h"

/**
 *merge_sort- sort an array using the top-down merge algorithm.
 *@array:array to be sorted
 *@size:size of the array
 */

void merge_sort(int *array, size_t size)
{
	int n = size - 1;

	if (array == NULL || size < 2)
		return;
	mergesort(array, 0, n);
}

/**
 *mergesort - do recursive operation to partition
 *@array:array to be sorted
 *@lo: low index
 *@hi: higher index of array
 */

void mergesort(int *array, int lo, int hi)
{
	int m;


	if (lo <  hi)
	{
		m = (lo + hi) / 2;
		mergesort(array, lo, m);
		mergesort(array, m + 1, hi);
		merge_arrays(array, lo, m, hi);
	}
}

/**
 *merge_arrays - merge two arrays
 *@array: array to be sorted
 *@lo: low index
 *@m: middle position to partition
 *@hi:higher indext
 */

void merge_arrays(int *array, int lo, int m, int hi)
{
	int i = lo, j, k = 0, n;
	int *support;

	n = hi - lo + 1;
	j = m + 1;
	support = malloc(n * sizeof(int));
	if (support == NULL)
		return;
	print_merge(array, lo, m, hi, 0);
	while (i <= m && j <= hi)
	{
		if (array[i] <= array[j])
		{
			support[k] = array[i];
			i++;
		}
		else
		{
			support[k] = array[j];
			j++;
		}
		k = k + 1;
	}
	while (i <= m)
	{
		support[k] = array[i];
		k++;
		i++;
	}
	while (j <= hi)
	{
		support[k] = array[j];
		k++;
		j++;
	}
	print_merge(array, lo, m, hi, 1);
	for (i = lo; i <= hi; i++)
	{
		array[i] = support[i - lo];
	}
	free(support);
}

void print_merge(int *array, int lo, int m, int hi, int flag)
{
	int i;

	if (flag == 0)
	{
		printf("Merging...\n");
		printf("[left]: ");
		for (i = lo; i <= m; i++)
		{
			if (i != m)
				printf("%d, ", array[i]);
			else
				printf("%d\n", array[i]);
		}
		printf("[right]: ");
		for (i = m + 1; i <= hi; i++)
		{
			if (i != hi)
				printf("%d, ", array[i]);
			else
				printf("%d\n", array[i]);
		}
	}
	else
	{
		printf("[Done]: ");
		for (i = lo; i <= hi; i++)
		{
			if (i != hi)
				printf("%d, ", array[i]);
			else
				printf("%d\n", array[i]);
		}
	}
}
