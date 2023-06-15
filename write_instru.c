#include "push_swap.h"

// /*
// Ecrit sa puis fait s
// */
void	write_sa(t_stack **stack_a)
{
	write(1, "sa\n", 3);
	do_s(stack_a);
}
/*
Ecrit sb puis fait s
*/
void	write_sb(t_stack **stack_b)
{
	write(1, "sb\n", 3);
	do_s(stack_b);
}
/*
Ecrit ss puis fait ss
*/
void	write_ss(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "ss\n", 3);
	do_s(stack_a);
	do_s(stack_b);
}

/*
Ecrit pa puis fait pa
*/
void	write_pa(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "pa\n", 3);
	do_p(stack_a, stack_b);
}
/*
Ecrit pb puis fait pb
*/
void	write_pb(t_stack **stack_b, t_stack **stack_a)
{
	write(1, "pb\n", 3);
	do_p(stack_b, stack_a);
}

/*
Ecrit ra puis fait do_r
*/
void	write_ra(t_stack **stack_a)
{
	write(1, "ra\n", 3);
	do_r(stack_a);
}
/*
Ecrit rb puis fait do_r
*/
void	write_rb(t_stack **stack_b)
{
	write(1, "rb\n", 3);
	do_r(stack_b);
}
/*
Ecrit rr puis fait deux fois d_r
*/
void	write_rr(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "rr\n", 3);
	do_r(stack_a);
	do_r(stack_b);
}

/*
Ecrit rra puis fait do_rr
*/
void	write_rra(t_stack **stack_a)
{
	write(1, "rra\n", 4);
	do_rr(stack_a);
}
/*
Ecrit rb puis fait do_r
*/
void	write_rrb(t_stack **stack_b)
{
	write(1, "rrb\n", 4);
	do_rr(stack_b);
}
/*
Ecrit rr puis fait deux fois d_rr
*/
void	write_rrr(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "rrr\n", 4);
	do_rr(stack_a);
	do_rr(stack_b);
}