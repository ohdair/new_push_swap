#include "push_swap.h"

/*
**	alpha == 'a' 한 번에 답인지 아닌지 확인, alpha == 'b' pb로 들어온 데이터가 변경하지 않아도 되는지 체크
*/
int	check_ans(t_list *A, t_list *B, char alpha)
{
	t_node *cur;

	if (alpha == 'a')
	{
		cur = A->head;
		while (cur != A->tail)
		{
			if (cur->next->index - cur->index < 1)
				return (0);
			cur = cur->next;
		}
	}
	else if (alpha == 'b')
	{
		cur = B->tail;
		while (cur != B->head)
		{
			if (cur->prev->index - cur->index < 1)
				return (0);
			cur = cur->next;
		}
	}
	return (1);
}

int	check_A(t_list *A, t_list *B, int max)
{
	if (A->head->index < (max / 2))
		return (1); // push(A, B);
	else if ((A->head->next->index - A->head->index) == 1 ||\
	(A->head->next->next->index - A->head->index) == 1)
		return (2); // swap(A);
	// else if (TopA.index - Bottom.index == 1)
	//	ra
	else if ((A->head->index - A->tail->index) == 1 ||\
	(A->head->index - A->tail->prev->index) == 1)
		return (3); // reverse_rotate(A);
	return (4); // rotate(A);
}

int	check_B(t_list *B, t_list *A)
{
	if ((B->head->index - B->head->next->index) == 1 ||\
	(B->head->index - B->head->next->next->index) == 1)
		return (2); // swap(B);
	// else if (TopB.index - Bottom.index == 1)
	//	ra
	else if ((B->tail->index - B->head->index) == 1 ||\
	(B->tail->prev->index - B->head->index) == 1)
		return (3); // reverse_rotate(B);
	return (4); // rotate(B);
}

void	check(t_list *A, t_list *B, int max)
{
	int	a;
	int	b;

	a = check_A(A, B, max);
	b = check_B(B, A);
	if (a == 2 && b == 2)
		ss(A, B);
	else if (a == 3 && b == 3)
		rrr(A, B);
	else if (a == 4 && b == 4)
		rr(A, B);
	else if (a == 1)
		pa(A, B);
	else if (a == 2)
		swap(A);
	
	
}