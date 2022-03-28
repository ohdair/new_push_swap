#include "push_swap.h"

void	push(t_pushswap *t, char alpha)
{
	t_node *tmp;

	if (alpha == 'a')
	{
		tmp = delNode(t->b);
		pushNode(t->a, tmp);
		write(1, "pa\n", 3);
	}
	else if (alpha == 'b')
	{
		tmp = delNode(t->a);
		pushNode(t->b, tmp);
		write(1, "pb\n", 3);
	}
}

void	rotate(t_pushswap *t, char alpha)
{
	t_node *tmp;

	if (alpha == 'a')
	{
		tmp = t->a->head;
		t->a->head = t->a->head->next;
		t->a->tail = tmp;
		write(1, "ra\n", 3);
	}
	else if (alpha == 'b')
	{
		tmp = t->b->head;
		t->b->head = t->b->head->next;
		t->b->tail = tmp;
		write(1, "rb\n", 3);
	}
}

void	reverse_rotate(t_pushswap *t, char alpha)
{
	t_node *tmp;

	if (alpha == 'a')
	{
		tmp = t->a->tail;
		t->a->tail = t->a->tail->prev;
		t->a->head = tmp;
		write(1, "rra\n", 4);
	}
	else if (alpha == 'b')
	{
		tmp = t->b->tail;
		t->b->tail = t->b->tail->prev;
		t->b->head = tmp;
		write(1, "rrb\n", 4);
	}
}

void	swap(t_pushswap *t, char alpha)
{
	t_node *tmp;

	if (alpha == 'a')
	{
		tmp = t->a->head->next;
		t->a->head->next = t->a->head->next->next;
		t->a->head->next->next->prev = t->a->head;
		tmp->next = t->a->head;
		tmp->prev = t->a->head->prev;
		pushNode(t->a, tmp);
		t->a->size--;
		write(1, "sa\n", 3);
	}
	else if (alpha == 'b')
	{
		tmp = t->b->head->next;
		t->b->head->next = t->b->head->next->next;
		t->b->head->next->next->prev = t->b->head;
		tmp->next = t->b->head;
		tmp->prev = t->b->head->prev;
		pushNode(t->b, tmp);
		t->b->size--;
		write(1, "sb\n", 3);
	}
}
