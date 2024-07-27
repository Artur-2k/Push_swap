#include "../inc/push_swap.h"

static void	rot_same_way(t_stack *stack_a, t_stack *stack_b, t_dlist cheap, \
						t_dlist targ)
{
	if (cheap.above_medium)
	{
		while (stack_a->tail->num != cheap.num && \
				stack_b->tail->num != targ.num)
			rr(stack_a, stack_b);
		while (stack_a->tail->num != cheap.num)
			ra(stack_a);
		while (stack_b->tail->num != targ.num)
			rb(stack_b);
	}
	else
	{
		while (stack_a->tail->num != cheap.num && \
				stack_b->tail->num != targ.num)
			rrr(stack_a, stack_b);
		while (stack_a->tail->num != cheap.num)
			rra(stack_a);
		while (stack_b->tail->num != targ.num)
			rrb(stack_b);
	}
}

static void	rot_both_then_b(t_stack *stack_a, t_stack *stack_b, t_dlist cheap, \
							t_dlist targ)
{
	if (cheap.above_medium)
	{
		while (stack_a->tail->num != cheap.num && \
				stack_b->tail->num != targ.num)
			rr(stack_a, stack_b);
		while (stack_b->tail->num != targ.num)
			rb(stack_b);
	}
	else
	{
		while (stack_a->tail->num != cheap.num && \
				stack_b->tail->num != targ.num)
			rrr(stack_a, stack_b);
		while (stack_b->tail->num != targ.num)
			rrb(stack_b);
	}
}

static void	rot_both_then_a(t_stack *stack_a, t_stack *stack_b, t_dlist cheap, \
							t_dlist targ)
{
	if (targ.above_medium)
	{
		while (stack_a->tail->num != cheap.num && \
				stack_b->tail->num != targ.num)
			rr(stack_a, stack_b);
		while (stack_a->tail->num != cheap.num)
			ra(stack_a);
	}
	else
	{
		while (stack_a->tail->num != cheap.num && \
				stack_b->tail->num != targ.num)
			rrr(stack_a, stack_b);
		while (stack_a->tail->num != cheap.num)
			rra(stack_a);
	}
}

static void	rot_diff_way(t_stack *stack_a, t_stack *stack_b, t_dlist cheap, \
						t_dlist targ)
{
	if (cheap.above_medium)
	{
		while (stack_a->tail->num != cheap.num)
			ra(stack_a);
		while (stack_b->tail->num != targ.num)
			rrb(stack_b);
	}
	else
	{
		while (stack_a->tail->num != cheap.num)
			rra(stack_a);
		while (stack_b->tail->num != targ.num)
			rb(stack_b);
	}
}

void	place_at_top(t_stack *stk_a, t_stack *stk_b, t_dlist cheap, \
					t_dlist targ)
{
	if (cheap.above_medium == targ.above_medium)
		rot_same_way(stk_a, stk_b, cheap, targ);
	else
	{
		if (cheap.rot_both == 1)
		{
			if (cheap.cost < targ.cost)
				rot_both_then_b(stk_a, stk_b, cheap, targ);
			else
				rot_both_then_a(stk_a, stk_b, cheap, targ);
		}
		else
			rot_diff_way(stk_a, stk_b, cheap, targ);
	}
}
