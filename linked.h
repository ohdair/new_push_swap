#ifndef LINKED_H
# define LINKED_H

#include <stdlib.h>

typedef struct	s_node
{
	int	index;
	int	data;
	struct	s_node *next;
	struct  s_node *prev;
}	t_node;

typedef struct	s_list{
	t_node	*head;
	t_node	*tail;
	int	size;
	int	flag;
}	t_list;

t_list	*init_list(void);
void	addNode(t_list *ls, int data);
t_node	*delNode(t_list *ls);
void	reset_list(t_list *ls);

#endif