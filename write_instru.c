#include "push_swap.h"

/*
Ecrit sa puis fait s
*/
void	write_sa(t_stack *stack_a)
{
	write(1, "sa\n", 3);
	do_s(stack_a);
}

/*
Ecrit sb puis fait s
*/
void	write_sb(t_stack *stack_b)
{
	write(1, "sb\n", 3);
	do_s(stack_b);
}

/*
Ecrit ss puis fait ss
*/
void	write_ss(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "ss\n", 3);
	do_s(stack_a);
	do_s(stack_b);
}

/*
Ecrit pa puis fait pa, value de a sur b
*/
void	write_pa(t_stack *stack_a, t_stack *stack_b)
{
	write(1, "pa\n", 3);
	do_p(stack_a, stack_b);
}

void	write_pb(t_stack *stack_b, t_stack *stack_a)
{
	write(1, "pb\n", 3);
	do_p(stack_b, stack_a);
}