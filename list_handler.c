#include "push_swap.h"

t_list		*ft_lstnew(int num)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
    {
        error_handle("Error:Malloc Error");
        return (NULL);
    }
	lst->num = num;
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
