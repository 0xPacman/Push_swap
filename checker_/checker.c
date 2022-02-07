#include "../push_swap.h"

void ft_checker(t_list **stack_a, int n)
{
    t_list *stack_b;
    char *read;

    stack_b = NULL;
    
}

void ft_check_instra(t_list **stack_a, t_list **stack_b, char *read)
{
    if (!ft_strncmp(read, "sa"))
		verify_sa(stack_a);
	else if (!ft_strncmp(read, "sb"))
		verify_sb(stack_b);
	else if (!ft_strncmp(read, "ss"))
		verify_ss(stack_a, stack_b);
    else if (!ft_strcmp(read, "pa"))
		verify_pa(stack_a, stack_b);
	else if (!ft_strncmp(read, "pb"))
		verify_pb(stack_a, stack_b);
	else if (!ft_strncmp(read, "ra"))
		verify_ra(stack_a);
	else if (!ft_strncmp(read, "rb"))
		verify_rb(stack_b);
	else if (!ft_strncmp(read, "rr"))
		verify_rr(stack_a, stack_b);
	else if (!ft_strncmp(read, "rra"))
		verify_rra(stack_a);
	else if (!ft_strncmp(read, "rrb"))
		verify_rrb(stack_b);
	else if (!ft_strncmp(read, "rrr"))
		verify_rrr(stack_a, stack_b);
	else
        ft_error_handler();
}

int main(int argc, char **argv)
{
    t_data *data = malloc(sizeof(t_data));
    t_list *stack_a;
    if (argc >= 2)
        {
            data->str = ft_addstr(argv);
            data->arg = ft_split(data->str, ' ', data);
            ft_is_duplicate(data->arg);
            stack_a = stack_creator(data->arg);


        }
}