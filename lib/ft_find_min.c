#include "../push_swap.h"

t_list *ft_find_min(t_list **stack)
{
    t_list *min;
    t_list *lst;

    min = *stack;
    lst = *stack;
    while(lst)
    {
        if(min->nb > lst->nb)
            min = lst;
        lst = lst->next;
    }
    return (min);
}