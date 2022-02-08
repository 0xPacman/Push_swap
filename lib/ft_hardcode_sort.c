/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hardcode_sort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:41:25 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 14:41:55 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_2(t_list **stack)
{
	if ((*stack)->nb > (*stack)->next->nb)
		ra(stack);
}

void	ft_sort_3_part_2(t_list **stack)
{
	if ((*stack)->nb < (*stack)->next->nb
		&& (*stack)->nb > (*stack)->next->next->nb
		&& (*stack)->next->nb > (*stack)->next->next->nb)
		rra(stack);
	else if ((*stack)->nb > (*stack)->next->nb
		&& (*stack)->nb < (*stack)->next->next->nb
		&& (*stack)->next->nb < (*stack)->next->next->nb)
		sa(stack);
	else if ((*stack)->nb > (*stack)->next->nb
		&& (*stack)->nb > (*stack)->next->next->nb
		&& (*stack)->next->nb < (*stack)->next->next->nb)
		ra(stack);
}

void	ft_sort_3(t_list **stack)
{
	if ((*stack)->nb < (*stack)->next->nb
		&& (*stack)->nb < (*stack)->next->next->nb
		&& (*stack)->next->nb > (*stack)->next->next->nb)
	{
		rra(stack);
		sa(stack);
	}
	else if ((*stack)->nb > (*stack)->next->nb
		&& (*stack)->nb > (*stack)->next->next->nb
		&& (*stack)->next->nb > (*stack)->next->next->nb)
	{
		sa(stack);
		rra(stack);
	}
	else
		ft_sort_3_part_2(stack);
}

void	ft_sort_4(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;

	min = ft_find_min(stack_a);
	while (ft_lstsize(stack_a) > 3)
	{
		if (!ft_find_in_stack(stack_a, min))
			pb(stack_a, stack_b);
		else if (ft_find_in_stack(stack_a, min) == 1)
			ra(stack_a);
		else
			rra(stack_a);
	}
	ft_sort_3(stack_a);
	while (ft_lstsize(stack_b) > 0)
		pa(stack_a, stack_b);
}

void	ft_sort_5(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;

	min = ft_find_min(stack_a);
	while (ft_lstsize(stack_a) > 4)
	{
		if (!ft_find_in_stack(stack_a, min))
			pb(stack_a, stack_b);
		else if (ft_find_in_stack(stack_a, min) == 1)
			ra(stack_a);
		else
			rra(stack_a);
	}
	ft_sort_4(stack_a, stack_b);
	while (ft_lstsize(stack_b) > 0)
		pa(stack_a, stack_b);
}
