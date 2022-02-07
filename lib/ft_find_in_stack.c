#include "../push_swap.h"

int ft_find_in_stack(t_list **stack, t_list *to_find)
{
    t_list *lst;
    int i;

    i = 0;
    lst = *stack;
    while(lst != to_find)
    {
		i++;
        lst = lst->next;
    }
    return (i);
}