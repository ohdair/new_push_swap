#include "push_swap.h"
#include <stdio.h>

static int is_space(char c)
{
    if (c == ' ' || (c >= 9 && c <= 13))
        return(1);
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
	while (*str && '0' <= *str && *str <= '9')
	{
		nbr = (nbr * 10) + (*str - '0');
		if (nbr > 2147483647 && sign == 1)
			return (-1);
		if (nbr > 2147483648 && sign == -1)
			return (0);
		str++;
	}
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

int ft_split(char *argv, t_pushswap *t)
{
    int data;

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
            if (data)
                exit(1);
            addNode(t->a, data);
        }
        while (*argv != 0 && !is_space(*argv))
			++argv;
    }
    return (1);
}

static int parsing_arg(char **argv, int argc, t_pushswap *t)
{
    int i;

    i = 0;
    while (++i < argc)
    {
        if (!ft_split(argv[i], t))
        {
            ft_destroy(t);
            return (0);
        }
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_pushswap  *t;

    if (argc < 2)
        exit(1);
    t = (t_pushswap *)malloc(sizeof (t_pushswap));
    if (!t)
        error('malloc');
    if (!parsing_arg(argv, argc, t))
        error('parsing');

    // 에러 파일 만들기
    // 파싱 완료 후 push_swap 함수 진행
    push_swap(t);
    
    return (0);
}