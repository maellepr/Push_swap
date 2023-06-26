/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:42:35 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/26 12:15:15 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size_sa;

	size_sa = ft_lstsize(*stack_a);
	if (size_sa == 2 && !(is_sort(stack_a)))
		write_sa(stack_a);
	else if (size_sa == 3)
		sort_3(stack_a);
	else if (size_sa < 10 && !(is_sort(stack_a)))
		sort_small(stack_a, stack_b);
	else if (size_sa >= 10 && !(is_sort(stack_a)))
		sort_big(stack_a, stack_b);
}

int	count_av(char **av2)
{
	int	i;

	i = 0;
	while (av2[i])
		i++;
	return (i);
}

t_stack	*argv_is_2(char **av)
{
	int		i;
	int		ac2;
	char	**av2;
	t_stack	*stack_a;

	av2 = ft_split(av[1]);
	ac2 = count_av(av2);
	stack_a = fill_stack_value(ac2, av2);
	i = 0;
	while (av2[i])
	{
		free(av2[i]);
		i++;
	}
	free(av2);
	return (stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		error_and_quite();
	else if (ac == 2)
	{
		if (!ft_check_error(av))
			error_and_quite();
		stack_a = argv_is_2(av);
	}
	else if (ac > 2)
	{
		if (!ft_check_error(av))
			error_and_quite();
		stack_a = fill_stack_value(ac, av);
	}
	stack_b = NULL;
	push_swap(&stack_a, &stack_b);
	ft_free(stack_a);
	ft_free(stack_b);
	return (0);
}
