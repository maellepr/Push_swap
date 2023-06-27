/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:56:18 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/27 09:10:50 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				pos;
	int				cost;
	struct s_stack	*next;
}	t_stack;

// ------------------- push_swap --------------------
int			main(int ac, char **av);
int			count_av(char **av2);
t_stack		*argv_is_2(char **av);
void		push_swap(t_stack **stack_a, t_stack **stack_b);

// ---------------------- split ---------------------
size_t		ft_strlen(const char *s);
char		*ft_copyword(char *av, int i_begin, int i_end);
int			ft_countwords(char *av);
char		**ft_split2(char *av, char **new_str);
char		**ft_split(char *av);

// ------------------- sort_big ----------------------
void		sort(t_stack **stack_a, t_stack **stack_b, int pos, int val);
void		pos_to_sort(t_stack **stack_a, t_stack **stack_b);
void		sort_a(t_stack **stack_a);
void		sort_big(t_stack **stack_a, t_stack **stack_b);

// ------------------- sort_big2 ----------------------
void		push_allb(t_stack **stack_a, t_stack **stack_b, int max, int med);
int			cost_b(int middle, int pos_nb, t_stack **stack_b);
int			cost_a(int nb_sta_b, t_stack **stack_a);
void		calcul_cost(t_stack **stack_a, t_stack **stack_b);
int			find_maj(t_stack **stack_a, int valuetopush);

//---------------------- sort_3 -----------------------
void		sort_3_do(t_stack **stack_a, int min_pos, int max_pos);
void		sort_3(t_stack **stack_a);

//-------------------- sort_small ---------------------
void		sort_small(t_stack **stack_a, t_stack **stack_b);

// ------------------- do_instru --------------------
void		do_s(t_stack **stack);
void		push(int value_to_push, t_stack **dest);
void		pop(t_stack **src);
void		do_p(t_stack **src, t_stack **dest);

// ------------------- do_instru2 --------------------
void		do_r(t_stack **stack);
t_stack		*stack_bottom(t_stack *stack);
void		do_rr(t_stack **stack);

// ------------------- write_instru --------------------
void		write_sa(t_stack **stack_a);
void		write_sb(t_stack **stack_b);
void		write_ss(t_stack **stack_a, t_stack **stack_b);
void		write_pa(t_stack **stack_a, t_stack **stack_b);
void		write_pb(t_stack **stack_a, t_stack **stack_b);

// ------------------- write_instru2 --------------------
void		write_ra(t_stack **stack_a);
void		write_rb(t_stack **stack_b);
void		write_rr(t_stack **stack_a, t_stack **stack_b);

// ------------------- write_instru3 --------------------
void		error_and_quite(void);
void		write_rra(t_stack **stack_a);
void		write_rrb(t_stack **stack_b);
void		write_rrr(t_stack **stack_a, t_stack **stack_b);

// ------------------- fill_stack --------------------
void		stack_add_bottom(t_stack *stack, t_stack *new);
t_stack		*stack_new(int nb);
t_stack		*fill_stack_value(int ac, char **av);

// ------------------- check_error --------------------
int			check_double(char **av);
int			check_int(char **av);
int			check_nb(char **av);
int			check_single(char **av);
int			ft_check_error(char **av);

// ------------------- swap_utils --------------------
int			ft_lstsize(t_stack *stack);
void		ft_free(t_stack	*stack);
int			ft_strcmp(char *str1, char *str2);
int			ft_checksign(const char *str);
int long	ft_atoi(const char *str);

// ------------------- swap_utils2 --------------------
int			get_max(t_stack **stack);
int			get_min(t_stack **stack);
int			*make_tab(t_stack **stack, int size);
int			calcul_med(int *tab, int size);
int			sort_tab_find_med(int *tab, int size);

// ------------------- swap_utils2 --------------------
void		ft_swap(int *a, int *b);
int			is_sort(t_stack **stack);
void		assign_pos(t_stack **stack);
int			get_pos(t_stack **stack, int value);
int			get_median(t_stack **stack);

#endif