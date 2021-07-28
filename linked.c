#include "linked.h"

t_list	*init_list(void)
{
	t_list *ls = (t_list*)malloc(sizeof(t_list));

	ls->head = NULL;
	ls->tail = NULL;
	ls->size = 0;
	ls->flag = 0;
	return (ls);
}

void	addNode(t_list *ls, int data)
{
	t_node *tmp = (t_node*)malloc(sizeof(t_node));

	tmp->data = data;
	tmp->index = 0;
	if (ls->head == NULL)
	{
		ls->head = tmp;
		ls->tail = tmp;
		tmp->next = tmp;
		tmp->prev = tmp;
	}
	else
	{
		tmp->next = ls->head;
		tmp->prev = ls->tail->next;
		ls->head = tmp;
		ls->tail->next = tmp;
	}
	ls->size++;
}

t_node	*delNode(t_list *ls)
{
	t_node	*cur;
	t_node	*tmp;

	cur = ls->head;
	tmp = ls->head->next;
	tmp->prev = ls->tail;
	ls->tail->next = tmp;
	cur->next = NULL;
	cur->prev = NULL;
	// free(cur);	void형 -> t_node 형으로 변경하여 push에 사용
	ls->head = tmp;
	ls->size--;
	return (cur);
}

void	reset_list(t_list *ls)
{
	t_node	*cur;
	t_node	*tmp;

	cur = ls->head;
	while (cur != ls->tail)
	{
		tmp = cur->next;
		// cur->next = NULL;
		// cur->prev = NULL;
		free(cur);
		cur = tmp;
		ls->size--;
	}
	// cur->next = NULL;
	// cur->prev = NULL;
	free(cur);
	ls->size--;
	ls->head = NULL;
	ls->tail = NULL;
	ls->size = 0;
}