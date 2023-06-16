/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:42:50 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/16 13:42:51 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Ajoute le nouveau maillon en bas de la liste chainee
*/
void	stack_add_bottom(t_stack *stack, t_stack *new)
{
	if(!new)
		return;
	// if(!*stack)
	// {
	// 	*stack = new;
	// 	return;
	// }
	while (stack && stack->next != NULL)
		stack = stack->next;
	stack->next = new;

}

/*
Creer nouveau maillon en donnant a value la valeur de nb 
et pointeur next pointe vers NULL 
*/
t_stack	*stack_new(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return(NULL);
	new->value = nb;
	new->next = NULL;
	return (new);
}

t_stack	*fill_stack_value(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (i == 1)
			stack_a = stack_new(nb);// argv[1] = 45 donc nb = 45
		else
			stack_add_bottom(stack_a, stack_new(nb));// stack a (45 -> NULL), argv[2] = 8
		i++;
	}
	return (stack_a);
}