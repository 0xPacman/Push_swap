#include "push_swap.h"
void dubug(t_list **stack_a, char c)
{
	t_list *temp1;
	t_list *temp2;
	temp1 = *stack_a;
	while (temp1)
	{
		//printf("stack %c [%d]\n", c ,temp1->nb);
		temp1 = temp1->next;
	}

}
void sa(t_list **stack)
{
    t_list *temp;

    if((*stack) && (*stack)->next)
    {
        temp = *stack;
        *stack = (*stack)->next;
        temp->next = (*stack)->next;
        (*stack)->next = temp;
        write(1, "sa\n", 3);
	 dubug(stack, 'A');
    }
}

void sb(t_list **stack)
{
    t_list *temp;

    if((*stack) && (*stack)->next)
    {
        temp = *stack;
        *stack = (*stack)->next;
        temp->next = (*stack)->next;
        (*stack)->next = temp;
        write(1, "sb\n", 3);
	 dubug(stack, 'B');
    }
}
void ss(t_list **stack_a, t_list **stack_b)
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
    write(1, "ss\n", 3);
    dubug(stack_a, 'A');
    dubug(stack_b, 'B');
}
void ra(t_list **stack)
{
    t_list *temp;
    
    if((*stack) && (*stack)->next)
    {
        temp = *stack;
        *stack = temp->next;
        temp->next = NULL;
        ft_lstadd_back(stack, temp);
        write(1, "ra\n", 3);
	 dubug(stack, 'A');
    }
}
void rb(t_list **stack)
{
    t_list *temp;
    
    if((*stack) && (*stack)->next)
    {
        temp = *stack;
        *stack = temp->next;
        temp->next = NULL;
        ft_lstadd_back(stack, temp);
        write(1, "rb\n", 3);
	 dubug(stack, 'B');
    }
	
}
void rr(t_list **stack_a, t_list **stack_b)
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
    write(1, "rr\n", 3);
	dubug(stack_a, 'A');
	dubug(stack_b, 'B');
}
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
	dubug(stack, 'A');
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
	dubug(stack, 'B');
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
	dubug(stack_a, 'A');
	dubug(stack_b, 'B');
}

void pb(t_list **stack_a, t_list **stack_b)
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
        write(1 ,"pb\n", 3);
	dubug(stack_a, 'A');
	dubug(stack_b, 'B');
    }
}

void pa(t_list **stack_a, t_list **stack_b)
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
        write(1 ,"pa\n", 3);
	dubug(stack_a, 'A');
	dubug(stack_b, 'B');
    }
}

