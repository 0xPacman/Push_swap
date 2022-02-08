/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:10:43 by ahjadani          #+#    #+#             */
/*   Updated: 2022/01/17 14:11:06 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_sort_min(t_list **stack_a, t_list **stack_b, t_data *data)
{	
	while(1)
	{
    	if((*stack_a)->index == data->min)
    	{
			(*stack_a)->flag = -42;
			ra(stack_a);
        	data->min++;
    	}
    	else if (ft_lstsize(stack_b) > 0 && (*stack_b)->index == data->min)
        	pa(stack_a, stack_b);
    	else if (ft_lstsize(stack_b) > 2 && ft_lstlast(*stack_b)->index == data->min)
        	rrb(stack_b);
    	else if ((*stack_a)->next->index == data->min)
        	sa(stack_a);
    	else
        	break ;
    }
}

void ft_push_a(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int i;
	i = 0;
    int size = ft_lstsize(stack_b);

    while (i < size && *stack_b)
    {
        if ((*stack_b)->index == data->min)
            ft_sort_min(stack_a, stack_b, data);
        else if ((*stack_b)->index >= data->mid)
        {
        	(*stack_b)->flag = data->flag;
            pa(stack_a, stack_b);
        }
        else
			rb(stack_b);
		i++;
    }
	data->max = data->mid;
    data->mid = (data->max - data->min) / 2 + data->min;
    data->flag++;
}

void ft_push_b(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int flag2;
	
	flag2 = (*stack_a)->flag;
    if ((*stack_a)->flag == 0)
    {
	    while ((*stack_a)->flag != -42)
        { 
    	    if ((*stack_a)->index != data->min)
        	    pb(stack_a, stack_b);
            ft_sort_min(stack_a, stack_b, data);
        }
    }
    else if ((*stack_a)->flag != 0)
    {
        while ((*stack_a)->flag == flag2)
        { 
    	    if ((*stack_a)->index != data->min)
        	    pb(stack_a, stack_b); 
            ft_sort_min(stack_a, stack_b, data);
        }
    }
    if (*stack_b)
    	data->max = ft_find_max(stack_b)->index;
    data->mid = (data->max - data->min) / 2 + data->min;
}

void start_sorting(t_list **stack_a, t_list **stack_b, t_data *data)
{
    int	size;
	int	i;

	size = ft_lstsize(stack_a);
	i = 0;
	while (i < size)
    {
		if ((*stack_a)->index <= data->mid)
			pb(stack_a, stack_b);
		else
		{
			if (ft_lstsize(stack_b) > 1 && (*stack_b)->index < (data->mid / 2))
				rr(stack_a, stack_b);
			else
                ra(stack_a);
		}
        i++;
	}
	data->max = data->mid;
	data->mid = data->max / 2;
}

void ft_sort_all(t_list **stack_a, t_list **stack_b, int n)
{
    t_data data;

	
    data.min = ft_find_min(stack_a)->index;
    data.max = ft_find_max(stack_a)->index;
    data.mid = data.max / 2;
	data.flag = 1;
	(*stack_a)->flag = 0;
    start_sorting(stack_a, stack_b, &data);
    while(ft_check_stack(stack_a, n))
    {
        if(!ft_lstsize(stack_b))
			ft_push_b(stack_a, stack_b, &data);
        else
            ft_push_a(stack_a, stack_b, &data);
    }
}
