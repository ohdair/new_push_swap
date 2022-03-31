/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaewpark <jaewpark@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 10:04:20 by jaewpark          #+#    #+#             */
/*   Updated: 2022/03/31 11:27:03 by jaewpark         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_H
# define LINKED_H

# include <stdlib.h>

typedef struct s_node
{
	int				index;
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	t_node	*head;
	t_node	*tail;
	int		size;
	int		flag;
}	t_list;

t_node	*delNode(t_list *ls);
void	pushNode(t_list *ls, t_node *newNode);
void	addNode(t_list *ls, int data);
void	reset_list(t_list *ls);
int		searchNode(t_list *ls, int search);

#endif
