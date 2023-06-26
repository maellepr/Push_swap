/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_instru3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:59:35 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/26 12:09:05 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_and_quite(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	write_rra(t_stack **stack_a)
{
	write(1, "rra\n", 4);
	do_rr(stack_a);
}

void	write_rrb(t_stack **stack_b)
{
	write(1, "rrb\n", 4);
	do_rr(stack_b);
}

void	write_rrr(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "rrr\n", 4);
	do_rr(stack_a);
	do_rr(stack_b);
}
