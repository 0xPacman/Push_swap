/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:59:55 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 16:22:50 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_lstsize(t_list **lst)
{
	t_list	*list;
	int		i;

	i = 0;
	list = *lst;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
