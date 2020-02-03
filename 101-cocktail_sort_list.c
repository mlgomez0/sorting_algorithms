#include "sort.h"

/**
 *cocktail_sort_list - sort an array using the cocktail sort algorithm.
 *@list:Doubly linked list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *temp, *sort, *prog, *progt, *sortt, *tempt, *tail;
	int check_sort = 0, end_list;

	if (list == NULL || *list == NULL)
		return;
	tail = *list;
	while (tail->next)
	{
		tail = tail->next;
	}
	prog = (*list)->next;
	progt = tail->prev;
	do {
		check_sort = 0;
		while (prog)
		{
			sort = prog->prev;
			temp = prog->next;
			if (temp == NULL)
				end_list = 1;
			if (sort->n > prog->n)
			{
				check_sort = 1;
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
			prog = temp;
		}
		if (check_sort == 0)
			break;
		while (progt)
		{
			end_list = 0;
			sortt = progt->next;
			tempt = progt->prev;
			if (tempt == NULL)
				end_list = 1;
			if (sortt->n < progt->n)
			{
				check_sort = 1;
				if (sortt->next == NULL && progt->prev == NULL)
				{
					insert_uniq(progt, sortt);
					*list = sortt;
				}
				else if (progt->prev == NULL)
				{
					insert_top(progt, sortt);
					*list = sortt;
				}
				else if (end_list == 1)
				{
					insert_end(progt, sortt);
					end_list = 0;
				}
				else
					insert_middle(progt, sortt);
				print_list(*list);
			}
			progt = tempt;
		}

	} while (check_sort);
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
