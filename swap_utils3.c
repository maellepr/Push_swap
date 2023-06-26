/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:59:56 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/26 12:19:39 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	is_sort(t_stack **stack)
{
	t_stack	*temp_s;

	temp_s = (*stack);
	while (temp_s->next != NULL)
	{
		if (temp_s->value > temp_s->next->value)
			return (0);
		temp_s = temp_s->next;
	}
	return (1);
}

void	assign_pos(t_stack **stack)
{
	int		pos;
	t_stack	*sta;

	pos = 0;
	sta = *stack;
	while (sta)
	{
		sta->pos = pos;
		sta = sta->next;
		pos++;
	}
}

int	get_pos(t_stack **stack, int value)
{
	t_stack	*sta;

	sta = (*stack);
	while (sta)
	{
		if (sta->value == value)
			return (sta->pos);
		sta = sta->next;
	}
	return (-1);
}

int	get_median(t_stack **stack)
{
	int		med;
	int		stack_size;
	int		*tab;
	t_stack	*sta;

	sta = *stack;
	stack_size = ft_lstsize(sta);
	tab = make_tab(stack, stack_size);
	med = sort_tab_find_med(tab, stack_size);
	return (med);
}
