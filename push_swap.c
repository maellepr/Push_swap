#include "push_swap.h"

/*
Renvoie 1 si liste triee
Renvoie 0 si liste n'est pas triee
*/
int	is_sort(t_stack *stack)
{
	while(stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	size_sa;

	size_sa = ft_lstsize(stack_a);
	if (size_sa == 2 && !is_sort(stack_a))// dans le cas u il y a deux nb
	{
		write_sa(stack_a);
	}
}