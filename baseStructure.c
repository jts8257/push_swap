#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list *a_lst;
    t_list *b_lst;

    if (argc < 2) // 인자가 제대로 안들어오면 error
        error_handle("Error:Argument Count Not Matched(argc > 1)");
    make_lst(argc, argv, &a_lst, &b_lst);

    print_msg("injected number test", 1);
    ft_lstiter(a_lst, print_num);
    write(1, "\n", 1);
    ft_lstiter(b_lst, print_num);
    write(1, "\n", 1);
    check_duplicate(&a_lst);// 중복값 확인

    //--------- 테스트 영역 ---------

    print_msg("swap a test", 1);
    swaplst(&a_lst);
    ft_lstiter(a_lst, print_num);
    write(1, "\n", 1);
    ft_lstiter(b_lst, print_num);
    write(1, "\n", 1);

    print_msg("push a test", 1);
    push(&a_lst, &b_lst);
    ft_lstiter(a_lst, print_num);
    write(1, "\n", 1);
    ft_lstiter(b_lst, print_num);
    write(1, "\n", 1);

    print_msg("swap all test", 1);
    swapall(&a_lst, &b_lst);
    ft_lstiter(a_lst, print_num);
    write(1, "\n", 1);
    ft_lstiter(b_lst, print_num);
    write(1, "\n", 1);

    print_msg("rotate a test", 1);
    rotate(&a_lst);
    ft_lstiter(a_lst, print_num);
    write(1, "\n", 1);
    ft_lstiter(b_lst, print_num);
    write(1, "\n", 1);

    print_msg("rotate all test", 1);
    rotateall(&a_lst, &b_lst);
    ft_lstiter(a_lst, print_num);
    write(1, "\n", 1);
    ft_lstiter(b_lst, print_num);
    write(1, "\n", 1);

    print_msg("push a again", 1);
    push(&a_lst, &b_lst);
    ft_lstiter(a_lst, print_num);
    write(1, "\n", 1);
    ft_lstiter(b_lst, print_num);
    write(1, "\n", 1);

    print_msg("rotate all again", 1);
    rotateall(&a_lst, &b_lst);
    ft_lstiter(a_lst, print_num);
    write(1, "\n", 1);
    ft_lstiter(b_lst, print_num);
    write(1, "\n", 1);

    print_msg("riverse rotate a test", 1);
    rrotate(&a_lst);
    ft_lstiter(a_lst, print_num);
    write(1, "\n", 1);
    ft_lstiter(b_lst, print_num);
    write(1, "\n", 1);

}