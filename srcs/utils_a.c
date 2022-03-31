/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:21:29 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/31 10:43:00 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_pushswap *t, char alpha)
{
	t_node	*tmp;

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
	return (1);
}

int	rotate(t_pushswap *t, char alpha)
{
	t_node	*tmp;

	if (alpha == 'a')
	{
		tmp = t->a->head;
		t->a->head = t->a->head->next;
		t->a->tail = tmp;
	}
	else if (alpha == 'b')
	{
		tmp = t->b->head;
		t->b->head = t->b->head->next;
		t->b->tail = tmp;
	}
	return (1);
}

int	reverse_rotate(t_pushswap *t, char alpha)
{
	t_node	*tmp;

	if (alpha == 'a')
	{
		tmp = t->a->tail;
		t->a->tail = t->a->tail->prev;
		t->a->head = tmp;
	}
	else if (alpha == 'b')
	{
		tmp = t->b->tail;
		t->b->tail = t->b->tail->prev;
		t->b->head = tmp;
	}
	return (1);
}

int	swap(t_pushswap *t, char alpha)
{
	t_node	*tmp;

	if (alpha == 'a')
	{
		tmp = t->a->head->next;
		t->a->head->next = t->a->head->next->next;
		t->a->head->next->next->prev = t->a->head;
		tmp->next = t->a->head;
		tmp->prev = t->a->head->prev;
		pushNode(t->a, tmp);
		t->a->size--;
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
	}
	return (1);
}
