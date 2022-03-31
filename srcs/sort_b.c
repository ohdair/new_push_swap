/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:24:19 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/31 11:36:39 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_pushswap *t)
{
	int	size;
	int	i;

	size = t->a->size;
	i = -1;
	while (++i < size)
	{
		if (t->a->head->index != t->lis)
		{
			call_utils(t, "pb");
			if (size > 100 && t->b->head->data >= t->mid)
				call_utils(t, "rb");
		}
		else
		{
			call_utils(t, "ra");
			t->lis--;
		}
	}
}

void	last_sort(t_pushswap *t)
{
	t_node	*cur;
	int		i;

	cur = t->a->head;
	i = -1;
	while (++i < t->a->size)
	{
		if (t->min == cur->data)
			break ;
		cur = cur->next;
	}
	if (i < t->a->size - i)
		while (--i >= 0)
			call_utils(t, "ra");
	else
		while (t->a->size - (++i) >= 0)
			call_utils(t, "rra");
}

static void	set_push(t_pushswap *t, int ***db, int this)
{
	while ((*db)[this][0]-- > 0)
		call_utils(t, "ra");
	while ((*db)[this][1]-- > 0)
		call_utils(t, "rra");
	while ((*db)[this][2]-- > 0)
		call_utils(t, "rb");
	while ((*db)[this][3]-- > 0)
		call_utils(t, "rrb");
	while ((*db)[this][4]-- > 0)
		call_utils(t, "rr");
	while ((*db)[this][5]-- > 0)
		call_utils(t, "rrr");
	call_utils(t, "pa");
}

void	get_push(t_pushswap *t, int ***db)
{
	int	i;
	int	min;
	int	push_this;

	i = 0;
	min = (*db)[i][6];
	while (++i < t->b->size)
		if (min > (*db)[i][6])
			min = (*db)[i][6];
	i = -1;
	while (++i < t->b->size)
		if (min == (*db)[i][6])
			push_this = i;
	i = -1;
	set_push(t, db, push_this);
}
