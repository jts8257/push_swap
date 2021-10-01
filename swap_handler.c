#include "push_swap.h"

//swap
// push
// rotate
// rrotate

void    swap_lst(t_lst *lst)
{
    int tmp;

    if (lst->head == NULL || lst->head == lst->tail)
        return ;
    tmp = lst->head->data;
    lst->head->data = lst->head->next->data;
    lst->head->next->data = tmp;
}

void    push_lst(t_lst *srclst, t_lst *dstlst)
{
    if (srclst->head == NULL)
        return ;
    if (dstlst == NULL)
        dstlst = init_lst();
    add_first(dstlst, srclst->head->data);
    del_first(srclst);
}

void    rotate_lst(t_lst *lst)
{
    if (lst->head == NULL)
        return ;
    if (lst->head == lst->tail)
        return ;
    add_last(lst, lst->head->data);
    del_first(lst);
}

void    rrotate_lst(t_lst *lst)
{
    if (lst->head == NULL)
        return ;
    if (lst->head == lst->tail)
        return ;
    add_first(lst, lst->tail->data);
    del_last(lst);
}