/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 16:24:19 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/29 22:09:39 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_db(t_pushswap *t, int **db)
{
	int	i;
	int	j;

	i = -1;
	while (++i < t->b->size)
	{
		j = -1;
		while (++j < 7)
			db[i][j] = 0;
		free(db[i]);
	}
	free(db);
}

void	reset_record(t_pushswap *t)
{
	t->rec_loc = 0;
	t->rec_min = 2147483647;
}

int		record(t_pushswap *t, int location, int min)
{
	if (t->rec_min > min)
	{
		t->rec_min = min;
		t->rec_loc = location;
		return (1);
	}
	return (0);
}

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
