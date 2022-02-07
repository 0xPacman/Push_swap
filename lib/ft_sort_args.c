#include "../push_swap.h"

int *sort_args(char **str, int n)
{
    int *tab;
    int i;

    i = 0;
	tab = malloc(sizeof(int) * n);
     if (!tab)
         ft_error_handler();
    while(i < n)
    {
        tab[i] = ft_atoi(str[i]);
        i++;
    }
    ft_bubble_sort(tab, n);
    return (tab);
}
