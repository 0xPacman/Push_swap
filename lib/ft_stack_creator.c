#include "../push_swap.h"

t_list *stack_creator(char **str)
{
    int i;
    t_list *node;

    i = 0;
    node = 0;
    while(str[i])
    {
        ft_lstadd_back(&node, ft_lstnew(ft_atoi(str[i])));
        i++;
    }
    return (node);
}
