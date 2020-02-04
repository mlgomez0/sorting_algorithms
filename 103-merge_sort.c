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
	printf("support: ");
	while (i <= m && j <= hi)
	{
		if (array[i] <= array[j])
		{
			support[k] = array[i];
			i++;
			printf("%d, ", support[k]);
			k++;
		}
		else
		{
			support[k] = array[j];
			j++;
			printf("%d, ", support[k]);
			k++;
		}

	}
	printf("\n");
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
	printf("merged: \n");
	for (i = lo; i < hi; i++)
	{
		array[i] = support[i - lo];
		printf("%d, ", array[i]);
		i++;
		j++;
	}
	printf("\n");
	free(support);
}
