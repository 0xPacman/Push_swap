/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_in_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:39:34 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 14:39:45 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_in_stack(t_list **stack, t_list *to_find)
{
	t_list	*lst;
	int		i;

	i = 0;
	lst = *stack;
	while (lst != to_find)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
