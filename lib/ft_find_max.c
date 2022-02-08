/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:40:01 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 16:47:08 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_find_max(t_list **stack)
{
	t_list	*max;
	t_list	*lst;

	max = *stack;
	lst = *stack;
	while (lst)
	{
		if (max->nb < lst->nb)
			max = lst;
		lst = lst -> next;
	}
	return (max);
}
