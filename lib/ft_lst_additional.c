/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_additional.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:09:24 by ahjadani          #+#    #+#             */
/*   Updated: 2022/01/17 14:09:27 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list *ft_find_min(t_list **stack)
{
    t_list *min;
    t_list *lst;

    min = *stack;
    lst = *stack;
    while(lst)
    {
        if(min->nb > lst->nb)
            min = lst;
        lst = lst->next;
    }
    return (min);
}
t_list *ft_find_max(t_list **stack)
{
    t_list *max;
    t_list *lst;

    max = *stack;
    lst = *stack;
    while(lst)
    {
        if(max->nb < lst->nb)
            max = lst;
        lst = lst -> next;
    }
    return (max);
}
int ft_find_in_stack(t_list **stack, t_list *to_find)
{
    t_list *lst;
    int i;

    i = 0;
    lst = *stack;
    while(lst != to_find)
    {
		i++;
        lst = lst->next;
    }
    return (i);
}

int ft_check_stack(t_list **stack, int n)
{
	t_list *lst;
	int size;

	size = ft_lstsize(stack);
	if(n != size)
		return (1);
	lst = *stack;
	while (lst->next)
	{
		if (lst->index > lst->next->index)
			return (1);
		lst = lst->next;
	}
	return (0);
}
