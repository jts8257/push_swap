#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_lst *a_lst;
    t_lst *b_lst;
    int i;

    if (argc < 2) // 인자가 제대로 안들어오면 error
        error_handle("Error:Argument Count Not Matched(argc > 1)");
    a_lst = init_lst();
    b_lst = init_lst();
    i = 1;
    while (i < argc)
    {
        add_last(a_lst, ft_swap_atoi(argv[i]));
        i++;
    }
    print_msg("print a_lst", 1);
    iter_lst(a_lst);
    print_msg("", 1);

    // TODO #1 퀵 정렬에 사용할 적절한 피봇 고르는 함수. -> median 을 찾아서 주려면 정렬을 해야함.
    // TODO #2 스택이 정렬되어 있는지 체크하는 함수.
    // TODO #3 a 스택에 pivot 기준으로 큰 값을 남겨두기. 작은 값은 b 스택에 쌓기

    exit(0);
}