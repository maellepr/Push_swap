#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> 

typedef struct s_stack
{
	int				value;
	int				pos;
	int				cost;// cout pour bouger un nb de la pile a a la pile b
	struct s_stack	*next;
}	t_stack;

// ------------------- swap_utils --------------------
int long	ft_atoi(const char *str);
int			ft_strcmp(char *str1, char *str2);
//static int	ft_checksign(const char *str);
void		ft_free(t_stack	*stack);
int			ft_lstsize(t_stack *stack);

// ------------------- swap_utils2 --------------------
int			get_max(t_stack **stack);
int			get_min(t_stack **stack);
int			*make_tab(t_stack **stack, int size);
int			sort_tab_find_med(int *tab, int size);
int			get_median(t_stack **stack);

//-------------------- sort_small ---------------------
void		sort_small(t_stack **stack_a, t_stack **stack_b);

//---------------------- sort_3 -----------------------
void		sort_3(t_stack **stack_a);

// ------------------- push_swap --------------------
void		assign_pos(t_stack **stack);
int			get_pos(t_stack **stack, int value);
void		push_swap(t_stack **stack_a, t_stack **stack_b);
int			is_sort(t_stack **stack);

// ------------------- write_instru --------------------
void		error_and_quite(void);
void		write_sa(t_stack **stack_a);
void		write_sb(t_stack **stack_b);
void		write_ss(t_stack **stack_a, t_stack **stack_b);
void		write_pa(t_stack **stack_a, t_stack **stack_b);
void		write_pb(t_stack **stack_a, t_stack **stack_b);
void		write_ra(t_stack **stack_a);
void		write_rb(t_stack **stack_b);
void		write_rr(t_stack **stack_a, t_stack **stack_b);
void		write_rra(t_stack **stack_a);
void		write_rrb(t_stack **stack_b);
void		write_rrr(t_stack **stack_a, t_stack **stack_b);

// ------------------- do_instru --------------------
void		do_s(t_stack **stack);
void		do_p(t_stack **src, t_stack **dest);
void		do_r(t_stack **stack);
void		do_rr(t_stack **stack);

// ------------------- check_error --------------------
int			ft_check_error(char **av);
int			check_nb(char **av);
int			check_int(char **av);

// ------------------- fill_stack --------------------
t_stack		*fill_stack_value(int ac, char **av);
t_stack		*stack_new(int nb);
void		stack_add_bottom(t_stack *stack, t_stack *new);

//--------------------- main --------------------------
void 		print_pile(t_stack *stack);

# endif