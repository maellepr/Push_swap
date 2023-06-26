/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instru.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:59:21 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/26 12:03:47 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	write_sa(t_stack **stack_a)
{
	write(1, "sa\n", 3);
	do_s(stack_a);
}

void	write_sb(t_stack **stack_b)
{
	write(1, "sb\n", 3);
	do_s(stack_b);
}

void	write_ss(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "ss\n", 3);
	do_s(stack_a);
	do_s(stack_b);
}

void	write_pa(t_stack **stack_b, t_stack **stack_a)
{
	write(1, "pa\n", 3);
	do_p(stack_b, stack_a);
}

void	write_pb(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "pb\n", 3);
	do_p(stack_a, stack_b);
}
