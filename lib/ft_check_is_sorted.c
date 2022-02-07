#include "../push_swap.h"

int check_if_sorted(int *sorted, t_list **stack, int n)
{
    int i;
    t_list *lst;

    i = 0;
    lst = *stack;
    while (i < n && lst)
    {
        if(lst->nb != sorted[i])
            return (0);
        i++;
        lst = lst->next;
    }
    return (1);
}