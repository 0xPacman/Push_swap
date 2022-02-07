#include "../push_swap.h"
#include "get_next_line.h"

void ft_checker(t_list **stack_a, int n)
{
    t_list *stack_b;
    char *read;

    stack_b = NULL;
    
}

void ft_check_instra(t_list **stack_a, t_list **stack_b, char *read)
{
	if (!ft_strcmp(read, "sa"))
		verify_sa(stack_a);
	else if (!ft_strcmp(read, "sb"))
		verify_sb(stack_b);
	else if (!ft_strcmp(read, "ss"))
		verify_ss(stack_a, stack_b);
	else if (!ft_strcmp(read, "pa"))
		verify_pa(stack_a, stack_b);
	else if (!ft_strcmp(read, "pb"))
		verify_pb(stack_a, stack_b);
	else if (!ft_strcmp(read, "ra"))
		verify_ra(stack_a);
	else if (!ft_strcmp(read, "rb"))
		verify_rb(stack_b);
	else if (!ft_strcmp(read, "rr"))
		verify_rr(stack_a, stack_b);
	else if (!ft_strcmp(read, "rra"))
		verify_rra(stack_a);
	else if (!ft_strcmp(read, "rrb"))
		verify_rrb(stack_b);
	else if (!ft_strcmp(read, "rrr"))
		verify_rrr(stack_a, stack_b);
	else
        ft_error_handler();
}

int main(int argc, char **argv)
{
    t_data *data = malloc(sizeof(t_data));
    t_list *stack_a;
	t_list *stack_b;
	char *read;
	int *sorted;
    if (argc >= 2)
        {
            data->str = ft_addstr(argv);
            data->arg = ft_split(data->str, ' ', data);
            ft_is_duplicate(data->arg);
            stack_a = stack_creator(data->arg);
			sorted = sort_args(data->arg, data->count);
			read = get_next_line(0);
			while (read && read[0] != '\n')
			{
				ft_check_instra(&stack_a, &stack_b, read);
				read = get_next_line(0);
			}
			if (check_if_sorted(sorted, &stack_a, data->count))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
        }
}