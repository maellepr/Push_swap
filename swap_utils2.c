/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:43:04 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/20 16:56:07 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack **stack)
{
	int		max;
	t_stack	*temp_s;

	temp_s = (*stack);
	max = temp_s->value;
	while(temp_s->next != NULL)
	{
		if (max < temp_s->next->value)
			max = temp_s->next->value;
		temp_s = temp_s->next;
	}
	return (max);
}

int	get_min(t_stack **stack)
{
	int		min;
	t_stack	*temp_s;

	temp_s = (*stack);
	min = temp_s->value;
	while(temp_s->next != NULL)
	{
		if (min > temp_s->next->value)
			min = temp_s->next->value;
		temp_s = temp_s->next;
	}
	return (min);
}

int	*make_tab(t_stack **stack, int size)
{
	int		i;
	int		*tab;
	t_stack	*sta;

	i = 0;
	sta = (*stack);
	tab = malloc(sizeof(int) * size + 1);
	while (sta->next != NULL)
	{
		tab[i] = sta->value;
		sta = sta->next;
		i++;
	}
	return(tab);
}

int	sort_tab_find_med(int *tab, int size)
{
	int swap;
	int	i;
	int med;

	i = 0;
	while (i < (size - 1))
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
			i = 0;
		}
		else
			i++;
	}
	med = tab[size / 2];
	return (med);
}

int	get_median(t_stack **stack)
{
	int		med;
	int		stack_size;
	int		*tab;
	t_stack *sta;


	sta = *stack;
	stack_size = ft_lstsize(sta);
	tab = make_tab(stack, stack_size);	
	med = sort_tab_find_med(tab, stack_size);
	return (med);
}