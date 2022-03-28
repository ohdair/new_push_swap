#include "push_swap.h"

// av[] = int
int	read_num(char *s)
{
	int ret;

	ret = 0;
	while (!*s)
	{
		if ('0' <= *s && *s <= '9')
			ret = ret * 10 + (*s - '0');
		s++;
	}
	return (ret);
}
