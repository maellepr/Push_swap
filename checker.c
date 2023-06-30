/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:48:07 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/29 11:47:46 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_av(char **av2)
{
	int	i;

	i = 0;
	while (av2[i])
		i++;
	return (i);
}

void	free_av2(char **av2)
{
	int	i;

	i = 0;
	while (av2[i])
	{
		free(av2[i]);
		i++;
	}
	free(av2);
}

t_stack	*argv_is_2(char **av)
{
	int		i;
	int		ac2;
	char	**av2;
	t_stack	*stack_a;

	av2 = ft_split(av[1]);
	if (!ft_check_error(av2))
	{
		free_av2(av2);
		error_and_quite();
	}
	ac2 = count_av(av2);
	stack_a = fill_stack_value(ac2, av2);
	i = 0;
	free_av2(av2);
	return (stack_a);
}

void	ft_sorted(t_stack **stack_a, t_stack **stack_b)
{
	if (!check_pile(stack_a, stack_b))
		write(1, "KO\n", 3);
	else if (check_pile(stack_a, stack_b))
		write(1, "OK\n", 3);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
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
	start_checker(&stack_a, &stack_b);
	ft_sorted(&stack_a, &stack_b);
	ft_free(stack_a);
	ft_free(stack_b);
	return (0);
}
