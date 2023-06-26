/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:23:22 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/26 10:56:15 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_allb(t_stack **stack_a, t_stack **stack_b, int max, int med)
{
	while (ft_lstsize(*stack_a) > 1)
	{
		if ((*stack_a)->value != max)
		{
			write_pb(stack_a, stack_b);
			if (ft_lstsize(*stack_b) >= 2 && (*stack_b)->value > med)
				write_rb(stack_b);
		}
		else
			write_ra(stack_a);
	}
}

int	cost_b(int middle, int pos_nb, t_stack **stack_b)
{
	int	cost;

	cost = pos_nb;
	if (pos_nb < middle)
		cost = pos_nb;
	else if (pos_nb >= middle)
		cost = ft_lstsize(*stack_b) - pos_nb;
	return (cost);
}

int	cost_a(int nb_sta_b, t_stack **stack_a)
{
	int		cost;
	int		maj;
	t_stack	*sta_a;

	sta_a = (*stack_a);
	maj = get_max(stack_a);
	while (sta_a)
	{
		if (sta_a->value > nb_sta_b && sta_a->value <= maj)
			maj = sta_a->value;
		sta_a = sta_a->next;
	}
	cost = cost_b(ft_lstsize(*stack_a) / 2, get_pos(stack_a, maj), stack_a);
	return (cost);
}

void	calcul_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*sta_b;

	sta_b = (*stack_b);
	while (sta_b)
	{
		sta_b->cost = cost_b((ft_lstsize(*stack_b)) / 2, sta_b->pos, stack_b);
		sta_b->cost += cost_a(sta_b->value, stack_a);
		sta_b = sta_b->next;
	}
}

int	find_maj(t_stack **stack_a, int valuetopush)
{
	int		maj;
	t_stack	*sta_a;

	maj = get_max(stack_a);
	sta_a = (*stack_a);
	while (sta_a)
	{
		if (sta_a->value < maj && sta_a->value > valuetopush)
			maj = sta_a->value;
		sta_a = sta_a->next;
	}
	return (maj);
}
