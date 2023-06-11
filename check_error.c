#include "push_swap.h"

int	check_double(char **av)
{
	int	i = 1;
	while (av[i])
	{
		int	j = i + 1;
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
	int			i = 1;
	long int	nb;

	while(av[i])
	{
		nb = ft_atoi(av[i]);
		//printf("nb apres atoi : %ld\n", nb);
		if (nb > 2147483647 || nb < -2147483648)
			return (0);
		i++;
	}
	return (1);
}

int	check_nb(char **av)
{
	int	i = 1;
	int	j;

	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{	
			if ((av[i][j] < '0' || av[i][j] > '9') && av[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_error(char **av)
{
	if (!check_nb(av) || !check_int(av) || !check_double(av))
		return (0);
	return (1);
}