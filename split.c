/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:16:20 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/26 10:56:14 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_copyword(char *av, int i_begin, int i_end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((i_end - i_begin +1) * sizeof(char));
	if (!word)
		error_and_quite();
	while (i_begin < i_end)
	{
		word[i] = av[i_begin];
		i++;
		i_begin++;
	}
	word[i] = '\0';
	return (word);
}

int	ft_countwords(char *av)
{
	int	count;
	int	trigger;

	count = 0;
	trigger = 0;
	while (*av)
	{
		if (*av != ' ' && trigger == 0)
		{
			trigger = 1;
			count++;
		}
		else if (*av == ' ')
			trigger = 0;
		av++;
	}
	return (count);
}

char	**ft_split2(char *av, char **new_str)
{
	size_t	i;
	int		j;
	int		index;

	i = 0;
	j = 1;
	index = -1;
	new_str[0] = malloc(sizeof(char) + 1);
	if (!new_str[0])
		exit (0);
	while (i <= ft_strlen(av))
	{
		if (av[i] != ' ' && index < 0)
			index = i;
		else if ((av[i] == ' ' || i == ft_strlen(av)) && index >= 0)
		{
			new_str[j] = ft_copyword(av, index, i);
			index = -1;
			j++;
		}
		i++;
	}
	new_str[j] = 0;
	return (new_str);
}

char	**ft_split(char *av)
{
	char	**new_str;

	if (!av)
		error_and_quite();
	if ((ft_countwords(av)) == 0 || (ft_countwords(av)) == 1)
		exit (0);
	new_str = malloc((ft_countwords(av) + 2) * sizeof(char *));
	if (!new_str)
		error_and_quite();
	new_str = ft_split2(av, new_str);
	new_str[0][0] = 'x';
	new_str[0][1] = '\0';
	return (new_str);
}
