#include "../inc/push_swap.h"

void	place_target_a_at_top(t_stack *stack_a, t_dlist target)
{
	while (stack_a->tail->num != target.num)
	{
		if (target.above_medium)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
