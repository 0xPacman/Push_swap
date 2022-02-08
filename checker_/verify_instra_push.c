#include "../push_swap.h"

void verify_pb(t_list **stack_a, t_list **stack_b)
{
    t_list *temp;
    t_list *first;

    if (*stack_a)
    {
        temp = (*stack_a)->next;
        first = *stack_a;
        first->next = NULL;
        ft_lstadd_front(stack_b,first);
        *stack_a = temp;
    }
}

void verify_pa(t_list **stack_a, t_list **stack_b)
{
    t_list *temp;
    t_list *first;

    if (*stack_b)
    {
        temp = (*stack_b)->next;
        first = *stack_b;
        first->next = NULL;
        ft_lstadd_front(stack_a,first);
        *stack_b = temp;
    }
}

