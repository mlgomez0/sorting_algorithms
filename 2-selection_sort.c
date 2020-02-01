#include "sort.h"

/**
 *selection_sort- sort an array using the election sort algorithm
 *@array:array to be sorted
 *@size:size of the array
 */

void selection_sort(int *array, size_t size)
{
	int i, j, temp, k, min, position, flag = 0;

	k = size;
	if (array == NULL || size < 2)
		return;
	for (i = 0; i < k - 1; i++)
	{
		min = array[i];
		for (j = i + 1; j < k; j++)
		{
			if (min > array[j])
			{
				flag = 1;
				min = array[j];
				position = j;
			}
		}
		if (flag == 1)
		{
			temp = array[i];
			array[i] = array[position];
			array[position] = temp;
			print_array(array, size);
			flag = 0;
		}
	}
}
