/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:59:40 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/26 12:12:58 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add_bottom(t_stack *stack, t_stack *new)
{
	if (!new)
		return ;
	if (!stack)
	{
		stack = new;
		return ;
	}
	while (stack && stack->next != NULL)
		stack = stack->next;
	stack->next = new;
}

t_stack	*stack_new(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
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
			stack_a = stack_new(nb);
		else
			stack_add_bottom(stack_a, stack_new(nb));
		i++;
	}
	return (stack_a);
}
