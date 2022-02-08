/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:40:15 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 16:47:40 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_find_min(t_list **stack)
{
	t_list	*min;
	t_list	*lst;

	min = *stack;
	lst = *stack;
	while (lst)
	{
		if (min->nb > lst->nb)
			min = lst;
		lst = lst->next;
	}
	return (min);
}
