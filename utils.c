#include "push_swap.h"

int	ft_swap_atoi(const char *str)
{
	long	sol;
	int		min;
	char	*tmp;

	tmp = (char *)str;
	sol = 0;
	min = 1;
	if (*tmp == '-')
	{
		min = -1;
		tmp++;
	}
	while (*tmp)
	{
        if (*tmp < '0' || *tmp > '9') // 숫자가 아니면 error
            error_handle("Error:Not a Number");
		sol = (sol * 10) + (min * (*tmp - '0'));
		tmp++;
	}
    if (sol < -2147483648 || sol > 2147483647) // int 범위를 넘어서는 숫자면 error
        error_handle("Error:out of int range");
	return ((int)sol);
}

void print_msg(char *str, int fd)
{
    int len;

    len = 0;
    while (str[len])
        len++;
    write(fd, str, len);
    write(fd,"\n", 1);
}

void	print_num(int num)
{
	char	tmp;

	if (num / 10)
		print_num(num / 10);
	num %= 10;
	tmp = num + '0';
	write(1, &tmp, 1);
}

void error_handle(char *str)
{
    print_msg(str, 2);
    exit(1);
}

void check_duplicate(t_list **lst)
{
    t_list  *tmp;
    t_list  *curr;
    int std_num;

    tmp = *lst;
    while (tmp)
    {
        std_num = tmp->num;
        curr = tmp->next;
        while (curr)
        {
            if (curr->num == std_num)
                error_handle("Error:Duplicated Number");
            curr = curr->next;
        }
        tmp = tmp->next;
    }
}

void make_lst(int argc, char **argv, t_list **a_lst, t_list ** b_lst)
{
    int cnt;

    cnt = 1;
    *a_lst = ft_lstnew(ft_swap_atoi(argv[cnt++]), 1);
    *b_lst = ft_lstnew(0, 0); // int 형에 null 을 넣을 수 없음. pointer 에 null 을 넣을 수 있을것임.
    while (cnt < argc)
    {
        ft_lstadd_back(a_lst, ft_lstnew(ft_swap_atoi(argv[cnt++]), 1));
        ft_lstadd_back(b_lst, ft_lstnew(0, 0));
    }
}