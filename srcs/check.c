/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 09:22:49 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/29 09:23:00 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
**	alpha == 'a' 한 번에 답인지 아닌지 확인, alpha == 'b' pb로 들어온 데이터가 변경하지 않아도 되는지 체크
*/
void	check_ans(t_list *A, t_list *B, char alpha)
{
	t_node *cur;

	if (alpha == 'a')
	{
		cur = A->head;
		while (cur != A->tail)
		{
			if (cur->next->index - cur->index < 1)
				return ;
			cur = cur->next;
		}
		A->flag = 1;
	}
	else if (alpha == 'b')
	{
		cur = B->tail;
		while (cur != B->head)
		{
			if (cur->prev->index - cur->index < 1)
				return ;
			cur = cur->next;
		}
		B->flag = 1;
	}
}

int	check_A(t_list *A, t_list *B, int max)
{
	if (A->flag == 1)
		return (0);
	if ((A->head->next->index - A->head->index) == 1 ||\
	(A->head->next->next->index - A->head->index) == 1)
		return (1); // swap(A);
	else if ((A->head->index - A->tail->index) == 1 ||\
	(A->head->index - A->tail->prev->index) == 1 ||\
	(A->tail->index < (max / 2)))
		return (2); // reverse_rotate(A);
	else if (A->head->index < (max / 2))
		return (3); // push(A, B);
	return (4); // rotate(A);
}

int	check_B(t_list *B, t_list *A)
{
	if (A->flag == 1 && A->head->index - B->head->index == 1)
		return (3);	// push(B, A);
	if (B->size == 0 || B->flag == 1)
		return (0);
	if ((B->head->index - B->head->next->index) == 1 ||\
	(B->head->index - B->head->next->next->index) == 1)
		return (1); // swap(B);
	else if ((B->tail->index - B->head->index) == 1 ||\
	(B->tail->prev->index - B->head->index) == 1)
		return (2); // reverse_rotate(B);
	return (4); // rotate(B);
}

void	check_sub(t_list *A, t_list *B, int a, int b)
{
	if (a == 3)
		push(A, B);
	else if (b == 3)
		push(B, A);
	else if (a == 4)
		rotate(A);
	else
		rotate(B);
}

void	check(t_list *A, t_list *B, int max)
{
	int	a;
	int	b;

	a = check_A(A, B, max);
	b = check_B(B, A);
	if (a == 1 && b == 1)
		ss(A, B);
	else if (a == 2 && b == 2)
		rrr(A, B);
	else if (a == 4 && b == 4)
		rr(A, B);
	else if (a == 1)
		swap(A);
	else if (b == 1)
		swap(B);
	else if (a == 2)
		reverse_rotate(A);
	else if (b == 2)
		reverse_rotate(B);
	else
		check_sub(A, B, a, b);
}
