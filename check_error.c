/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:42:54 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/27 08:59:23 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_double(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (!ft_strcmp(av[i], av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_int(char **av)
{
	int			i;
	long int	nb;

	i = 1;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		if (nb > 2147483647 || nb < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_nb(char **av)
{
	int	i;
	int	j;

	i = 1;
	if (av[1][0] == '-' && !av[1][1])
		return (0);
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-' && \
			((av[i][j + 1] < '1' || av[i][j + 1] > '9') || !av[i][j + 1]))
				return (0);
			if ((av[i][j] < '0' || av[i][j] > '9') && \
			av[i][j] != '-' && av[i][j] != ' ')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_single(char **av)
{
	int	i;
	int	j;
	int	count_neg;

	i = 1;
	while (av[i])
	{
		j = 0;
		count_neg = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-')
				count_neg++;
			j++;
			if (count_neg > 1)
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_error(char **av)
{
	if (!check_nb(av) || !check_int(av))
		return (0);
	if (!check_double(av) || !check_single(av))
		return (0);
	return (1);
}
