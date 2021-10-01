#include "push_swap.h"

t_lst   *init_lst(void)
{
    t_lst *lst;
    
    lst = (t_lst *)malloc(sizeof(t_lst));
    if (lst == NULL)
        error_handle("Error:Malloc Error");
    lst->head = NULL;
    lst->tail = NULL;

    return lst;
}

void    add_first(t_lst *lst, int data)
{
    t_node *tmp;
    
    tmp = (t_node *)malloc(sizeof(t_node));
    if (tmp == NULL)
        error_handle("Error:Malloc Error");
    tmp->data = data;
    if (lst->head == NULL)
    {
        lst->head = tmp;
        lst->tail = tmp;
        tmp->next = tmp;
        tmp->prev = tmp;
    }
    else
    {
        tmp->next = lst->head;
        lst->head->prev = tmp;
        tmp->prev = lst->tail;
        lst->tail->next = tmp;
        lst->head = tmp;
    }
    lst->size++;
}

void    add_last(t_lst *lst, int data)
{
     t_node *tmp;
    
    tmp = (t_node *)malloc(sizeof(t_node));
    if (tmp == NULL)
        error_handle("Error:Malloc Error");
    tmp->data = data;
     if (lst->head == NULL)
    {
        lst->head = tmp;
        lst->tail = tmp;
        tmp->next = tmp;
        tmp->prev = tmp;
    }
    else
    {
        tmp->next = lst->head;
        lst->head->prev = tmp;
        tmp->prev = lst->tail;
        lst->tail->next = tmp;
        lst->tail = tmp;
    }
}

void    del_first(t_lst *lst)
{
    t_node *curr;
    t_node *tmp;

    curr = lst->head;
    if (curr == NULL)
        return ;
    if (curr == lst->tail)
    {
        free(curr);
        curr = NULL;
        return ;
    }
    tmp = lst->head->next;
    tmp->prev = lst->tail;
    lst->tail->next = tmp;
    free(curr);
    curr = NULL;
    lst->head = tmp;
    lst->size--;
}

void    del_last(t_lst *lst)
{
    t_node *curr;
    t_node *tmp;

    curr = lst->tail;
    if (curr == NULL)
        return ;
    if (curr == lst->head)
    {
        free(curr);
        curr = NULL;
        return ;
    }
    tmp = lst->tail->prev;
    tmp->next = lst->head;
    lst->head->prev = tmp;
    free(curr);
    curr = NULL;
    lst->tail = tmp;
    lst->size--;

}

void    iter_lst(t_lst *lst, void (*f)(int))
{
    t_node *curr;
    int len;

    if (lst->head == NULL)
        return ;
    len = 0;
    while (len < lst->size)
    {
        f(curr->data);
        curr = curr->next;
    }
}