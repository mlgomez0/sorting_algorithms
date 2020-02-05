#include "sort.h"


/**
 *cocktail_sort_list - sort an array using the cocktail sort algorithm.
 *@list:Doubly linked list to be sorted
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *prog, *progt, *tail;
	int check_sort = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	tail = *list;
	while (tail->next)
	{
		tail = tail->next;
	}
	do {
		prog = (*list)->next;
		check_sort = 0;
		r_c(prog, list, &tail, &check_sort);
		if (check_sort == 0)
			break;
		check_sort = 0;
		progt = tail->prev;
		l_c(progt, list, &tail, &check_sort);
	} while (check_sort);
}

/**
 *r_c - makes the right cicle sortin a doubly linked list.
 *@prog:pointer to a node to start sort.
 *@list:head of the doubly linked list.
 *@tail:tail of the doubly linked list.
 *@check_sort: controls if the list is already sorted.
 */

void r_c(listint_t *prog, listint_t **list, listint_t **tail, int *check_sort)
{
	listint_t *sort, *temp;
	int end_list = 0;

	while (prog)
	{
		sort = prog->prev;
		temp = prog->next;
		if (temp == NULL)
			end_list = 1;
		if (sort->n > prog->n)
		{
			*check_sort = 1;
			if (sort->prev == NULL && prog->next == NULL)
			{
				insert_all(list, sort, prog, 4);
				*tail = sort;
			}
			else if (sort->prev == NULL)
			{
				insert_all(list, sort, prog, 1);
				*list = prog;
			}
			else if (end_list == 1)
			{
				insert_all(list, sort, prog, 2);
				*tail = sort;
				end_list = 0;
			}
			else
				insert_all(list, sort, prog, 3);
			print_list(*list);
		}
		prog = temp;
	}
}

/**
 *l_c - makes the left cicle sorting a doubly linked list.
 *@progt:pointer to a node to start sort.
 *@list:head of the doubly linked list.
 *@tail:tail of the doubly linked list.
 *@check_sort: controls if the list is already sorted.
 */

void l_c(listint_t *progt, listint_t **list, listint_t **tail, int *check_sort)
{
	int end_list = 0;
	listint_t *tempt, *sortt;

	while (progt)
	{
		sortt = progt->next;
		tempt = progt->prev;
		if (sortt == NULL)
			end_list = 1;
		if (sortt->n < progt->n)
		{
			*check_sort = 1;
			if (sortt->next == NULL && progt->prev == NULL)
			{
				insert_all(list, progt, sortt, 4);
				*tail = progt;
			}
			else if (progt->prev == NULL)
			{
				insert_all(list, progt, sortt, 1);
				*list = sortt;
			}
			else if (end_list == 1)
			{
				insert_all(list, progt, sortt, 2);
				*tail = progt;
				end_list = 0;
			}
			else
				insert_all(list, progt, sortt, 3);
			print_list(*list);
		}
		progt = tempt;
	}
}


/**
 *insert_all - insert a node at the indicated place in doubly linked list.
 *@list: head of the doubly linked list.
 *@sort:pointer to a node of doubly linked list.
 *@prog:pointer to a node of doubly linked list.
 *@ind:indication to add the node (1 = top, 2 = end, 3 = mid, 4 = uniq).
 */

void insert_all(listint_t **list, listint_t *sort, listint_t *prog, int ind)
{
	if (ind == 1)
	{
		sort->next = prog->next;
		prog->next->prev = sort;
		prog->next = sort;
		sort->prev = prog;
		prog->prev = NULL;
	}
	else if (ind == 2)
	{
		sort->prev->next = prog;
		prog->prev = sort->prev;
		prog->next = sort;
		sort->prev = prog;
		sort->next = NULL;
	}
	else if (ind == 3)
	{
		sort->next = prog->next;
		prog->next->prev = sort;
		sort->prev->next = prog;
		prog->next = sort;
		prog->prev = sort->prev;
		sort->prev = prog;
	}
	else
	{
		sort->prev = prog;
		sort->next = NULL;
		prog->next = sort;
		prog->prev = NULL;
		*list = prog;
	}
}
