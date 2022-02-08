#include "../push_swap.h"

void verify_sa(t_list **stack)
{
    t_list *temp;

    if((*stack) && (*stack)->next)
    {
        temp = *stack;
        *stack = (*stack)->next;
        temp->next = (*stack)->next;
        (*stack)->next = temp;
    }
}

void verify_sb(t_list **stack)
{
    t_list *temp;

    if((*stack) && (*stack)->next)
    {
        temp = *stack;
        *stack = (*stack)->next;
        temp->next = (*stack)->next;
        (*stack)->next = temp;
    }
}

void verify_ss(t_list **stack_a, t_list **stack_b)
{
    t_list *temp;

    if((*stack_a) && (*stack_a)->next)
    {
        temp = *stack_a;
        *stack_a = (*stack_a)->next;
        temp->next = (*stack_a)->next;
        (*stack_a)->next = temp;
    }
    if((*stack_b) && (*stack_b)->next)
    {
        temp = *stack_b;
        *stack_b = (*stack_b)->next;
        temp->next = (*stack_b)->next;
        (*stack_b)->next = temp;
    }
}
