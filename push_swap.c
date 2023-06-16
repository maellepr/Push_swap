#include "push_swap.h"

/*
Renvoie 1 si liste triee
Renvoie 0 si liste n'est pas triee
*/
int	is_sort(t_stack **stack)
{
	t_stack	*temp_s;

	temp_s = (*stack);
	while(temp_s->next != NULL)
	{
		if (temp_s->value > temp_s->next->value)
			return (0);
		temp_s = temp_s->next;
	}
	return (1);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size_sa;

	size_sa = ft_lstsize(*stack_a);
	if (size_sa == 2 && !(is_sort(stack_a)))// dans le cas u il y a deux nb
		write_sa(stack_a);
	else if (size_sa == 3 )
	{

	}
	else if (size_sa <= 10 && !(is_sort(stack_a)))
	{
		
	}
	else if (size_sa > 10 && !(is_sort(stack_a)))
	{
		printf("min de la pile a = %d\n", get_min(stack_a));
	}
}