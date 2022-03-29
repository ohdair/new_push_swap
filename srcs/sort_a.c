/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:28:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/29 22:03:46 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	**database(t_pushswap *t)
{
	int	**db;
	int	i;
	int	j;

	db = (int **)malloc(sizeof(int *) * t->b->size);
	if (!db)
		error(0);
	i = -1;
	while (++i < t->b->size)
	{
		// ra rra rb rrb rr rrr sum(배열 7개 순서)
		db[i] = (int *)malloc(sizeof(int) * 7);
		if (!db[i])
			error(0);
		j = -1;
		while (++j < 7)
			db[i][j] = 0;
	}
	t->b->flag = 0;
	return (db);
}

static void	calculate(int **db, int index, int a, int b)
{
	if (db[index][a] > 0 && db[index][b] > 0)
	{
		if (db[index][a] >= db[index][b])
		{
			db[index][a] -= db[index][b];
			db[index][b] = 0;
			db[index][b * 2 - a] = db[index][b];
		}
		else
		{
			db[index][a] = 0;
			db[index][b] -= db[index][a];
			db[index][b * 2 - a] = db[index][a];
		}
	}
}

// ra rra rb rrb rr rrr sum(배열 7개 순서)
static void	write_db(t_pushswap *t, int **db, int index)
{
	t_node	*cur;
	t_node	*tmp;
	int		location;

	location = -1;
	cur = t->b->head;
	while (++location < index)
		cur = cur->next;
	if (index <= t->b->size - index)
		db[index][2] = index;
	else
		db[index][3] = t->b->size - index;
	location = -1;
	tmp = t->a->head;
	reset_record(t);
	while (++location < t->a->size)
	{
		if (tmp->data - cur->data > 0)
			record(t, location, tmp->data - cur->data);
		tmp = tmp->next;
	}
	printf("%d location\n", t->rec_loc);
	if (t->rec_loc <= t->a->size - t->rec_loc)
		db[index][0] = t->rec_loc;
	else
		db[index][1] = t->a->size - t->rec_loc;
}

static void	do_push(t_pushswap *t, int **db, int address)
{
	while (db[address][0]--)
		call_utils(t, "ra");
	while (db[address][1]--)
		call_utils(t, "rra");
	while (db[address][2]--)
		call_utils(t, "rb");
	while (db[address][3]--)
		call_utils(t, "rrb");
	while (db[address][4]--)
		call_utils(t, "rr");
	while (db[address][5]--)
		call_utils(t, "rrr");
	delete_db(t, db);
	call_utils(t, "pa");
}

void	b_to_a(t_pushswap *t)
{
	int	**db;
	int	address;
	int	i;

	while (t->b->size)
	{
		i = -1;
		db = database(t);
		printf("%d번째 db : \n", t->b->size);
		while (++i < t->b->size)
		{
			write_db(t, db, i);
			calculate(db, i, 0, 2);
			calculate(db, i, 1, 3);
			db[i][6] = db[i][0] + db[i][1] + db[i][2] + db[i][3] + \
			db[i][4] + db[i][5];
			if (t->b->flag >= db[i][6])
			{
				t->b->flag = db[i][6];
				address = i;
			}
			printf("%d %d %d %d %d %d = %d\n", db[i][0], db[i][1], db[i][2], db[i][3], db[i][4], db[i][5], db[i][6]);
		}
		printf("\n");
		do_push(t, db, address);
	}
}
