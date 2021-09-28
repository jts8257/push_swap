/** Error 케이스
 * int 범위를 넘는 숫자가 들어옴
 * int 가 아닌 인자가 들어옴
 * 인자가 안들어옴
 * 중복되는 int 가 들어옴
 **/

#include "push_swap.h"

long	ft_swap_atoi(const char *str)
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
	return (sol);
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

int main(int argc, char **argv)
{
    int cnt;
    t_list *lst;

    if (argc < 2) // 인자가 제대로 안들어오면 error
        error_handle("Error:Argument Count Not Matched(argc > 1)");
    cnt = 1;
    lst = ft_lstnew(ft_swap_atoi(argv[cnt++]));
    while (cnt < argc)
        ft_lstadd_back(&lst, ft_lstnew(ft_swap_atoi(argv[cnt++])));
    ft_lstiter(lst, print_num);// 제대로 값이 들어간것 확인
    write(1, "\n", 1);
    check_duplicate(&lst);// 중복값 확인
}