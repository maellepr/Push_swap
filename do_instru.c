/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_instru.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:42:40 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/22 13:19:42 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Interverti les deux premiers elements au sommet de la pile a ou b
*/
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

/*
Prend le 1er element de la pile src et le met sur l'autre pile dest 
do pop and push
*/
void	do_p(t_stack **src, t_stack **dest)
{
	int	value_to_push;

	if (*src == NULL)
		return ;
	value_to_push = (*src)->value;
	pop(src);
	push(value_to_push, dest);
}

/*
Decale d'une position vers le haut tous les elements de la pile
le 1er element devient le dernier
*/
void	do_r(t_stack **stack)
{
	int		prem_elem;
	t_stack	*temp_stack;

	if (*stack == NULL)
		return ;
	prem_elem = (*stack)->value;
	temp_stack = *stack;
	while (temp_stack->next != NULL)
	{
		temp_stack->value = temp_stack->next->value;
		temp_stack = temp_stack->next;
	}
	temp_stack->value = prem_elem;
}

t_stack	*stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return(stack);
}

/*
Decale d'une position vers le bas tous les elements de la pile
le dernier element devient le 1er
*/
void	do_rr(t_stack **stack)
{
	int		i;
	int		nb_elem;
	t_stack	*temp_stack;
	t_stack	*temp2_stack;
	t_stack	*last;

	if (*stack == NULL)
		return ;
	i = -1;
	nb_elem = ft_lstsize(*stack);
	last = stack_bottom(*stack);
	temp_stack = (*stack);
	(*stack) = last;
	(*stack)->next = temp_stack;
	temp2_stack = (*stack);
	while (++i < (nb_elem - 1) && temp2_stack)
		temp2_stack = temp2_stack->next;
	temp2_stack->next = NULL;
}