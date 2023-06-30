/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:50:39 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/29 11:45:08 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	error_free_quite(t_stack **stack_a, t_stack **stack_b)
{
	write (2, "Error\n", 6);
	if (*stack_a)
		ft_free(*stack_a);
	if (*stack_b)
		ft_free(*stack_b);
	exit(EXIT_FAILURE);
}

void	error_and_quite(void)
{
	write (2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
