#include "linked.h"

void	swap(t_list *ls, char alpha)
{
	int	tmp;

	tmp = ls->head->next->data;
	ls->head->next->data = ls->head->data;
	ls->head->data = tmp;
	if (alpha == 'a')
		write(1, "sa\n", 3);
	else if (alpha == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_list *ls, char alpha)
{
	t_node *tmp;

	tmp = ls->head;
	ls->head = ls->head->next;
	ls->tail = tmp;
	if (alpha == 'a')
		write(1, "ra\n", 3);
	else if (alpha == 'b')
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_list *ls, char alpha)
{
	t_node *tmp;

	tmp = ls->tail;
	ls->tail = ls->tail->prev;
	ls->head = tmp;
	if (alpha == 'a')
		write(1, "rra\n", 4);
	else if (alpha == 'b')
		write(1, "rrb\n", 4);
}

void	push(t_list *A, t_list *B, char alpha)
{
	t_node *tmp;

	tmp = delNode(A);
	pushNode(B, tmp);
	if (alpha == 'a')
		write(1, "pa\n", 3);
	else if (alpha == 'b')
		write(1, "pb\n", 4);
}