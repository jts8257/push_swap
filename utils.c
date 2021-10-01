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
	write(1, " ", 1);
}

void error_handle(char *str)
{
    print_msg(str, 2);
    exit(1);
}