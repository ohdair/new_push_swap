#include "push_swap.h"

void	init_pushswap(t_pushswap *t)
{
	t->a = (t_list *)malloc(sizeof(t_list));
	t->b = (t_list *)malloc(sizeof(t_list));
	init_list(t->a);
	init_list(t->b);
}

void	pushNode(t_list *ls, t_node *newNode)
{
	if (ls->head == NULL)
	{
		ls->head = newNode;
		ls->tail = newNode;
		newNode->next = newNode;
		newNode->prev = newNode;
	}
	else
	{
		newNode->next = ls->head;
		newNode->prev = ls->tail->next;
		ls->head = newNode;
		ls->tail->next = newNode;
	}
	ls->size++;
}

int	searchNode(t_list *ls, int search)
{
	t_node *cur;

	cur = ls->head;
	while (cur != ls->tail)
	{
		if (cur->data == search)
			break;
		cur = cur->next;
	}
	return (cur->index);
}
