#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "linked.h"
// #include <unistd.h>

/*
**	option_A
*/
void	swap(t_list *ls);
void	rotate(t_list *ls);
void	reverse_rotate(t_list *ls);
void	push(t_list *A, t_list *B);

/*
**	option_B
*/
void	ss(t_list *A, t_list *B);
void	rr(t_list *A, t_list *B);
void	rrr(t_list *A, t_list *B);

/*
**	linked_new
*/
void	init_all(t_list *A, t_list *B, t_list *answer);
void	pushNode(t_list *ls, t_node *newNode);
int	searchNode(t_list *ls, int search);

/*
**	check
*/
void	check_ans(t_list *A, t_list *B, char alpha);
int	check_A(t_list *A, t_list *B, int max);
int	check_B(t_list *B, t_list *A);
void	check(t_list *A, t_list *B, int max);

/*
**	read
*/
int	read_num(char *s);

#endif