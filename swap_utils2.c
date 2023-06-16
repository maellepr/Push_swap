#include "push_swap.h"

int	get_max(t_stack **stack)
{
	int		max;
	t_stack	*temp_s;

	temp_s = (*stack);
	max = temp_s->value;
	while(temp_s->next != NULL)
	{
		if (max < temp_s->next->value)
			max = temp_s->next->value;
		temp_s = temp_s->next;
	}
	return (max);
}

int	get_min(t_stack **stack)
{
	int		min;
	t_stack	*temp_s;

	temp_s = (*stack);
	min = temp_s->value;
	while(temp_s->next != NULL)
	{
		if (min > temp_s->next->value)
			min = temp_s->next->value;
		temp_s = temp_s->next;
	}
	return (min);
}