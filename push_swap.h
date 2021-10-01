#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

int ft_swap_atoi(const char *str);
void    print_msg(char *str, int fd);
void    print_num(int num);
void    error_handle(char *str);

typedef struct		s_node
{
    struct s_node	*next;
    struct s_node	*prev;
	int			    data;
}					t_node;

typedef struct		s_lst
{
    t_node  *head;
    t_node  *tail;
	int     size;
}					t_lst;

t_lst   *init_lst(void);
void    add_first(t_lst *lst, int data);
void    add_last(t_lst *lst, int data);
void    del_first(t_lst *lst);
void    del_last(t_lst *lst);
void    lst_iter(t_lst *lst, void (*f)(int));

#endif