/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahjadani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:08:40 by ahjadani          #+#    #+#             */
/*   Updated: 2022/01/17 14:08:46 by ahjadani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int main(int argc, char *argv[])
{
    static t_data data;
    t_list *stack_a;
    t_list *stack_b;
    stack_a = NULL;
    stack_b = NULL;
    int *sorted;

    if (argc >= 2)
        {
            data.str = ft_addstr(argv);
            data.arg = ft_split(data.str, ' ', &data);
            ft_is_duplicate(data.arg);
            stack_a = stack_creator(data.arg);
            sorted = sort_args(data.arg, data.count);
            if (check_if_sorted(sorted, &stack_a, data.count))
                exit (0);
            ft_get_index(stack_a, sorted, data.count);
            ft_sort(&stack_a, &stack_b, data.count);
        }
    exit(1);
}
