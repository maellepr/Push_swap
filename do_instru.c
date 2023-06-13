#include "push_swap.h"

/*
Intervertit les deux premiers elements au sommet de la pile a ou b
*/
void	do_s(t_stack *stack)
{
	int	temp;

	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
}

/*
Prend le 1er element de la pile stack_x et le met sur l'autre pile stack_y 
*/
t_stack*	do_p(t_stack *stack_x, t_stack *stack_y)
{

	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = stack_x->value;
	new->next = stack_y->value;
	return (new);
	free(stack_x);
}

/*
Decale d'une position vers le haut tous les elements de la pile
le 1er element devient le dernier
*/
void	do_r(t_stack *stack)
{
	int	prem_elem;

	prem_elem = stack->value;
	while (stack->next != NULL)
	{
		stack->value = stack->next->value;
		stack = stack->next;
	}
	stack->value = prem_elem;
}

/*
Decale d'une position vers le bas tous les elements de la pile
le dernier element devient le 1er
*/
// void	do_rr(t_stack *stack)
// {

// }