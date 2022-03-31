/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:22:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/31 11:01:59 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_short(t_pushswap *t)
{
	if (t->a->head->data == t->max)
		call_utils(t, "ra");
	if ((t->a->head->data == t->min && t->a->head->next->data == t->max) || \
		t->a->tail->data == t->min)
		call_utils(t, "rra");
	if (t->a->head->next->data == t->min)
		call_utils(t, "sa");
}
