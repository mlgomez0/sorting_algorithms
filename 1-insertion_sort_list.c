#include "sort.h"

/**
 *insertion_sort_list - sort an doubly linked list, insertion method.
 *@list:Doubly linked list to be sorted
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *sort, *prog;
	int end_list = 0;

	if (list == NULL || *list == NULL)
		return;
	prog = (*list)->next;
	while (prog)
	{
		sort = prog->prev;
		temp = prog->next;
		if (temp == NULL)
			end_list = 1;
		if (sort->n > prog->n)
		{
			while (sort)
			{
				if (sort->n > prog->n)
				{
					if (sort->prev == NULL && prog->next == NULL)
					{
						insert_uniq(sort, prog);
						*list = prog;
					}
					else if (sort->prev == NULL)
					{
						insert_top(sort, prog);
						*list = prog;
					}
					else if (end_list == 1)
					{
						insert_end(sort, prog);
						end_list = 0;
					}
					else
						insert_middle(sort, prog);
					print_list(*list);
				}
				sort = sort->prev;
			}
		}
		prog = temp;
	}
}

/**
 *insert_top - insert a node at the top of doubly linked list.
 *@sort:pointer to a node of doubly linked list.
 *@prog:pointer to a node of doubly linked list.
 */

void insert_top(listint_t *sort, listint_t *prog)
{
	sort->next = prog->next;
	prog->next->prev = sort;
	prog->next = sort;
	sort->prev = prog;
	prog->prev = NULL;
}

/**
 *insert_end - insert a node at the end  of doubly linked list.
 *@sort:pointer to a node of doubly linked list.
 *@prog:pointer to a node of doubly linked list.
 */

void insert_end(listint_t *sort, listint_t *prog)
{
	sort->prev->next = prog;
	prog->prev = sort->prev;
	prog->next = sort;
	sort->prev = prog;
	sort->next = NULL;
}

/**
 *insert_middle - insert a node in the middle of doubly linked list.
 *@sort:pointer to a node of doubly linked list.
 *@prog:pointer to a node of doubly linked list.
 */

void insert_middle(listint_t *sort, listint_t *prog)
{
	sort->next = prog->next;
	prog->next->prev = sort;
	sort->prev->next = prog;
	prog->next = sort;
	prog->prev = sort->prev;
	sort->prev = prog;
}

/**
 *insert_uniq - insert a node when only two nodes in a doubly linked list.
 *@sort:pointer to a node of doubly linked list.
 *@prog:pointer to a node of doubly linked list.
 */

void insert_uniq(listint_t *sort, listint_t *prog)
{
	sort->prev = prog;
	sort->next = NULL;
	prog->next = sort;
	prog->prev = NULL;
}
