/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 13:42:27 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/23 11:24:17 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Fonction temporaire pour afficher le contenu d'une pile
*/
void print_pile(t_stack *stack)
{
	t_stack	*stack1 = stack;
 
    if (stack1 == NULL)
    {
        printf("Stack Underflow\n");
        return;
    }
	int i = 1;
    while (stack1 != NULL)
    {
        printf("%d	pos : %d	cost : %d	i = %d\n", stack1->value, stack1->pos, stack1->cost, i);
        stack1 = stack1->next;
		i++;
    }
}

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
	int count;
	int	trigger;
	
	count = 0;
	trigger = 0;
	while(*av)
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
	new_str[j] = '\0';
	new_str[0][0] = 'x';// valeur arbitraire
	new_str[0][1] = '\0';
	// int k = 0;
	// while(new_str[k])
	// {
	// 	write (1, new_str[k], 1);
	// 	write (1, " ", 1);
	// 	k++;
	// }
	// write(1, "\n", 1);
	return (new_str);
}

char	**ft_split(char *av)
{
	char	**new_str;

	if (!av)
		error_and_quite();
	if ((ft_countwords(av)) == 0 || (ft_countwords(av)) == 1)
		exit (0);
	//printf("-----------countwords-------------- : %d\n", ft_countwords(av));	
	new_str = malloc((ft_countwords(av) + 2) * sizeof(char *));
	if (!new_str)
		error_and_quite();
	new_str = ft_split2(av, new_str);
	return (new_str);
}

int	count_av(char **av2)
{
	int	i;

	i = 0;
	while(av2[i])
		i++;
	return (i);
}

t_stack	*argv_is_2(char **av)
{
	int		ac2;
	char	**av2;
	t_stack	*stack_a;
	
	av2 = ft_split(av[1]);	
	ac2 = count_av(av2);
	if (!ft_check_error(av2))
		error_and_quite();
	stack_a = fill_stack_value(ac2, av2);
	//printf("av2[2][0] = %c\n", av2[2][0]);
	// printf("\nEtat de ma pile a apres :\n\n");
	// print_pile(stack_a);
	// printf("\nEtat de ma pile b apres :\n\n");
	// print_pile(stack_b);
	int i = 0;
	while(av2[i])
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
		stack_a = argv_is_2(av);
	else if (ac > 2)
	{
		if (!ft_check_error(av))
			error_and_quite();
		stack_a = fill_stack_value(ac, av);
	}
	//---------------------------------------------
	// else if (ac >= 2)
	// {
	// 	if (!ft_check_error(av))
	// 	{
	// 		write (2, "Error\n", 6);
	// 		return (0);
	// 	}
	// }
	// stack_a = fill_stack_value(ac, av);
	//----------------------------------------------
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