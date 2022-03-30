/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:57:45 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/30 16:41:19 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_list(t_list *ls)
{
	ls->head = NULL;
	ls->tail = NULL;
	ls->size = 0;
	ls->flag = 0;
}

static void	init_pushswap(t_pushswap *t)
{
	t->a = (t_list *)malloc(sizeof(t_list));
	t->b = (t_list *)malloc(sizeof(t_list));
	init_list(t->a);
	init_list(t->b);
}

void	error(int code)
{
	if (code == 0)
		write(1, "There was a problem while malloc creating\n", 42);
	else if (code == 1)
		write(1, "There was a problem while parsing\n", 35);
	else
		write(1, "error\n", 6);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_pushswap	*t;

	if (argc < 2)
		exit(1);
	t = (t_pushswap *)malloc(sizeof(t_pushswap));
	init_pushswap(t);
	if (!t || !t->a || !t->b)
		error(0);
	if (!parsing_arg(argv, argc, t))
		error(1);
	get_lis(t);
	a_to_b(t);
	b_to_a(t);
	/*
	현재 진행상황 : 화요일 13:24
		1. array 생성 max, min, mid 값 산출
		2. array 이용해서 lis 생성
		3. lis 이용해서 a_to_b 함수 완료
	테스트
		a_to_b 확인 까지 완료
	*/
	reset_list(t->a);
	// printf("\n------up : a / down : b------\n");
	if (t->b->size)
		reset_list(t->b);
	return (0);
}
