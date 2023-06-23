/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 12:05:54 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/21 14:12:49 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_stack **stack_a, t_stack **stack_b)
{
	int	min;
	int	min_pos;


	while (!(is_sort(stack_a)))
	{
		while (ft_lstsize(*stack_a) > 3)
		{
			//printf("la taille de stack_a = %d\n", ft_lstsize(*stack_a));
			min = get_min(stack_a);
			assign_pos(stack_a);
			min_pos = get_pos(stack_a, min);
			if (min_pos < ft_lstsize(*stack_a) / 2)
				while ((*stack_a)->value != min)
					write_ra(stack_a);
			if (min_pos > ft_lstsize(*stack_a) / 2)
				while ((*stack_a)->value != min)
					write_rra(stack_a);
			write_pb(stack_a, stack_b);
		}
		sort_3(stack_a);
		while(ft_lstsize(*stack_b) > 0)
			write_pa(stack_b, stack_a);
	}
		
}