/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 11:28:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/30 15:36:10 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_push(t_pushswap *t, int **db)
{
	int	i;
	int	min;
	int	push_this;

	i = 0;
	min = db[i][6];
	while (++i < t->b->size)
		if (min > db[i][6])
			min = db[i][6];
	i = -1;
	while (++i < t->b->size)
		if (min == db[i][6])
			push_this = i;

	// i = 0;
	// push_this = 0;
	// min = db[i][6];
	// while (++i < t->b->size)
	// 	if (min > db[i][6])
	// 	{
	// 		min = db[i][6];
	// 		push_this = i;
	// 	}

	printf("push this : %d\n", push_this);
}

void	calculate(int *db)
{
	db[4] = ft_min((float)db[0], (float)db[2]);
	db[0] -= db[4];
	db[2] -= db[4];
	db[5] = ft_min((float)db[1], (float)db[3]);
	db[1] -= db[5];
	db[3] -= db[5];
	db[6] = ft_min((float)(db[0] + db[2] + db[4]), \
	(float)(db[1] + db[3] + db[5]));
	if (db[0] + db[2] + db[4] < db[1] + db[3] + db[5])
	{
		db[1] = 0;
		db[3] = 0;
		db[5] = 0;
	}
	else
	{
		db[0] = 0;
		db[2] = 0;
		db[4] = 0;
	}
}

static void	dest_me(t_pushswap *t, int **db, t_node *me, int my_location)
{
	t_node	*com;
	float	*array;
	int		dest;
	int		min;

	com = t->a->head;
	dest = -1;
	min = 2147483647;
	array = (float *)malloc(sizeof(float) * t->a->size);
	if (!array)
		error(0);
	while (++dest < t->a->size)
	{
		array[dest] = (float)(com->data - me->data);
		if (array[dest] > 0)
			min = ft_min(array[dest], (float)min);
		com = com->next;
	}
	dest = -1;
	while (dest < t->a->size)
		if (array[++dest] == min)
			break ;
	db[my_location][0] = dest;
	db[my_location][1] = t->a->size - dest;
	free(array);
}

static void	find_me(t_pushswap *t, int **db)
{
	t_node	*me;
	int		my_location;

	me = t->b->head;
	my_location = -1;
	while (++my_location < t->b->size)
	{
		dest_me(t, db, me, my_location);
		db[my_location][2] = my_location;
		db[my_location][3] = t->b->size - my_location;
		calculate(db[my_location]);
		me = me->next;
	}
}

void	b_to_a(t_pushswap *t)
{
	int	**db;
	int	i;

	db = database(t);
	// reset_db(t, db);
	find_me(t, db);
	// do_push(t, db);
	i = -1;
	while (++i < t->b->size)
	{
		printf("%d번째 : %d ", i, db[i][0]);
		printf("%d ", db[i][1]);
		printf("%d ", db[i][2]);
		printf("%d ", db[i][3]);
		printf("%d ", db[i][4]);
		printf("%d ", db[i][5]);
		printf(" = %d\n", db[i][6]);
	}
	delete_db(t, db);
}
