/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:10:08 by mapoirie          #+#    #+#             */
/*   Updated: 2023/06/29 11:48:47 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

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

// --------------------- checker -----------------------
int			count_av(char **av2);
void		free_av2(char **av2);
t_stack		*argv_is_2(char **av);
void		ft_sorted(t_stack **stack_a, t_stack **stack_b);
int			main(int ac, char **av);

// --------------------- get_next_line -------------------
char		*get_next_line(int fd);
char		*ft_line_maker(int fd, char *buf, char *storage);
int			ft_check(char *storage);
char		*ft_line_extract(char *line);

// --------------------- checker_utils -------------------
void		ft_free(t_stack	*stack);
int			ft_lstsize(t_stack *stack);
char		*ft_strdup(const char *s);
char		*ft_strjoin(char const *s1, char const *s2);

// --------------------- checker_utils2 -------------------
int			ft_strcmp(char *str1, char *str2);
int			ft_checksign(const char *str);
int long	ft_atoi(const char *str);

// ------------------ checker_check_error ----------------
int			check_double(char **av);
int			check_int(char **av);
int			check_nb(char **av);
int			check_single(char **av);
int			ft_check_error(char **av);

// --------------------- checker_error -------------------
void		error_free_quite(t_stack **stack_a, t_stack **stack_b);
void		error_and_quite(void);

// ------------------------ split ------------------------
size_t		ft_strlen(const char *s);
char		*ft_copyword(char *av, int i_begin, int i_end);
int			ft_countwords(char *av);
char		**ft_split2(char *av, char **new_str);
char		**ft_split(char *av);

// --------------------- fill_stack ----------------------
void		stack_add_bottom(t_stack *stack, t_stack *new);
t_stack		*stack_new(int nb);
t_stack		*fill_stack_value(int ac, char **av);

// ------------------- do_instru --------------------
void		do_s(t_stack **stack);
void		push(int value_to_push, t_stack **dest);
void		pop(t_stack **src);
void		do_p(t_stack **src, t_stack **dest);

// ------------------- do_instru2 --------------------
void		do_r(t_stack **stack);
t_stack		*stack_bottom(t_stack *stack);
void		do_rr(t_stack **stack);

// --------------------- chercker_start -------------------
void		before_do_rrr(t_stack **stack_a, t_stack **stack_b);
void		before_do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_instru(char *instru, t_stack **stack_a, t_stack **stack_b);
int			check_pile(t_stack **stack_a, t_stack **stack_b);
void		start_checker(t_stack **stack_a, t_stack **stack_b);

#endif