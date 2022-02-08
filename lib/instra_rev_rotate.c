#include "../push_swap.h"

void rra(t_list **stack)
{
    t_list *temp;
    t_list *last;

    if((*stack) && (*stack)->next)
    {
        temp = *stack;
        last = ft_lstlast(*stack);
        while (temp->next->next)
            temp = temp->next;
        temp->next = NULL;
        ft_lstadd_front(stack, last);
        write(1, "rra\n", 4);
    }
}

void rrb(t_list **stack)
{
    t_list *temp;
    t_list *last;

    if((*stack) && (*stack)->next)
    {
        temp = *stack;
        last = ft_lstlast(*stack);
        while (temp->next->next)
            temp = temp->next;
        temp->next = NULL;
        ft_lstadd_front(stack, last);
        write(1, "rrb\n", 4);
    }
}

void rrr(t_list **stack_a, t_list **stack_b)
{
    t_list *temp;
    t_list *last;

    if((*stack_a) && (*stack_a)->next)
    {
        temp = *stack_a;
        last = ft_lstlast(*stack_a);
        while (temp->next->next)
            temp = temp->next;
        temp->next = NULL;
        ft_lstadd_front(stack_a, last);
    }
    if((*stack_b) && (*stack_b)->next)
    {
        temp = *stack_b;
        last = ft_lstlast(*stack_b);
        while (temp->next->next)
            temp = temp->next;
        temp->next = NULL;
        ft_lstadd_front(stack_b, last);
    }
    write(1, "rrr\n", 4);
}
