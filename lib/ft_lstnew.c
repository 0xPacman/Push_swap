/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 21:36:05 by ahjadani          #+#    #+#             */
/*   Updated: 2021/11/12 13:54:46 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstnew(int nb)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	else
	 {
		 //printf("nb:%d\n", nb);
		 new->nb = nb;
		 new->index = 0;
		 //new->flag = 0;
		 new->next = NULL;
		 //new->prev = NULL;
	 }
	return (new);
}
