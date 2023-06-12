#include "push_swap.h"
/*
Ajoute le nouveau maillon en bas de la liste chainee
*/
void	stack_add_bottom(t_stack *stack, t_stack *new)
{
	if(!new)
		return;
	// if(!*stack)
	// {
	// 	*stack = new;
	// 	return;
	// }
	while (stack && stack->next != NULL)
		stack = stack->next;
	stack->next = new;
}
/*
Creer nouveau maillon en donnant a value la valeur de nb 
et pointeur next pointe vers NULL 
*/
t_stack	*stack_new(int nb)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = nb;
	new->next = NULL;
	return (new);
}

t_stack	*fill_stack_value(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = atoi(av[i]);
		if (i == 1)
			stack_a = stack_new(nb);// argv[1] = 45 donc nb = 45
		else
			stack_add_bottom(stack_a, stack_new(nb));// stack a (45 -> NULL), argv[2] = 8
		i++;
	}
	return (stack_a);
}

void print_pile(t_stack *stack_a)
{
    if (stack_a == NULL)
        return ;
    while (stack_a != NULL)
    {
        printf("%d\n", stack_a->value);
    	stack_a = stack_a->next;
    }
    printf("\n");
}

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
	write (1, "No error\n", 9);
	stack_a = fill_stack_value(ac, av);
	stack_b = NULL;

	printf("\nEtat de ma pile a :\n");
	print_pile(stack_a);
	return (0);
}