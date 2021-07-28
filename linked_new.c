#include "linked.h"

void	init_all(t_list *A, t_list *B, t_list *ans, t_list *ansA, t_list *ansB)
{
	A = init_list();
	B = init_list();
	ans = init_list();
	ansA = init_list();
	ansB = init_list();
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