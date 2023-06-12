#include "push_swap.h"

// int	ft_push(t_list *top, int ac, char **av)
// {
// 	int			i = ac;
// 	int			nbr;
// 	t_list		*newNode;


// 	while (i > 0)
// 	{	
// 		newNode = malloc(sizeof(*newNode));
// 		if (!newNode)
// 		{
// 			free(newNode);
// 			return (0); 
// 		}
// 		nbr = ft_atoi(av[i]);
// 		newNode->nb = &nbr;
// 		newNode->next = top;
// 		top = newNode;
// 		i--;
// 	}
// 	return(1);
// }

// void	ft_printlst(t_list *top)
// {
// 	t_list *ptr;
	
// 	ptr = top;
// 	while(ptr)
// 	{
// 		printf("%d\n", *(ptr->nb));
// 		ptr = ptr->next;
// 	}
// }

// void empiler(Pile *pile, int nvNombre)
// {
//     Element *nouveau = malloc(sizeof(*nouveau));
//     if (pile == NULL || nouveau == NULL)
//         exit(EXIT_FAILURE);
//     nouveau->nb = nvNombre;
//     nouveau->suivant = pile->premier;
//     pile->premier = nouveau;
// }
t_stack	*get_stack_bottom(t_stack *stack)
{
	while (stack && stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_new(int nb)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(*new_stack));
	if (!new_stack)
		return (NULL);
	new_stack->value = nb;
	new_stack->next = NULL;
	return (new_stack);
}

void	stack_add_bottom(t_stack **stack, t_stack *new)
{
	t_stack	*queue;

	if(!new)
		return;
	if(!*stack)
	{
		*stack = new;
		return;
	}
	queue = get_stack_bottom(*stack);
	queue->next = new;
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
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

void afficherPile(t_stack *stack_a)
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
	afficherPile(stack_a);
	return (0);
}