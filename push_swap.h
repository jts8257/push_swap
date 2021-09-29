#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

int     ft_swap_atoi(const char *str);
void    print_msg(char *str, int fd);
void	print_num(int num);
void    error_handle(char *str);

typedef struct		s_list
{
	int			    num;
	int				is_injected;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstnew(int num, int injected);
void		ft_lstadd_front(t_list **lst, t_list *newlst);
int		    ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *newlst);
void		ft_lstiter(t_list *lst, void (*f)(int));
void        check_duplicate(t_list **lst);
void		ft_delfirst(t_list **lst);
void        make_lst(int argc, char **argv, t_list **a_lst, t_list ** b_lst);

void		ft_delhead(t_list **lst);
void		ft_copy_top_to_botoom(t_list **lst);
void		ft_dellast(t_list **lst);
void		ft_copy_bottom_to_top(t_list **lst);

void    	swaplst(t_list **lst);
void    	swapall(t_list **a_lst, t_list **blst);
void    	push(t_list **srclst, t_list **destlst);
void    	rotate(t_list **lst);
void    	rotateall(t_list **a_lst, t_list **b_lst);
void	    rrotate(t_list **lst);
#endif