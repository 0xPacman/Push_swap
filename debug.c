/* ************************************************************************** */
/* FOR DEBUGING */
/* ************************************************************************** */



void dubug(t_list **stack_a, char c)
{
	t_list *temp1;
	temp1 = *stack_a;
	while (temp1)
	{
		//printf("stack %c [%d]\n", c ,temp1->nb);
		temp1 = temp1->next;
	}

}