/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:57:45 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/28 14:37:33 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	error(int code)
{
	if (code == 0)
		write(1, "There was a problem while creating\n", 36);
	else if (code == 1)
		write(1, "There was a problem while parsing\n", 35);
	else
		write(1, "error\n", 6);
	exit(1);
}

static int	is_space(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	long long	sign;
	long long	nbr;

	sign = 1;
	nbr = 0;
	while (*str && is_space(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (*str == 0)
		error(2);
	while (*str != 0)
	{
		if (*str && '0' <= *str && *str <= '9')
			nbr = (nbr * 10) + (*str++ - '0');
		else
			error(2);
	}
	if ((nbr > 2147483647 && sign == 1) || (nbr > 2147483648 && sign == -1) ||\
		 (nbr == 0 && sign == -1))
		error(2);
	return ((int)(nbr * sign));
}

static char	*save_word(char *str)
{
	char	*word;
	size_t	i;

	i = 0;
	while (str[i] && !is_space(str[i]))
		++i;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	i = -1;
	while (str[++i] != 0 && !is_space(str[i]))
		word[i] = str[i];
	word[i] = '\0';
	return (word);
}

int	ft_split(char *argv, t_pushswap *t)
{
	char	*tmp;
	int		data;

	if (!argv)
		return (0);
	while (*argv != 0)
	{
		while (*argv != 0 && is_space(*argv))
			++argv;
		if (*argv != 0 && !is_space(*argv))
		{
			tmp = save_word(argv);
			data = ft_atoi(tmp);
			addNode(t->a, data);
		}
		while (*argv != 0 && !is_space(*argv))
			++argv;
	}
	return (1);
}

// ft_destroy(t); -> write 함수에 넣을 것
static int	parsing_arg(char **argv, int argc, t_pushswap *t)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!ft_split(argv[i], t))
		{
			write(1, "error", 5);
			return (0);
		}
	}
	return (1);
}

	// 에러 파일 만들기
	// 파싱 완료 후 push_swap 함수 진행
	// push_swap(t);
int	main(int argc, char **argv)
{
	t_pushswap	*t;
	char	**a;

	a = argv;
	if (argc < 2)
		exit(1);
	t = (t_pushswap *)malloc(sizeof(t_pushswap));
	init_pushswap(t);
	if (!t || !t->a || !t->b)
		error(0);
	if (!parsing_arg(argv, argc, t))
		error(1);
	reset_list(t->a);
	return (0);
}
