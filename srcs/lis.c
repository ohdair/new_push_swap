/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:15:57 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/29 15:23:41 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	get_index(t_pushswap *t, int *array)
{
	int	*arr;
	int	i;
	int	j;
	int	temp;

	arr = array;
	i = 0;
	while (i < t->a->size)
	{
		j = 0;
		while (j < i)
		{
			if (arr[j] > arr[i])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
			j++;
		}
		i++;
	}
	t->mid = arr[t->a->size / 2];
	t->min = arr[0];
	t->max = arr[t->a->size - 1];
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

static int	*get_array(t_pushswap *t)
{
	t_node	*cur;
	int		*array;
	int		i;

	array = (int *)malloc(sizeof(int) * (t->a->size));
	if (!array)
		error(0);
	i = 0;
	cur = t->a->head;
	while (cur != t->a->tail)
	{
		array[i] = cur->data;
		cur = cur->next;
		i++;
	}
	array[i] = cur->data;
	return (array);
}

static void	put_lis(t_pushswap *t, int *lis, int *array)
{
	t_node	*cur;
	int		i;
	int		max;

	i = 0;
	max = 0;
	cur = t->a->head;
	while (cur != t->a->tail)
	{
		cur->index = lis[i];
		cur = cur->next;
		if (max < ft_max(lis[i], lis[i + 1]))
			max = ft_max(lis[i], lis[i + 1]);
		i++;
	}
	cur->index = lis[i];
	get_index(t, array);
	t->lis = max;
	free(lis);
}

int	get_lis(t_pushswap *t)
{
	int	*lis;
	int	*array;
	int	i;
	int	j;

	lis = malloc(sizeof(int) * (t->a->size));
	if (!lis)
		error(0);
	array = get_array(t);
	i = t->a->size - 1;
	lis[i] = 1;
	while (i >= 0)
	{
		j = i - 1;
		lis[i] = 1;
		while (j++ < t->a->size)
			if (array[i] < array[j])
				lis[i] = ft_max(lis[i], lis[j] + 1);
		--i;
	}
	put_lis(t, lis, array);
	free(array);
	return (1);
}
