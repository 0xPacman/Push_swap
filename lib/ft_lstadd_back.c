/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:58:23 by ahjadani          #+#    #+#             */
/*   Updated: 2021/11/12 00:31:08 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *newlst)
{
	t_list	*head;

	if (!*lst)
		*lst = newlst;
	else
	{
		head = *lst;
		while (head->next)
			head = head->next;
		head->next = newlst;
	}
}
