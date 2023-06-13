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
Prend le 1er element de la pile src et le met sur l'autre pile dest 
*/
void	do_p(t_stack *src, t_stack *dest)
{
	int	temp;

	temp = src->value;
	src->value = src->next->value;
	if (dest == NULL)
		dest = stack_new(temp);
	else
		stack_add_bottom(dest, stack_new(temp));
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