/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 11:07:48 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/21 11:58:12 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3_do(t_stack **stack_a, int min_pos, int max_pos)
{
	if (min_pos == 1 && max_pos == 0)
		write_ra(stack_a);
	if (min_pos == 0 && max_pos == 1)
	{
		write_sa(stack_a);
		write_ra(stack_a);
	}
	if (min_pos == 2 && max_pos == 0)
	{
		write_ra(stack_a);
		write_sa(stack_a);
	}
	if (min_pos == 1 && max_pos == 2)
		write_sa(stack_a);
	if (min_pos == 2 && max_pos == 1)
		write_rra(stack_a);
}


void	sort_3(t_stack **stack_a)
{
	int	min;
	int	max;
	int	min_pos;
	int	max_pos;

	min = get_min(stack_a);
	max = get_max(stack_a);
	// printf("min = %d\n", min);
	// printf("max = %d\n", max);
	assign_pos(stack_a);
	min_pos = get_pos(stack_a, min);
	max_pos = get_pos(stack_a, max);
	// printf("min_pos = %d\n", min_pos);
	// printf("max_pos = %d\n", max_pos);
	sort_3_do(stack_a, min_pos, max_pos);
}