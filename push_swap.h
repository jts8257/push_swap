#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

long	ft_swap_atoi(const char *str);
void print_msg(char *str, int fd);
void error_handle(char *str);

typedef struct		s_list
{
	int			    num;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstnew(int num);
void		ft_lstadd_front(t_list **lst, t_list *newlst);
int		    ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *newlst);
void		ft_lstiter(t_list *lst, void (*f)(int));
#endif