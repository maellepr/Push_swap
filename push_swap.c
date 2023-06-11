#include "push_swap.h"

int	ft_push(t_list *top, int ac, char **av)
{
	int			i = ac;
	int			nbr;
	t_list		*newNode;


	while (i > 0)
	{	
		newNode = malloc(sizeof(*newNode));
		if (!newNode)
		{
			free(newNode);
			return (0); 
		}
		nbr = ft_atoi(av[i]);
		newNode->nb = &nbr;
		newNode->next = top;
		top = newNode;
		i--;
	}
	return(1);
}

void	ft_printlst(t_list *top)
{
	t_list *ptr;
	
	ptr = top;
	while(ptr)
	{
		printf("%d\n", *(ptr->nb));
		ptr = ptr->next;
	}
}

int	main(int ac, char **av)
{
	if(ac > 2)
	{
		if (!ft_check_error(av))
		{
			write (2, "Error\n", 6);
			return (0);
		}
	}
	write (1, "No error\n", 9);
	t_list *top = NULL;
	ft_push(top, ac, av);
	//ft_printlst(top);
	return (0);
}