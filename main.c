/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:42:27 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/20 17:51:24 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Fonction temporaire pour afficher le contenu d'une pile
*/
// void print_pile(t_stack *stack)
// {
// 	t_stack	*stack1 = stack;
 
//     if (stack1 == NULL)
//     {
//         printf("Stack Underflow\n");
//         return;
//     }
//     while (stack1 != NULL)
//     {
//         printf("%d	pos : %d	cost : %d\n", stack1->value, stack1->pos, stack1->cost);
//         stack1 = stack1->next;
//     }
// }

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
	{
		write (2, "Error\n", 6);
		return (0);	
	}
	else if (ac > 2)
	{
		if (!ft_check_error(av))
		{
			write (2, "Error\n", 6);
			return (0);
		}
	}
	stack_a = fill_stack_value(ac, av);
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	// printf("\nEtat de ma pile a apres :\n\n");
	// print_pile(stack_a);
	// printf("\nEtat de ma pile b apres :\n\n");
	// print_pile(stack_b);
	ft_free(stack_a);
	ft_free(stack_b);
	return (0);
}