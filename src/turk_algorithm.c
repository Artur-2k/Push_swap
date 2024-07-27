#include "../inc/push_swap.h"

void	sort_three(t_stack *stack_a)
{
	t_dlist	*bigger;

	bigger = get_bigger(*stack_a);
	if (bigger->num == stack_a->tail->num)
		ra(stack_a);
	else if (bigger->num == stack_a->tail->prev->num)
		rra(stack_a);
	if (stack_a->tail->num > stack_a->tail->prev->num)
		sa(stack_a);
}

static void	rev_sort_in_b(t_stack *stack_a, t_stack *stack_b)
{
	t_dlist	*cheapest;

	while (stack_a->size > 3 && !is_sorted(*stack_a))
	{
		update_index(stack_a);
		update_index(stack_b);
		cheapest = find_cheapest_a(stack_a, stack_b);
		place_at_top(stack_a, stack_b, *cheapest, *cheapest->target);
		pb(stack_a, stack_b);
	}
}

static void	sort_in_a(t_stack *stack_a, t_stack *stack_b)
{
	t_dlist	*target;

	while (stack_b->size > 0)
	{
		update_index(stack_a);
		update_index(stack_b);
		target = find_target_b(*stack_a, *stack_b->tail);
		place_target_a_at_top(stack_a, target);
		pa(stack_a, stack_b);
	}
}

static void	put_correct_order_a(t_stack *stack_a)
{
	t_dlist	*smaller;

	update_index(stack_a);
	smaller = get_smaller(*stack_a);
	while (stack_a->tail->num != smaller->num)
	{
		if (smaller->above_medium)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

void	turk_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 3)
		pb(stack_a, stack_b);
	if (stack_a->size > 3)
		pb(stack_a, stack_b);
	rev_sort_in_b(stack_a, stack_b);
	sort_three(stack_a);
	sort_in_a(stack_a, stack_b);
	put_correct_order_a(stack_a);
}
