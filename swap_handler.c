#include "push_swap.h"
#include <stdio.h>

// 아직까지는 swapa, swapb 함수를 따로 만들어야 하는 이유를 모르겠음. 기능적으로 동일한것 아닌가?
void    swaplst(t_list **lst)
{
    int tmp;
    if ((*lst)->is_injected == 0 || (*lst)->next->is_injected == 0
        || *lst == NULL || (*lst)->next == NULL)
        return ;
    tmp = (*lst)->next->num;
    (*lst)->next->num = (*lst)->num;
    (*lst)->num = tmp;
}

void    swapall(t_list **a_lst, t_list **blst)
{
    swaplst(a_lst);
    swaplst(blst);
}

// pa : take the first element at the top of b and put it at the top of a. 
// Donothing if b is empty.
// pb is opposite direction, 기능적으로 동일함.
void    push(t_list **srclst, t_list **destlst)
{
    if ((*srclst)->is_injected == 0) // srclst 가 비어있으면 아무것도 안함
    return ;
    // srclst 의 최상위 값을 destlst 최상위 값으로 옮김.
    ft_lstadd_front(destlst, ft_lstnew((*srclst)->num, 1));  
    // src 의 최상위 lst 를 삭제하고 나머지를 이어붙여줌
    ft_delhead(srclst);
}

// shift up all elements of stack a by 1. The first element becomes the last one
void    rotate(t_list **lst)
{
    ft_copy_top_to_botoom(lst);
    ft_delhead(lst);
}

// rr
void    rotateall(t_list **a_lst, t_list **b_lst)
{
    rotate(a_lst);
    rotate(b_lst);
}

// reverse rotate a - shift down all elements of stack a by 1. The last element
// becomes the first one.
void    rrotate(t_list **lst)
{
    ft_copy_bottom_to_top(lst);
    ft_dellast(lst);
}