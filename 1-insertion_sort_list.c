#include "sort.h"

/**
 *insertion_sort_list - sort an doubly linked list, insertion method.
 *@list:Doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *sort, *prog;
	int end_list = 0;

	prog = (*list)->next;
	while (prog)
	{
		sort = prog->prev;
		temp = prog->next;
		if (temp == NULL)
			end_list = 1;
		if (sort->n > prog->n)
		{
			while(sort)
			{
				if (sort->n > prog->n)
				{
					if (sort->prev == NULL)
					{
						sort->next = prog->next;
						prog->next->prev = sort;
						prog->next = sort;
						sort->prev = prog;
						prog->prev = NULL;
						*list = prog;
						print_list(*list);
					}
					else if (end_list == 1)
					{
						sort->prev->next = prog;
						prog->prev = sort->prev;
						prog->next = sort;
						sort->prev = prog;
						sort->next = NULL;
						end_list = 0;
						print_list(*list);
					}
					else
					{
						sort->next = prog->next;
						prog->next->prev = sort;
						sort->prev->next = prog;
						prog->next = sort;
						prog->prev = sort->prev;
						sort->prev = prog;
						print_list(*list);
					}
				}
				sort = sort->prev;
			}
		}
		prog = temp;
	}
}
