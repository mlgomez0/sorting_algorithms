#include "sort.h"

/**
 *bubble_sort - sort an array using the bubble sort algorithm
 *@array:array to be sorted
 *@size:size of the array
 */

void bubble_sort(int *array, size_t size)
{
	int i, temp, k;
	int check_sort;

	k = size;
	do {
		check_sort = 0;
		for (i = 1; i < k; i++)
		{
			if (array[i - 1] > array[i])
			{
				temp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = temp;
				print_array(array, size);
				check_sort = 1;
			}
		}
	} while (check_sort);
}
