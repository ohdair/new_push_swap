/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 11:26:10 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/30 21:18:27 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_abs(int a, int b)
{
	int	flag;

	flag = -1;
	if (a - b < -2147483648)
		return (-2147483648);
	if (a - b < 0)
		return ((a - b) * flag);
	if (a - b > 2147483647)
		return (2147483647);
	return (a - b);
}

void	delete_db(t_pushswap *t, int **db)
{
	int	i;

	i = -1;
	while (++i < t->db_height)
		free(db[i]);
	free(db);
}

void	reset_db(t_pushswap *t, int ***db)
{
	int	i;
	int	j;

	i = -1;
	while (++i < t->b->size)
	{
		j = -1;
		while (++j < 7)
			(*db)[i][j] = 0;
	}
	return ;
}

int	**database(t_pushswap *t)
{
	int	**array;
	int	i;

	t->db_height = t->b->size;
	array = (int **)malloc(sizeof(int *) * t->b->size);
	if (!array)
		error(0);
	i = -1;
	while (++i < t->b->size)
	{
		array[i] = (int *)malloc(sizeof(int) * 7);
		if (!array[i])
			error(0);
	}
	return (array);
}

int	ft_min(float a, float b)
{
	if (a < b)
		return ((int)a);
	return ((int)b);
}
