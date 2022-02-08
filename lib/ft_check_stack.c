/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:38:58 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 14:39:04 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_check_stack(t_list **stack, int n)
{
	t_list	*lst;
	int		size;

	size = ft_lstsize(stack);
	if (n != size)
		return (1);
	lst = *stack;
	while (lst->next)
	{
		if (lst->index > lst->next->index)
			return (1);
		lst = lst->next;
	}
	return (0);
}
