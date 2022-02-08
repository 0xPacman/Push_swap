/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instra_swap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:18:21 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 16:19:00 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_list **stack)
{
	t_list	*temp;

	if ((*stack) && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = (*stack)->next;
		(*stack)->next = temp;
		write(1, "sa\n", 3);
	}
}

void	sb(t_list **stack)
{
	t_list	*temp;

	if ((*stack) && (*stack)->next)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = (*stack)->next;
		(*stack)->next = temp;
		write(1, "sb\n", 3);
	}
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if ((*stack_a) && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = (*stack_a)->next;
		temp->next = (*stack_a)->next;
		(*stack_a)->next = temp;
	}
	if ((*stack_b) && (*stack_b)->next)
	{
		temp = *stack_b;
		*stack_b = (*stack_b)->next;
		temp->next = (*stack_b)->next;
		(*stack_b)->next = temp;
	}
	write(1, "ss\n", 3);
}
