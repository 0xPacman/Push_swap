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
void verify_ra(t_list **stack)
{
    t_list *temp;
    
    if((*stack) && (*stack)->next)
    {
        temp = *stack;
        *stack = temp->next;
        temp->next = NULL;
        ft_lstadd_back(stack, temp);
    }
}
void verify_rb(t_list **stack)
{
    t_list *temp;
    
    if((*stack) && (*stack)->next)
    {
        temp = *stack;
        *stack = temp->next;
        temp->next = NULL;
        ft_lstadd_back(stack, temp);
    }
}
void verify_rr(t_list **stack_a, t_list **stack_b)
{
    t_list *temp;

    if((*stack_a) && (*stack_a)->next)
    {
        temp = *stack_a;
        *stack_a = temp->next;
        temp->next = NULL;
        ft_lstadd_back(stack_a, temp);
    }
    if((*stack_b) && (*stack_b)->next)
    {
        temp = *stack_b;
        *stack_b = temp->next;
        temp->next = NULL;
        ft_lstadd_back(stack_b, temp);
    }
}
void verify_rra(t_list **stack)
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
    }
}
void verify_rrb(t_list **stack)
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
    }
}

void verify_rrr(t_list **stack_a, t_list **stack_b)
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
}

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

