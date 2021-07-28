#include "linked.h"

void	ss(t_list *A, t_list *B)
{
	swap(A, 'c');
	swap(B, 'c');
	write(1, "ss\n", 3);
}

void	rr(t_list *A, t_list *B)
{
	rotate(A, 'c');
	rotate(B, 'c');
	write(1, "rr\n", 3);
}

void	rrr(t_list *A, t_list *B)
{
	reverse_rotate(A, 'c');
	reverse_rotate(B, 'c');
	write(1, "rrr\n", 4);
}