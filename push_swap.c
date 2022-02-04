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

void    ft_error_handler(void)
{
    write(2,"Error\n",7);
    exit(1);
}

t_list *stack_creator(char **str)
{
    int i;
    t_list *node;

    i = 0;
    node = 0;
    while(str[i])
    {
        ft_lstadd_back(&node, ft_lstnew(ft_atoi(str[i])));
        i++;
    }
    return (node);
}

void swap(int *x, int *y)
{
    int temp = 0;
    temp = *x;
    *x = *y;
    *y = temp;
}

void ft_bubble_sort(int tab[], int n)
{
   int i;
   int j;
   i = 0;
   while (i < n-1)
    {
        j = 0;
        while (j < n-i-1)
        {
            if (tab[j] > tab[j+1])
                swap(&tab[j], &tab[j+1]);
            j++;
        }
    i++;
    }
}

int *sort_args(char **str, int n)
{
    int *tab;
    int i;

    i = 0;
    tab = malloc(sizeof(int) * n);
    if (!tab)
        ft_error_handler();
    while(i < n)
    {
        //printf("atoi:%d\n",ft_atoi(str[i]));
        tab[i] = ft_atoi(str[i]);
        i++;
    }
    tab[i] = '\0';
    ft_bubble_sort(tab, n);
    return (tab);
}
char *ft_addstr(char **str)
{
    char *args;
    int i;
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

void ft_is_valid(char *str)
{
    int i;
    i = 0;
    while(str[i])
    {
        if(((str[i] == '-' || str[i] == '+')&& ft_isdigit(str[i+1])))
            i++;
        if(!ft_isdigit(str[i]))
            ft_error_handler();
        i++;
    }
}

void ft_is_duplicate(char **str)
{
    int i;
    int args;
    int j;

    j = 0;
    i = 0;
    args = 0;
    while(str[args])
    {
        ft_is_valid(str[args]);
        args++;
    }
    while (i < args)
        {
            j = i + 1;
            while (j < args)
                {
                    //printf("%s vs %s\n", str[i], str[j]);
                    if(!ft_strcmp(str[i], str[j]))
                        ft_error_handler();
                    j++;
                }
            i++;
        }
}

void check_if_sorted(int *sorted, t_list **stack, int n)
{
    int i;
    t_list *lst;

    i = 0;
    lst = *stack;
    while (i < n && lst)
    {
        if(lst->nb != sorted[i])
            return ;
        i++;
        lst = lst->next;
    }
    exit(0);

}

int main(int argc, char *argv[])
{
    t_data *data = malloc(sizeof(t_data));
    t_list *stack_a;
    t_list *stack_b;
    int *sorted;

    if (argc >= 2)
        {
            data->str = ft_addstr(argv);
            data->arg = ft_split(data->str, ' ', data);
            ft_is_duplicate(data->arg);
            stack_a = stack_creator(data->arg);
            sorted = sort_args(data->arg, data->count);
            check_if_sorted(sorted, &stack_a, data->count);
            ft_get_index(stack_a, sorted, data->count);
			// while(stack_a)
            // {
            //     printf("-Stack A:[%d] | index %d\n", stack_a->nb, stack_a->index);
            //     stack_a = stack_a->next;
            // }
            ft_sort(&stack_a, &stack_b, data->count);
           
    //         ft_get_index(stack_a, sorted, data->count);
           // printf("the index: %d\nthe number: %d\n", stack_a->index,stack_a->nb);
            // while(stack_a)
            // {
            //     printf("-Stack A :[%d]\n", stack_a->nb);
            //     stack_a = stack_a->next;
            // }
            // printf("\n========================\n");
            // while(stack_b)
            // {
            //     printf("-Stack B :[%d]\n", stack_b->nb);
            //     stack_b = stack_b->next;
            // }
        }
    exit(1);
}
