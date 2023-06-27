/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:01:33 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/27 09:06:37 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b, int pos, int value)
{
	int	maj;
	int	maj_pos;

	if (pos <= (ft_lstsize(*stack_b) / 2))
		while ((*stack_b)->value != value)
			write_rb(stack_b);
	else if (pos > (ft_lstsize(*stack_b) / 2))
		while ((*stack_b)->value != value)
			write_rrb(stack_b);
	maj = find_maj(stack_a, value);
	maj_pos = get_pos(stack_a, maj);
	if (maj_pos <= (ft_lstsize(*stack_a) / 2))
		while ((*stack_a)->value != maj)
			write_ra(stack_a);
	else if (maj_pos > (ft_lstsize(*stack_a) / 2))
		while ((*stack_a)->value != maj)
			write_rra(stack_a);
	write_pa(stack_b, stack_a);
}

void	pos_to_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		costtopush;
	int		postopush;
	int		valuetopush;
	t_stack	*sta_b;

	costtopush = __INT_MAX__;
	sta_b = *stack_b;
	while (sta_b)
	{
		if (sta_b->cost < costtopush)
		{
			costtopush = sta_b->cost;
			postopush = sta_b->pos;
			valuetopush = sta_b->value;
		}
		sta_b = sta_b->next;
	}
	sort(stack_a, stack_b, postopush, valuetopush);
}

void	sort_a(t_stack **stack_a)
{
	int	min;
	int	pos_min;

	min = get_min(stack_a);
	pos_min = get_pos(stack_a, min);
	if (pos_min < ft_lstsize(*stack_a) / 2)
		while ((*stack_a)->value != min)
			write_ra(stack_a);
	else if (pos_min >= ft_lstsize(*stack_a) / 2)
		while ((*stack_a)->value != min)
			write_rra(stack_a);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int	max_a;
	int	med_a;

	max_a = get_max(stack_a);
	med_a = get_median(stack_a);
	push_allb(stack_a, stack_b, max_a, med_a);
	while (ft_lstsize(*stack_b) > 0)
	{
		assign_pos(stack_a);
		assign_pos(stack_b);
		calcul_cost(stack_a, stack_b);
		pos_to_sort(stack_a, stack_b);
	}
	sort_a(stack_a);
}
