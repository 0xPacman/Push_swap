/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_creator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:50:08 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 16:50:23 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*stack_creator(char **str)
{
	int		i;
	t_list	*node;

	i = 0;
	node = 0;
	while (str[i])
	{
		ft_lstadd_back(&node, ft_lstnew(ft_atoi(str[i])));
		i++;
	}
	return (node);
}
