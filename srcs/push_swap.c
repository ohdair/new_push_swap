/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:57:45 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/29 10:03:08 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

	// 에러 파일 만들기
	// 파싱 완료 후 push_swap 함수 진행
	// push_swap(t);
int	main(int argc, char **argv)
{
	t_pushswap	*t;
	char		**a;

	a = argv;
	if (argc < 2)
		exit(1);
	t = (t_pushswap *)malloc(sizeof(t_pushswap));
	init_pushswap(t);
	if (!t || !t->a || !t->b)
		error(0);
	if (!parsing_arg(argv, argc, t))
		error(1);
	// if (t->a->size > 3)
	// {
	// 	push(t, 'b');
	// 	push(t, 'b');
	// 	push(t, 'b');
	// }
	// reset_list(t->b);
	// reset_list(t->a);
	return (0);
}
