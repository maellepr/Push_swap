/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 09:50:24 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/29 11:48:18 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *str1, char *str2)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' || str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}

int	ft_checksign(const char *str)
{
	int	i;
	int	c;
	int	sign;

	i = 0;
	c = 0;
	sign = '+';
	while (str[i] == ' ' || (str[i] < 14 && str[i] > 8))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = '-';
		i++;
		c++;
	}
	if (c > 1)
		return (0);
	else
		return (sign);
}

int long	ft_atoi(const char *str)
{
	int			i;
	int long	nb;

	i = 0;
	nb = 0;
	if (ft_checksign(str) == '-' || ft_checksign(str) == '+')
	{
		while (str[i] == ' ' || (str[i] < 14 && str[i] > 8))
			i++;
		while (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] <= '9' && str[i] >= '0')
		{
			nb = nb * 10 + (str[i] - '0');
			i++;
		}
	}
	if (ft_checksign(str) == '-')
		return (nb * (-1));
	if ((nb < INT_MIN && ft_strlen(str) >= 11) \
	|| (nb > INT_MAX && ft_strlen(str) >= 10))
		error_and_quite();
	return (nb);
}
