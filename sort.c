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
            //printf("nb %d - sorted %d\n", lst->nb, sorted[i]);
            if (lst->nb == sorted[i])
            {
                //printf("nb: %d is in index:%d\n",lst->nb,i);
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
    //printf("size:%d\n", ft_lstsize(stack_a));
    while (ft_lstsize(stack_a) > 3)
    {
        if (!ft_find_in_stack(stack_a, min))
            pb(stack_a, stack_b);
        else if(ft_find_in_stack(stack_a, min) == 1)
            ra(stack_a);
        else
            rra(stack_a);
    }
    //pb(stack_a, stack_b);
    ft_sort_3(stack_a);
    while(ft_lstsize(stack_b) > 0)
        pa(stack_a, stack_b);
}

void ft_sort_5(t_list **stack_a, t_list **stack_b)
{
    t_list *min;

    min = ft_find_min(stack_a);
    //printf("size:%d\n", ft_lstsize(stack_a));
    while (ft_lstsize(stack_a) > 4)
    {
        if (!ft_find_in_stack(stack_a, min))
            pb(stack_a, stack_b);
        else if(ft_find_in_stack(stack_a, min) == 1)
            ra(stack_a);
        else
            rra(stack_a);
    }
    //pb(stack_a, stack_b);
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
    else if (ft_lstsize(stack_b) > 2 && ft_lstlast(*stack_b)->index == data->min)
         rrb(stack_b);
    else if (ft_lstsize(stack_b) > 1 && (*stack_a)->next->index == data->min)
        ss(stack_a, stack_b);
    else if ((*stack_a)->next->index == data->min)
        sa(stack_a);
    else
        return ;
    ft_sort_min(stack_a, stack_b, data);
}

void ft_sort_all(t_list **stack_a, t_list **stack_b, int n)
{
    t_data *data;

    data = malloc(sizeof(t_data));
    if (!data)
        ft_error_handler();
    data->min = ft_find_min(stack_a)->index;
   // printf("min:%d\n",data->min);
    data->max = ft_find_max(stack_a)->index;
    data->mid = data->max / 2 + data->min;
    int i;

    i = 0;
    while (i < ft_lstsize(stack_a))
    {
        if ((*stack_a)->index <= data->mid)
            pb(stack_a, stack_b);
        else
        {
            if (ft_lstsize(stack_b) > 1 && (*stack_b)->index < (data->mid/2))//rotate to set the smallest down in the stack bb
                rb(stack_b);
            ra(stack_a);
        }
        i++;
    }
    data->max = data->mid;
    data->mid = (data->max - data->min) / 2 + data->min;
    data->flag = 1;
    int flag2 = 1;
    while(!ft_check_stack(stack_a, n))
    {
        //printf("1");
        if(!*stack_b) //if stack b is empty
        { //printf("flag: %d\n", (*stack_a)->flag);
            if((*stack_a)->flag == 0)
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
            data->min = (data->max - data->min) / 2 + data->min;
        }
        else //if stack b is not empty
        {
            i = 0;
            while (i < ft_lstsize(stack_b) && *stack_b)
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
		printf("%d\n%d\n%d\n", (*stack_a)->flag, (*stack_b)->flag,data->flag);
    }
//    printf("%d\n", data->mid);
}
void ft_sort(t_list **stack_a, t_list **stack_b , int n)
{
    //sa(stack);
    //ra(stack);
    // rra(stack_a);
    // pb(stack_a, stack_b);
    // pb(stack_a, stack_b);
    // rr(stack_a, stack_b);
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