/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instru2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:59:32 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/26 12:03:34 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_ra(t_stack **stack_a)
{
	write(1, "ra\n", 3);
	do_r(stack_a);
}

void	write_rb(t_stack **stack_b)
{
	write(1, "rb\n", 3);
	do_r(stack_b);
}

void	write_rr(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "rr\n", 3);
	do_r(stack_a);
	do_r(stack_b);
}
