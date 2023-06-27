/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instru.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:00:51 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/26 15:46:08 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_s(t_stack **stack)
{
	int	temp;

	if (*stack == NULL)
		return ;
	temp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = temp;
}

void	push(int value_to_push, t_stack **dest)
{
	t_stack	*temp_dest;

	if (*dest == NULL)
	{
		(*dest) = malloc(sizeof(t_stack));
		if (!*dest)
			return ;
		(*dest)->next = NULL;
		(*dest)->value = value_to_push;
	}
	else
	{
		temp_dest = malloc(sizeof(t_stack));
		if (!temp_dest)
			return ;
		temp_dest->next = (*dest);
		temp_dest->value = value_to_push;
		(*dest) = temp_dest;
	}
}

void	pop(t_stack **src)
{
	t_stack	*temp_src;

	if (*src == NULL)
		return ;
	temp_src = (*src)->next;
	free(*src);
	(*src) = temp_src;
}

void	do_p(t_stack **src, t_stack **dest)
{
	int	value_to_push;

	if (*src == NULL)
		return ;
	value_to_push = (*src)->value;
	pop(src);
	push(value_to_push, dest);
}
