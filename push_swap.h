#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 

// typedef struct s_list
// {
// 	int				*nb;
// 	struct s_list	*next;
// }		t_list;

// t_list *top = NULL;

// typedef struct Element Element;
// struct Element
// {
// 	int		nb;
// 	Element	*suivant;
// };

// typedef struct Pile Pile;
// struct Pile
// {
// 	Element	*premier;
// };

typedef struct s_stack
{
	int				value;
	//int				index;
	//int				pos;
	//int				target_pos;
	//int				cost_a;
	//int				cost_b;
	struct s_stack	*next;
}	t_stack;

// ------------------- swap_utils --------------------
int long	ft_atoi(const char *str);
int			ft_strcmp(char *str1, char *str2);
//static int	ft_checksign(const char *str);
void		ft_free(t_stack	*stack);
int			ft_lstsize(t_stack *stack);

// ------------------- push_swap --------------------
void		push_swap(t_stack *stack_a, t_stack *stack_b);
int			is_sort(t_stack *stack);

// ------------------- write_instru --------------------
void		write_sa(t_stack *stack_a);
void		write_sb(t_stack *stack_b);
void		write_ss(t_stack *stack_a, t_stack *stack_b);

// ------------------- do_instru --------------------
void		do_s(t_stack *stack);
t_stack		*do_p(t_stack *stack_x, t_stack *stack_y);
void		do_r(t_stack *stack);

// ------------------- check_error --------------------
int			ft_check_error(char **av);
int			check_nb(char **av);
int			check_int(char **av);

// ------------------- fill_stack --------------------
t_stack		*fill_stack_value(int ac, char **av);
t_stack		*stack_new(int nb);
void		stack_add_bottom(t_stack *stack, t_stack *new);

# endif