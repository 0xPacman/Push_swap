/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <ahjadani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:04:52 by ahjadani          #+#    #+#             */
/*   Updated: 2022/02/08 19:39:33 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (data->arg[i])
		free(data->arg[i++]);
	free(data->str);
	free(data->arg);
	free(data->sorted);
}
