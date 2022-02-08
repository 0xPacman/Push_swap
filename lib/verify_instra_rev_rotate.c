/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_instra_rev_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:23:00 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 16:24:07 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	verify_rra(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if ((*stack) && (*stack)->next)
	{
		temp = *stack;
		last = ft_lstlast(*stack);
		while (temp->next->next)
			temp = temp->next;
		temp->next = NULL;
		ft_lstadd_front(stack, last);
	}
}

void	verify_rrb(t_list **stack)
{
	t_list	*temp;
	t_list	*last;

	if ((*stack) && (*stack)->next)
	{
		temp = *stack;
		last = ft_lstlast(*stack);
		while (temp->next->next)
			temp = temp->next;
		temp->next = NULL;
		ft_lstadd_front(stack, last);
	}
}

void	verify_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;
	t_list	*last;

	if ((*stack_a) && (*stack_a)->next)
	{
		temp = *stack_a;
		last = ft_lstlast(*stack_a);
		while (temp->next->next)
			temp = temp->next;
		temp->next = NULL;
		ft_lstadd_front(stack_a, last);
	}
	if ((*stack_b) && (*stack_b)->next)
	{
		temp = *stack_b;
		last = ft_lstlast(*stack_b);
		while (temp->next->next)
			temp = temp->next;
		temp->next = NULL;
		ft_lstadd_front(stack_b, last);
	}
}
