/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:50:33 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/29 11:48:07 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	before_do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	do_rr(stack_a);
	do_rr(stack_b);
}

void	before_do_rr(t_stack **stack_a, t_stack **stack_b)
{
	do_r(stack_a);
	do_r(stack_b);
}

void	do_instru(char *instru, t_stack **stack_a, t_stack **stack_b)
{
	if (!ft_strcmp(instru, "sa\n"))
		do_s(stack_a);
	else if (!ft_strcmp(instru, "sb\n"))
		do_s(stack_b);
	else if (!ft_strcmp(instru, "pa\n"))
		do_p(stack_b, stack_a);
	else if (!ft_strcmp(instru, "pb\n"))
		do_p(stack_a, stack_b);
	else if (!ft_strcmp(instru, "ra\n"))
		do_r(stack_a);
	else if (!ft_strcmp(instru, "rb\n"))
		do_r(stack_b);
	else if (!ft_strcmp(instru, "rr\n"))
		before_do_rr(stack_a, stack_b);
	else if (!ft_strcmp(instru, "rra\n"))
		do_rr(stack_a);
	else if (!ft_strcmp(instru, "rrb\n"))
		do_rr(stack_b);
	else if (!ft_strcmp(instru, "rrr\n"))
		before_do_rrr(stack_a, stack_b);
	else
		error_free_quite(stack_a, stack_b);
}

int	check_pile(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b) != NULL || *stack_a == NULL)
		return (0);
	else if (*stack_a && (*stack_b) == NULL)
	{
		while (*stack_a && ((*stack_a)->next != NULL))
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
				return (0);
			(*stack_a) = (*stack_a)->next;
		}
	}
	return (1);
}

void	start_checker(t_stack **stack_a, t_stack **stack_b)
{
	char	*instru;

	instru = get_next_line(0);
	if (!instru)
		return ;
	while (instru != NULL)
	{
		do_instru(instru, stack_a, stack_b);
		free(instru);
		instru = get_next_line(0);
	}
	free(instru);
}
