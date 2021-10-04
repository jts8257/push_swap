#include <stdlib.h>
#include <stdio.h>

int *sort(int *arr, int size);

int	ft_easy_atoi(const char *str)
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
		sol = (sol * 10) + (min * (*tmp - '0'));
		tmp++;
	}
	return ((int)sol);
}

int main(int argc, char **argv) {

    int *arr = (int *)malloc(sizeof(int) * argc);
    for (int i = 1 ; i < argc ; i++) {
        arr[i - 1] = ft_easy_atoi(argv[i]);
    }

    int *result = sort(arr, argc - 1);
    for (int i = 0; i < argc - 1 ; i++) {
        printf("%d ", result[i]);
    }
    exit (0);
}