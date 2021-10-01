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
    iter_lst(a_lst);
    print_msg("", 1);

    swap_lst(a_lst);
    iter_lst(a_lst);
    print_msg("", 1);

    push_lst(a_lst, b_lst);
    iter_lst(a_lst);
    print_msg("", 1);
    iter_lst(b_lst);
    print_msg("", 1);

    push_lst(a_lst, b_lst);
    iter_lst(a_lst);
    print_msg("", 1);
    iter_lst(b_lst);
    print_msg("", 1);

    push_lst(a_lst, b_lst);
    iter_lst(a_lst);
    print_msg("", 1);
    iter_lst(b_lst);
    print_msg("", 1);

    rotate_lst(a_lst);
    print_msg("rotate a_lst", 1);
    iter_lst(a_lst);
    print_msg("", 1);

    rrotate_lst(b_lst);
    print_msg("rrotate b_lst", 1);
    iter_lst(b_lst);
    print_msg("", 1);
    exit(0);
}
