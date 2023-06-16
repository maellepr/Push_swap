/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:42:35 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/16 17:35:11 by mapoirie         ###   ########.fr       */
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

void	sort_big(t_stack **stack_a, t_stack **stack_b)
{
	int		min_a;
	int		max_a;
	int		med_a;
	t_stack	*sta_a;
	t_stack	*sta_b;

	sta_a = (*stack_a);
	sta_b = (*stack_b);
	max_a = get_max(stack_a); 
	min_a = get_min(stack_a);
	med_a = get_median(stack_a, min_a);
	//printf("med_a = %d\n", med_a);
// Au lieu d'envoyer tous les plus grand > mediane, tous les plus petis < mediane
// Envoyer dans l'ordre tous sauf le max et faire un rotate b lorque la value est plus grande
	while (ft_lstsize(*stack_a) > 6)
	{

		//print_pile(*stack_a);
		if (((*stack_a)->value) > med_a && ((*stack_a)->value) != max_a)
			write_pa(stack_a, stack_b);
		//printf("sta_a->value = %d\n", sta_a->value);
		//printf("\nEtat de ma pile a apres **:\n\n");		
		else 
			write_ra(stack_a);

		//printf("sta_a->value apres = %d\n", sta_a->value);
	}
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
		//sort_big(stack_a, stack_b);
	}
}