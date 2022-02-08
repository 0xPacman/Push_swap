/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:37:29 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 14:37:36 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_addstr(char **str)
{
	char	*args;
	int		i;

	i = 1;
	args = 0;
	while (str[i])
	{
		if (!args)
		{
			args = ft_strdup(str[i]);
			i++;
		}
		else
		{
			args = ft_strjoin(args, " ");
			args = ft_strjoin(args, str[i]);
			i++;
		}
	}
	return (args);
}
