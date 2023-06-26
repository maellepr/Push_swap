/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 10:59:50 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/26 12:18:56 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_stack **stack)
{
	int		max;
	t_stack	*temp_s;

	temp_s = (*stack);
	max = temp_s->value;
	while (temp_s->next != NULL)
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
	while (temp_s->next != NULL)
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
	tab = malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		tab[i] = sta->value;
		sta = sta->next;
		i++;
	}
	i = 0;
	return (tab);
}

int	calcul_med(int *tab, int size)
{
	int	med;

	if (size % 2 != 0)
		med = tab[size / 2];
	else
		med = (tab[size / 2] + tab[size / 2 - 1]) / 2;
	return (med);
}

int	sort_tab_find_med(int *tab, int size)
{
	int	swap;
	int	i;
	int	j;
	int	med;

	i = 1;
	swap = 0;
	med = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[i])
				ft_swap(&tab[j], &tab[i]);
			j++;
		}
		i++;
	}
	med = calcul_med(tab, size);
	free(tab);
	return (med);
}
