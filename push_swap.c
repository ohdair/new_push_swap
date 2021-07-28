#include "push_swap.h"
#include <stdio.h>

int main(int ac, char *av[])
// int main()
{
    t_list  *A;
    t_list  *B;
    t_list  *ans;
    t_list  *ans_A;
    t_list  *ans_B;
    int i;
    int put;

    i = 0;
    init_all(A, B, ans, ans_A, ans_B);
    // 1. 입력
    // 2. 정렬
    // 3. ans 입력, ans_A & ans_B 로 나누기
    // 4. 
    while (i++ < ac)
    {
        put = read_num(av[i]);
        addNode(ans, put);
        addNode(A, put);
    }
    sort_ans();
    write_index(ans);
    copy_index(A);
    start_sorting();
    return (0);
}
    // ans = 입력받은 것에 대한 최종 답
    // ans_A, ans_B = 입력받은 것에 대한 A, B 에서 최종답