/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:42:35 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/20 17:48:54 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Renvoie 1 si liste triee
Renvoie 0 si liste n'est pas triee
*/
int	is_sort(t_stack **stack)
{
	t_stack	*temp_s;

	temp_s = (*stack);
	while(temp_s->next != NULL)
	{
		if (temp_s->value > temp_s->next->value)
			return (0);
		temp_s = temp_s->next;
	}
	return (1);
}

void	push_allb(t_stack **stack_a, t_stack **stack_b, int max, int med)
{
	//Initialisation : on push tout dans b sauf max, en triant plus grand en bas plus petit en haut
	
	while (ft_lstsize(*stack_a) > 1)
	{
		if ((*stack_a)->value != max)
		{
			write_pb(stack_a, stack_b);
			if (ft_lstsize(*stack_b) >= 2 && (*stack_b)->value > med)
				write_rb(stack_b);
		}
		else
			write_ra(stack_a);
	}
	//printf("stack_b->value : %d\n", (*stack_b)->value);
}

void	assign_pos(t_stack **stack_a, t_stack **stack_b)
{
	int		pos;
	t_stack	*sta_a;
	t_stack	*sta_b;

	pos = 0;
	sta_a = *stack_a;
	sta_b = *stack_b;
	while (sta_a)
	{
		sta_a->pos = pos;
		sta_a = sta_a->next;
		pos++; 
	}
	pos = 0;
	while (sta_b)
	{
		sta_b->pos = pos;
		sta_b = sta_b->next;
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
	return(-1);
}
// Compte le cout de remonter ou de descendre un nb pour pouvoir le push
int	cost_b(int middle, int pos_nb, t_stack **stack_b)
{
	int cost;
	
	if (pos_nb < middle)
		cost = pos_nb;
	else if (pos_nb >= middle)
		cost = ft_lstsize(*stack_b) - pos_nb;
	return (cost);		
}

// Compte le cout de remonter un nb de la stack_a en fonction du nb en question de la stack_b
// en cherchant le plus petit majorant du nb
int	cost_a(int nb_sta_b, t_stack **stack_a)
{
	int		cost;
	int		maj;
	t_stack	*sta_a;

	sta_a = (*stack_a);
	maj = get_max(stack_a);
	while(sta_a)
	{
		if (sta_a->value > nb_sta_b && sta_a->value <= maj)
			maj = sta_a->value;
		sta_a = sta_a->next;
	}
	cost = cost_b(ft_lstsize(*stack_a) / 2 , get_pos(stack_a, maj), stack_a);
	return (cost);
}



void	calcul_cost(t_stack **stack_a, t_stack **stack_b)
{
//	int		middle;
//	int		med_b;
//	t_stack	*sta_a;
	t_stack	*sta_b;

//	sta_a = (*stack_a);
	sta_b = (*stack_b);
//	middle = ft_lstsize(stack_b) / 2;
//	med_b = get_median(stack_b, min_b);// ici 6
	while (sta_b)
	{
		sta_b->cost = cost_b((ft_lstsize(*stack_b)) / 2, sta_b->pos, stack_b) + cost_a(sta_b->value, stack_a);
		sta_b = sta_b->next;
	}
}

int	find_maj(t_stack **stack_a, int valuetopush)
{
//	int 	max;
	int		maj;
	t_stack	*sta_a;

	maj = get_max(stack_a);;//45
	sta_a = (*stack_a);
	while (sta_a)
	{
		if (sta_a->value < maj && sta_a->value > valuetopush)
			maj = sta_a->value;
		sta_a = sta_a->next;
	}
	//printf("valuetopuh = %d et son majorant = %d\n", valuetopush, maj);
	return (maj);
}

void	sort(t_stack **stack_a, t_stack **stack_b, int postopush, int valuetopush)
{
	int		maj;
	int		maj_pos;

	// printf("value to push = %d\n", valuetopush);
	// printf("pos to push = %d\n", postopush);
	// printf("lstsize / 2 = %d\n", ft_lstsize(*stack_b) / 2);
	//remonte la bonne valeur en haut de stack_b 
	if (postopush < (ft_lstsize(*stack_b) / 2))
		while ((*stack_b)->value != valuetopush)
			write_rb(stack_b);
	else if (postopush >= (ft_lstsize(*stack_b) / 2))
		while ((*stack_b)->value != valuetopush)
			write_rrb(stack_b);
	//remonte le majorant en haut de stack_a
	maj = find_maj(stack_a, valuetopush);
	// printf("maj = %d\n", maj);
	maj_pos = get_pos(stack_a, maj);
	if (maj_pos < (ft_lstsize(*stack_a) / 2))
		while ((*stack_a)->value != maj)
			write_ra(stack_a);
	else if (maj_pos >= (ft_lstsize(*stack_a) / 2))
		while ((*stack_a)->value != maj)
			write_rra(stack_a);
	write_pa(stack_b, stack_a);
}

void	pos_to_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		costtopush;
	int		postopush;
	int		valuetopush;
	t_stack *sta_b;

	// costtopush = sta_b->cost;
	costtopush = 100;
	sta_b = *stack_b;
// cherche la position du nb a pusher dans stack_a
	while(sta_b)
	{
		if (sta_b->cost < costtopush)
		{
			costtopush = sta_b->cost;
			postopush = sta_b->pos;
			valuetopush = sta_b->value;
		}
		sta_b = sta_b->next;
	}
	sort(stack_a, stack_b, postopush, valuetopush);
}

void	sort_a(t_stack **stack_a)
{
	int	min;
	int	pos_min;

	min = get_min(stack_a);
	pos_min = get_pos(stack_a, min);
	if (pos_min < ft_lstsize(*stack_a) / 2)
		while ((*stack_a)->value != min)
			write_ra(stack_a);
	if (pos_min >= ft_lstsize(*stack_a) / 2)
		while ((*stack_a)->value != min)
			write_rra(stack_a);
}

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
//	int	min_a;
	int	max_a;
	int	med_a;
	
	max_a = get_max(stack_a);
	med_a = get_median(stack_a);

	push_allb(stack_a, stack_b, max_a, med_a);
	// printf("\nEtat de ma pile a apres push_allb :\n");
	// print_pile(*stack_a);
	// printf("\nEtat de ma pile b apres push_allb :\n");
	// print_pile(*stack_b);
	while (ft_lstsize(*stack_b) > 0)// a changer avec 0
	{
		assign_pos(stack_a, stack_b);
		calcul_cost(stack_a, stack_b);
		pos_to_sort(stack_a, stack_b);
	}	
	sort_a(stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size_sa;

	size_sa = ft_lstsize(*stack_a);
	//printf("taille de la liste = %d\n", size_sa);
	//write_pa(stack_a, stack_b);
	if (size_sa == 2 && !(is_sort(stack_a)))// dans le cas u il y a deux nb
		write_sa(stack_a);
	else if (size_sa == 3 )
	{

	}
	else if (size_sa <= 10 && !(is_sort(stack_a)))
	{
		
	}
	else if (size_sa > 10 && !(is_sort(stack_a)))
	{
		sort_big(stack_a, stack_b);
	}
}