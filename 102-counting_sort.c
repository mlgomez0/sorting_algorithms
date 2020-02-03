#include "sort.h"

/**
 *counting_sort- sort an array using the counting sort algorithm
 *@array:array to be sorted
 *@size:size of the array
 */

void counting_sort(int *array, size_t size)
{
	int i = 0, sort_ind = 0, max_num = array[0], k = size, *count_ele, *temp_array;

	if (array == NULL || size < 2)
		return;
	while (array[i])
	{
		if (array[i] > max_num)
			max_num = array[i];
		i++;
		if (array[i] < array[i - 1])
			sort_ind = 1;
	}
	if (sort_ind == 0)
		return;
	count_ele = (int *) malloc(sizeof(int) * max_num++);
	if (count_ele == NULL)
		return;
	temp_array = (int *) malloc(sizeof(int) * k);
	if (temp_array == NULL)
		return;
	for (i = 0; i <= max_num; i++)
	{
		count_ele[i] = 0;
	}
	for (i = 0; i < k; i++)
	{
		count_ele[array[i]]++;
	}
	for (i = 1; i <= max_num; i++)
	{
		count_ele[i] = count_ele[i] + count_ele[i - 1];
	}
	print_array(count_ele, max_num);
	for (i = k - 1; i >= 0; i--)
	{
		temp_array[count_ele[array[i]] - 1] = array[i];
		count_ele[array[i]]--;
	}
	for (i = 0; i < k; ++i)
	{
		array[i] = temp_array[i];
	}
	free(count_ele);
	free(temp_array);
}
