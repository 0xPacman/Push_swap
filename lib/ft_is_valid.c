/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:00:44 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 15:01:05 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

void	ft_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((ft_is_sign(str[i]) && ft_isdigit(str[i + 1])))
			i++;
		if (!ft_isdigit(str[i]))
			ft_error_handler();
		if (ft_isdigit(str[i]) && (ft_is_sign(str[i + 1])
				&& ft_isdigit(str[i + 2])))
			ft_error_handler();
		i++;
	}
}
