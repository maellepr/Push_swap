/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instru2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:02:19 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/26 12:11:08 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_r(t_stack **stack)
{
	int		prem_elem;
	t_stack	*temp_stack;

	if (*stack == NULL)
		return ;
	prem_elem = (*stack)->value;
	temp_stack = *stack;
	while (temp_stack->next != NULL)
	{
		temp_stack->value = temp_stack->next->value;
		temp_stack = temp_stack->next;
	}
	temp_stack->value = prem_elem;
}

t_stack	*stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	do_rr(t_stack **stack)
{
	int		i;
	int		nb_elem;
	t_stack	*temp_stack;
	t_stack	*temp2_stack;
	t_stack	*last;

	if (*stack == NULL)
		return ;
	i = -1;
	nb_elem = ft_lstsize(*stack);
	last = stack_bottom(*stack);
	temp_stack = (*stack);
	(*stack) = last;
	(*stack)->next = temp_stack;
	temp2_stack = (*stack);
	while (++i < (nb_elem - 1) && temp2_stack)
		temp2_stack = temp2_stack->next;
	temp2_stack->next = NULL;
}
