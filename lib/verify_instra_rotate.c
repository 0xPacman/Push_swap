/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_instra_rotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:24:17 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 16:24:57 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	verify_ra(t_list **stack)
{
	t_list	*temp;

	if ((*stack) && (*stack)->next)
	{
		temp = *stack;
		*stack = temp->next;
		temp->next = NULL;
		ft_lstadd_back(stack, temp);
	}
}

void	verify_rb(t_list **stack)
{
	t_list	*temp;

	if ((*stack) && (*stack)->next)
	{
		temp = *stack;
		*stack = temp->next;
		temp->next = NULL;
		ft_lstadd_back(stack, temp);
	}
}

void	verify_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	if ((*stack_a) && (*stack_a)->next)
	{
		temp = *stack_a;
		*stack_a = temp->next;
		temp->next = NULL;
		ft_lstadd_back(stack_a, temp);
	}
	if ((*stack_b) && (*stack_b)->next)
	{
		temp = *stack_b;
		*stack_b = temp->next;
		temp->next = NULL;
		ft_lstadd_back(stack_b, temp);
	}
}
