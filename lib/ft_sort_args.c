/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:49:22 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 16:49:51 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*sort_args(char **str, int n)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * n);
	if (!tab)
		ft_error_handler();
	while (i < n)
	{
		tab[i] = ft_atoi(str[i]);
		i++;
	}
	ft_bubble_sort(tab, n);
	return (tab);
}
