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

void ft_get_index(t_list *stack, int *sorted, int n)
{
    int i;
    t_list *lst;

    lst = stack;
    while (lst)
    {
        i = 0;
        while(i < n)
        {
            if (lst->nb == sorted[i])
            {
                lst->index = i;
            }
            i++;
        }
        lst = lst->next;
    }
}
void ft_sort_2(t_list **stack)
{
    if ((*stack)->nb > (*stack)->next->nb)
        ra(stack);
}

void ft_sort_3(t_list **stack)
{
    if ((*stack)->nb < (*stack)->next->nb 
    && (*stack)->nb < (*stack)->next->next->nb 
    && (*stack)->next->nb > (*stack)->next->next->nb)
        {
            rra(stack);
            sa(stack);
        }
    else if ((*stack)->nb > (*stack)->next->nb 
    && (*stack)->nb > (*stack)->next->next->nb 
    && (*stack)->next->nb > (*stack)->next->next->nb)
    {
        sa(stack);
        rra(stack);
    }
    else if ((*stack)->nb < (*stack)->next->nb 
    && (*stack)->nb > (*stack)->next->next->nb 
    && (*stack)->next->nb > (*stack)->next->next->nb)
        rra(stack);
    else if ((*stack)->nb > (*stack)->next->nb 
    && (*stack)->nb < (*stack)->next->next->nb 
    && (*stack)->next->nb < (*stack)->next->next->nb)
        sa(stack);
    else if ((*stack)->nb > (*stack)->next->nb 
    && (*stack)->nb > (*stack)->next->next->nb 
    && (*stack)->next->nb < (*stack)->next->next->nb)
        ra(stack);
}

void ft_sort_4(t_list **stack_a, t_list **stack_b)
{
    t_list *min;

    min = ft_find_min(stack_a);
    while (ft_lstsize(stack_a) > 3)
    {
        if (!ft_find_in_stack(stack_a, min))
            pb(stack_a, stack_b);
        else if(ft_find_in_stack(stack_a, min) == 1)
            ra(stack_a);
        else
            rra(stack_a);
    }
    ft_sort_3(stack_a);
    while(ft_lstsize(stack_b) > 0)
        pa(stack_a, stack_b);
}

void ft_sort_5(t_list **stack_a, t_list **stack_b)
{
    t_list *min;

    min = ft_find_min(stack_a);
    while (ft_lstsize(stack_a) > 4)
    {
        if (!ft_find_in_stack(stack_a, min))
            pb(stack_a, stack_b);
        else if(ft_find_in_stack(stack_a, min) == 1)
            ra(stack_a);
        else
            rra(stack_a);
    }
    ft_sort_4(stack_a, stack_b);
    while(ft_lstsize(stack_b) > 0)
        pa(stack_a, stack_b);
}

void ft_sort_min(t_list **stack_a, t_list **stack_b, t_data *data)
{
    if((*stack_a)->index == data->min)
    {
        (*stack_a)->flag = -42;
        ra(stack_a);
        data->min++;
    }
    else if (ft_lstsize(stack_b) > 0 && (*stack_b)->index == data->min)
        pa(stack_a, stack_b);
    else if (ft_lstsize(stack_b) > 1 && (*stack_a)->next->index == data->min && ft_lstlast(*stack_a)->index == data->min + 1)
        ss(stack_a, stack_b);
    else if (ft_lstsize(stack_b) > 2 && ft_lstlast(*stack_b)->index == data->min)
         rrb(stack_b);
    else if ((*stack_a)->next->index == data->min)
        sa(stack_a);
    else
        return ;
    ft_sort_min(stack_a, stack_b, data);
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
    
    //printf("end push a\n");
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
	} //printf("end\n");
	data->max = data->mid;
	data->mid = data->max / 2;
	data->flag = 1;
}
void ft_sort_all(t_list **stack_a, t_list **stack_b, int n)
{
    t_data data;

	data.flag = 0;
    data.min = ft_find_min(stack_a)->index;
    data.max = ft_find_max(stack_a)->index;
    data.mid = data.max / 2;
    
    start_sorting(stack_a, stack_b, &data);
	
    while(ft_check_stack(stack_a, n))
    {
        if(!ft_lstsize(stack_b))
        {
			ft_push_b(stack_a, stack_b, &data);
        }
        else
        { 
            ft_push_a(stack_a, stack_b, &data);
        }
	
    }
}
void ft_sort(t_list **stack_a, t_list **stack_b , int n)
{
    if (n == 2)
        ft_sort_2(stack_a);
    else if (n == 3)
        ft_sort_3(stack_a);
    else if (n == 4)
        ft_sort_4(stack_a, stack_b);
    else if (n == 5)
        ft_sort_5(stack_a, stack_b);
    else
        ft_sort_all(stack_a, stack_b, n);
}
