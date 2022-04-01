/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 19:08:38 by jaewpark          #+#    #+#             */
/*   Updated: 2022/04/01 19:42:24 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

int	checker(t_stack *a, t_stack *b, int size)
{
	char	*line;
	int		gnl;

	gnl = get_next_line(0, &line);
	if (*line)
	{
		while (gnl > 0)
		{
			if (!ft_strcmp(line, "Error"))
				error(2);
			operation(line, a, b);
			free(line);
			gnl = get_next_line(0, &line);
		}
		if (gnl < 0)
			error(2);
	}
	free(line);
	return (is_sort(a, size, 0));
}

int	main(int argc, char *argv[])
{
	char	***arg;
	int		size;
	int		result;
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		exit(1);
	arg = parsing_args(argv, argc);
	if (!arg)
		error(2);
	size = count(arg);
	init_stack(&a, &b, size, arg);
	result = checker(&a, &b, size);
	if (result == 0)
		write(1, "KO\n", 3);
	else if (result == 1 && b.top == -1)
		write(1, "OK\n", 3);
	else if (result == 1 && b.top != -1)
		write(1, "KO\n", 3);
	free(a.stack);
	a.stack = 0;
	free(b.stack);
	b.stack = 0;
	return (0);
}
