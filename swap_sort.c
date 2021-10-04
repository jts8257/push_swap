#include "push_swap.h"


int *get_arr(t_lst* lst)
{
    int *cont;
    int i;
    
    if (lst->head == NULL)
        return NULL;
    cont = (int *)malloc(sizeof(int) * lst->size);
    if (cont == NULL)
        error_handle("Error:malloc Error");
    i = -1;
    while(++i < lst->size)
    {
        cont[i] = lst->data;
        lst = lst->next;
    }
    return cont;
}

int find_median(int *arr, int size)
{
  
}

int get_pivot(t_lst *lst)
{
    int *cont;

    cont = get_arr(lst);
    find_median(cont, lst->size);
}