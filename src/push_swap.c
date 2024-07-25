/* ************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:19 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/24 21:05:44 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************** */

#include "../inc/push_swap.h"

void	init_stacks(t_stack *stack_a, t_stack *stack_b, int ac, char **av)
{
	int i;

	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_b->size = 0;
	i = 1;

	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		i = 0;
	}
	while (av[i] != NULL)
		insert_at_head(stack_a, ft_atoi(av[i++]));
	return ;
}

void	handle_error(void) // todo
{

}

void	sort_three(t_stack *stack_a)
{
	t_dlist *bigger;

	bigger = get_bigger(*stack_a);
	if (bigger->num == stack_a->tail->num)
		ra(stack_a);
	else if (bigger->num == stack_a->tail->prev->num)
		rra(stack_a);
	if (stack_a->tail->num > stack_a->tail->prev->num)
		sa(stack_a);
}


t_dlist	*find_target_a(t_stack stack_b, int num)
{
	t_dlist *target_node;

   if (!stack_b.head)
        return NULL;

	target_node = get_smaller(stack_b);
    if (num <= target_node->num)
        return (get_bigger(stack_b));
    while (stack_b.head != NULL)
    {
        if( stack_b.head->num < num && stack_b.head->num > target_node->num)
			target_node = stack_b.head;
        stack_b.head = stack_b.head->next;
    }
    return (target_node);
}

t_dlist	*find_cheapest_a(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->head || !stack_b->head)
		handle_error(); // todo

	t_dlist *cheapest = NULL;
	int totalCost = 0;
	int bestCost = INT_MAX;


	t_dlist *current = stack_a->tail;
	while (current != NULL)
	{
		current->target = find_target_a(*stack_b, current->num);
		current->rot_both = 0;	
		//cost a
		if (current->above_medium)
			current->cost = stack_a->size - current->index;
		else
			current->cost = current->index;

		//cost b
		if (current->target->above_medium)
			current->target->cost = stack_b->size - current->target->index;
		else
			current->target->cost = current->target->index;

		//optimal cost with rr and rrr
		if ((current->above_medium && current->target->above_medium) || // 1 1
		    (!current->above_medium && !current->target->above_medium)) // 0 0
		{
		    totalCost = ft_get_max(current->cost, current->target->cost);
		}
		else // 1 0 or 0 1
		{
			totalCost = current->cost + current->target->cost; // seperate cost
			int tempCost = 0;
			int tempIdx;

			if (current->cost < current->target->cost)
			{
				tempCost = current->cost;
				if (current->above_medium)
					tempIdx = current->target->index + current->cost;
				else
					tempIdx = current->target->index - current->cost;
				if (tempIdx > stack_b->size / 2)
					tempCost = tempCost + stack_b->size - tempIdx;
				else
					tempCost = tempCost + tempIdx;
			}
			else
			{
				tempCost = current->target->cost;
				if (current->target->above_medium)
					tempIdx = current->index + current->target->cost;
				else
					tempIdx = current->index - current->target->cost;
				if (tempIdx > stack_a->size / 2)
					tempCost = tempCost + stack_a->size - tempIdx;
				else
					tempCost = tempCost + tempIdx;
			}

			if (tempCost < totalCost)
			{
				if (current->num == -485)
				totalCost = tempCost;
				current->rot_both = 1;
			}
			
		}	
		//update cost
		if (totalCost < bestCost)
		{
			bestCost = totalCost;
			cheapest = current;
		}
		
		//next node
		current = current->prev;
	}
	return (cheapest);
}





t_dlist	*find_target_b(t_stack stack_a, t_dlist node)
{
	t_dlist *target;

	if (!stack_a.head)
		handle_error(); //todo

	target = get_bigger(stack_a);
	if (target->num <= node.num)
		return (get_smaller(stack_a));

	while (stack_a.tail != NULL)
	{
		if (stack_a.tail->num > node.num && stack_a.tail->num < target->num)
			target = stack_a.tail;
		stack_a.tail = stack_a.tail->prev;
	}
	return (target);
}


void	place_at_top(t_stack *stack_a, t_stack *stack_b, t_dlist cheapest, t_dlist target)
{
	if (!stack_a || !stack_b )
		handle_error(); //todo

	int cheapVal = cheapest.num;
	int targetVal = target.num;

	if (cheapest.above_medium && target.above_medium)	// rr + ra/rb to top
	{
		while (stack_a->tail->num != cheapVal && stack_b->tail->num != targetVal)
			rr(stack_a, stack_b);
		while (stack_a->tail->num != cheapVal)
			ra(stack_a);
		while (stack_b->tail->num != targetVal)
			rb(stack_b);
	}
	else if (!cheapest.above_medium && !target.above_medium) // rrr + ra/rb to top
	{
		while (stack_a->tail->num != cheapVal && stack_b->tail->num != targetVal)
			rrr(stack_a, stack_b);
		while (stack_a->tail->num != cheapVal)
			rra(stack_a);
		while (stack_b->tail->num != targetVal)
			rrb(stack_b);
	}
	else
	{

		if (cheapest.rot_both == 1)
		{
			if (cheapest.cost < target.cost)
			{
				if (cheapest.above_medium)
				{
					while (stack_a->tail->num != cheapVal && stack_b->tail->num != targetVal)
						rr(stack_a, stack_b);
					while (stack_b->tail->num != targetVal)
						rb(stack_b);
				}
				else
				{
					while (stack_a->tail->num != cheapVal && stack_b->tail->num != targetVal)
						rrr(stack_a, stack_b);
					while (stack_b->tail->num != targetVal)
						rrb(stack_b);			
				}
			}
			else
			{
				if (target.above_medium)
				{
					while (stack_a->tail->num != cheapVal && stack_b->tail->num != targetVal)
						rr(stack_a, stack_b);
					while (stack_a->tail->num != cheapVal)
						ra(stack_a);
				}
				else
				{
					while (stack_a->tail->num != cheapVal && stack_b->tail->num != targetVal)
						rrr(stack_a, stack_b);
					while (stack_a->tail->num != cheapVal)
						rra(stack_a);		
				}
			}
		}
		else
		{
			if (cheapest.above_medium)
			{
				while (stack_a->tail->num != cheapVal)
					ra(stack_a);
			}
			else
			{
				while (stack_a->tail->num != cheapVal)
					rra(stack_a);
			}
			if (target.above_medium)
			{
				while (stack_b->tail->num != targetVal)
					rb(stack_b);
			}
			else
			{
				while (stack_b->tail->num != targetVal)
					rrb(stack_b);	
			}
		}
	}
	
}


void	place_target_a_at_top(t_stack *stack_a, t_dlist *target)
{
	if (!stack_a || !target)
		handle_error(); //todo

	while (stack_a->tail->num != target->num)
	{
		if (target->above_medium)
			ra(stack_a);
		else
			rra(stack_a);
	}
}


void	turk_algorithm(t_stack *stack_a, t_stack *stack_b)
{
	t_dlist *cheapest;

	// push 2 to b
	if (stack_a->size > 3)
		pb(stack_a, stack_b);
	if (stack_a->size > 3)
		pb(stack_a, stack_b);

	// if stack size > 3 and is not sorted
	while (stack_a->size > 3 && !is_sorted(*stack_a))
	{
		// updates indexes and above medium flags
		update_index(stack_a);
		update_index(stack_b);

		// finds the cheapest node to push to b and where it should be
		// cheapest is the node we're pushing and node.target is it's target
		cheapest = find_cheapest_a(stack_a, stack_b);

		// readys cheapest push
		// puts the cheapest node and its target at the top of both stacks
		place_at_top(stack_a, stack_b, *cheapest, *cheapest->target);
		
		// pushes cheapest to correct stack b position
		// pb pops a so it reduces stack_a.size by one each time
		pb(stack_a, stack_b);

	}


	sort_three(stack_a);



	while (stack_b->size > 0)
	{
		update_index(stack_a);
		update_index(stack_b);
		t_dlist *target = find_target_b(*stack_a, *stack_b->tail);
		place_target_a_at_top(stack_a, target);

		pa(stack_a, stack_b);
	}


	update_index(stack_a);
	t_dlist *smaller = get_smaller(*stack_a);
	int above_medium = smaller->above_medium;
	int num = smaller->num;
	while (stack_a->tail->num != num)
	{
		if (above_medium)
			ra(stack_a);
		else
			rra(stack_a);
	}
}

int	main(int ac, char **av)
{
    t_stack stack_a;
    t_stack stack_b;

	check_arguments(ac, av);

    init_stacks(&stack_a, &stack_b, ac, av);

	update_index(&stack_a);



//todo check 1 argument
 	if (!is_sorted(stack_a))
	{
		if (stack_a.size == 2)
			sa(&stack_a);
		else if(stack_a.size == 3)
			sort_three(&stack_a);
		else
			turk_algorithm(&stack_a, &stack_b);
	}



	if (stack_a.head)
	    free_list(&stack_a.head);
	if (stack_b.head)
	    free_list(&stack_b.head);
    return (0);
}