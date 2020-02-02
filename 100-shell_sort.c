#include "sort.h"

/**
 *shell_sort - sort an array using the shell_sort algorithm
 *@array:array to be sorted
 *@size:size of the array
 */

void shell_sort(int *array, size_t size)
{
	int i, temp, j, gap = 1;
	int n = size;

	if (array == NULL || size < 2)
		return;
	while (gap < n / 3)
	{
		gap = 3 * gap + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < n; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
