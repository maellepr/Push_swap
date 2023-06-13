#include "push_swap.h"

/*
Fonction temporaire pour afficher le contenu d'une pile
*/
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
	
	printf("\nEtat de ma pile a avant :\n");
	print_pile(stack_a);
	printf("\nEtat de ma pile b avant :\n");
	print_pile(stack_b);
	do_p(stack_a, stack_b);
	// stack_b = stack_a;
	//stack_a = stack_a->next;
	printf("\nEtat de ma pile a apres do_p :\n");
	print_pile(stack_a);
	printf("\nEtat de ma pile b apres do_p :\n");
	print_pile(stack_b);
	ft_free(stack_a);
	return (0);
}