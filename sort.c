/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:10:43 by ahjadani          #+#    #+#             */
/*   Updated: 2022/01/17 14:11:06 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_get_index(t_list *stack, int *sorted, int n)
{
    int i;
    t_list *lst;

    lst = stack;
    while (lst)
    {
        i = 0;
        while(i < n)
        {
            printf("nb %d - sorted %d\n", lst->nb, sorted[i]);
            if (lst->nb == sorted[i])
            {
                printf("nb: %d is in index:%d\n",lst->nb,i);
                lst->index = i;
            }
            i++;
        }
        lst = lst->next;
    }
}
void ft_sort_2(t_list **stack)
{
    if ((*stack)->nb > (*stack)->nb)
        ra(stack);
}

void ft_sort_3(t_list **stack)
{
    if ((*stack)->nb < (*stack)->next->nb 
    && (*stack)->nb < (*stack)->next->next->nb 
    && (*stack)->next->nb > (*stack)->next->next->nb)
        {
            rra(stack);
            sa(stack);
        }
    if ((*stack)->nb > (*stack)->next->nb 
    && (*stack)->nb > (*stack)->next->next->nb 
    && (*stack)->next->nb > (*stack)->next->next->nb)
    {
        sa(stack);
        rra(stack);
    }
    if ((*stack)->nb < (*stack)->next->nb 
    && (*stack)->nb > (*stack)->next->next->nb 
    && (*stack)->next->nb > (*stack)->next->next->nb)
        rra(stack);
}

void ft_sort_all(t_list **stack_a, t_list **stack_b)
{
    
}

void ft_sort(t_list **stack_a, t_list **stack_b , int *sorted, int n)
{
    (void)sorted;
    (void)n;
    //sa(stack);
    //ra(stack);
    // rra(stack_a);
    // pb(stack_a, stack_b);
    // pb(stack_a, stack_b);
    // rr(stack_a, stack_b);
    if (n == 2)
        ft_sort_2(stack_a);
    if (n == 3)
        ft_sort_3(stack_a);
    if (n >= 4)
        ft_sort_all()
}