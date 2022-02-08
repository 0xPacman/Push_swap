/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:40:30 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 16:48:03 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_get_index(t_list *stack, int *sorted, int n)
{
	int		i;
	t_list	*lst;

	lst = stack;
	while (lst)
	{
		i = 0;
		while (i < n)
		{
			if (lst->nb == sorted[i])
				lst->index = i;
			i++;
		}
		lst = lst->next;
	}
}
