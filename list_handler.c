#include "push_swap.h"
#include <stdio.h>

t_list		*ft_lstnew(int num, int injected)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
    {
        error_handle("Error:Malloc Error");
        return (NULL);
    }
	lst->num = num;
	lst->is_injected = injected;
	lst->next = NULL;
	return (lst);
}

void		ft_lstadd_front(t_list **lst, t_list *newlst)
{
	newlst->next = *lst;
	*lst = newlst;
}

int		ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}

t_list		*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void		ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list *tmp;

	if (*lst == NULL)
	{
		*lst = newlst;
		return ;
	}
	tmp = *lst;
	tmp = ft_lstlast(tmp);
	tmp->next = newlst;
}

void		ft_lstiter(t_list *lst, void (*f)(int))
{
	t_list *curr;

	curr = lst;
	while (curr)
	{
		f(curr->num);
		curr = curr->next;
	}
}

void	ft_delhead(t_list **lst)
{
	t_list *link_lst;
	t_list *lest_lst;

	if ((*lst)->is_injected == 0)
		return ;
	link_lst = (*lst)->next;
	if (link_lst == NULL)
		link_lst = ft_lstnew(0,0);	
	lest_lst = *lst;
	free(lest_lst);
	*lst = link_lst;
}

void	ft_roatate_add_back(t_list **lst, t_list *newlst)
{
	t_list	*tmp;
	int		size;
	int		i;

	size= ft_lstsize(*lst);
	if (*lst == NULL)
	{
		*lst = newlst;
		return ;
	}
	tmp = *lst;
	while (tmp->next && tmp->next->is_injected == 1)
		tmp = tmp->next;
	tmp->next = newlst;
	i = 0;
	while (i < size - ft_lstsize(*lst) + 1)
		ft_lstadd_back(lst, ft_lstnew(0, 0));
}

void	ft_copy_top_to_botoom(t_list **lst)
{
	t_list *copied_lst;
	
	if ((*lst)->is_injected == 0)
		return ;
	copied_lst = ft_lstnew((*lst)->num, 1);
	ft_roatate_add_back(lst, copied_lst);
}

/**
 * 	t_list *link_lst;
	t_list *lest_lst;

	if ((*lst)->is_injected == 0)
		return ;
	link_lst = (*lst)->next;
	if (link_lst == NULL)
		link_lst = ft_lstnew(0,0);	
	lest_lst = *lst;
	free(lest_lst);
	*lst = link_lst;
 * */
void	ft_dellast(t_list **lst)
{
	t_list	*tmp;
	
	if ((*lst)->is_injected == 0)
		return ;
	tmp = *lst;
	while ((*lst)->next != NULL && (*lst)->is_injected == 1)
	{
		print_msg("while", 1);
		*lst = (*lst)->next;
	}
	// free(*lst);
	(*lst)->next = NULL;
}

void	ft_copy_bottom_to_top(t_list **lst)
{
	t_list	*copied_lst;
	t_list	*tmp;
	
	if ((*lst)->is_injected == 0)
		return ;
	tmp = *lst;
	while (tmp->next != NULL && tmp->next->is_injected == 1)
		tmp = tmp->next;
	copied_lst = ft_lstnew(tmp->num, 1);
	ft_lstadd_front(lst, copied_lst);
}