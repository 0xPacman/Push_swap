#include "../push_swap.h"

t_list *ft_find_max(t_list **stack)
{
    t_list *max;
    t_list *lst;

    max = *stack;
    lst = *stack;
    while(lst)
    {
        if(max->nb < lst->nb)
            max = lst;
        lst = lst -> next;
    }
    return (max);
}