#include "../inc/push_swap.h"

static void	get_single_cost(t_stack *stk_a, t_stack *stk_b, t_dlist *cur)
{
	if (cur->above_medium)
		cur->cost = stk_a->size - cur->index;
	else
		cur->cost = cur->index;
	if (cur->target->above_medium)
		cur->target->cost = stk_b->size - cur->target->index;
	else
		cur->target->cost = cur->target->index;
}

static int	cost_curr_lt_tar(t_stack *stack_b, t_dlist *current)
{
	int	temp_cost;
	int	temp_idx;

	temp_cost = current->cost;
	if (current->above_medium)
		temp_idx = current->target->index + current->cost;
	else
		temp_idx = current->target->index - current->cost;
	if (temp_idx > stack_b->size / 2)
		temp_cost += stack_b->size - temp_idx;
	else
		temp_cost += temp_idx;
	return (temp_cost);
}

static int	cost_curr_gt_tar(t_stack *stack_a, t_dlist *current)
{
	int	temp_cost;
	int	temp_idx;

	temp_cost = current->target->cost;
	if (current->target->above_medium)
		temp_idx = current->index + current->target->cost;
	else
		temp_idx = current->index - current->target->cost;
	if (temp_idx > stack_a->size / 2)
		temp_cost += stack_a->size - temp_idx;
	else
		temp_cost += temp_idx;
	return (temp_cost);
}

static int	get_optimal_cost(t_stack *stk_a, t_stack *stk_b, t_dlist *cur)
{
	int	total_cost;
	int	temp_cost;

	total_cost = cur->cost + cur->target->cost;
	if (cur->cost < cur->target->cost)
		temp_cost = cost_curr_lt_tar(stk_b, cur);
	else
		temp_cost = cost_curr_gt_tar(stk_a, cur);
	if (temp_cost < total_cost)
	{
		total_cost = temp_cost;
		cur->rot_both = 1;
	}
	return (total_cost);
}

t_dlist	*find_cheapest_a(t_stack *stack_a, t_stack *stack_b)
{
	t_dlist	*cheapest;
	t_dlist	*current;
	int		total_cost;
	int		best_cost;

	best_cost = INT_MAX;
	current = stack_a->tail;
	while (current != NULL)
	{
		current->target = find_target_a(*stack_b, current->num);
		current->rot_both = 0;
		get_single_cost(stack_a, stack_b, current);
		if (current->above_medium == current->target->above_medium)
			total_cost = ft_get_max(current->cost, current->target->cost);
		else
			total_cost = get_optimal_cost(stack_a, stack_b, current);
		if (total_cost < best_cost)
		{
			best_cost = total_cost;
			cheapest = current;
		}
		current = current->prev;
	}
	return (cheapest);
}
