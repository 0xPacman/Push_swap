#include "../push_swap.h"

void ft_get_index(t_list *stack, int *sorted, int n)
{
    int i;
    t_list *lst;

    lst = stack;
    while (lst)
    {
        i = 0;
        while(i < n)
        {
            if (lst->nb == sorted[i])
                lst->index = i;
            i++;
        }
        lst = lst->next;
    }
}