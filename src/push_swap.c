/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:19 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/23 16:35:17 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stacks(t_stack *stack_a, t_stack *stack_b, int ac, char ** av)
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

t_dlist	*find_target(t_stack stack, int num)
{
	t_dlist *target_node;

	target_node = get_smaller(stack);
    if (num <= target_node->num)
        return (get_bigger(stack));
    while (stack.head != NULL)
    {
        if( stack.head->num < num && stack.head->num > target_node->num)
			target_node = stack.head;
        stack.head = stack.head->next;
    }
    return (target_node);
}

t_dlist *find_cheapest(t_stack *stack_a, t_stack *stack_b)
{
	t_dlist *current;
	t_dlist	*cheapeast;
	int		cost_a;
	int		cost_b;
	int		lower_cost = stack_a->size + stack_b->size; //todo better solution for this

	//todo maybe update index on main sort algorithm
	update_index(stack_a);
	update_index(stack_b);

	current = stack_a->tail;
	while (current != NULL)
	{
		current->target = find_target(*stack_b, current->num);
		//cost a
		if (current->above_medium)
			cost_a = stack_a->size - current->index - 1;
		else
			cost_a = current->index + 1;
		//cost b

		if (current->target->above_medium)
			cost_b = stack_b->size - current->target->index - 1;
		else
			cost_b = current->target->index + 1;
		// cheapeast update
		if (cost_a + cost_b < lower_cost)
		{
			lower_cost = cost_a + cost_b;
			cheapeast = current;
		}
		//next value check
		current = current->prev;
	}
	return (cheapeast);
}

void	place_at_top(t_stack *stack_a, t_stack *stack_b, t_dlist node_a, t_dlist node_b)
{
	while (stack_a->tail->num != node_a.num && stack_b->tail->num != node_b.num)
	{
		if (node_a.above_medium && node_b.above_medium)
			rrr(stack_a, stack_b); // shifts stack up (tail becomes head)
		else if (!node_a.above_medium && !node_b.above_medium)
			rr(stack_a, stack_b); // shifts down (head becomes tail)
		else
			break ;
	}
	while (stack_a->tail->num != node_a.num || stack_b->tail->num != node_b.num)
	{
		if (stack_a->tail->num != node_a.num)
		{
			if (node_a.above_medium)
				ra(stack_a);
			else
				rra(stack_a);
		}
		if (stack_b->tail->num != node_b.num )
		{
			if (node_b.above_medium)
				rb(stack_b);
			else
				rrb(stack_b);
		}
	}
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

int	main(int ac, char **av)
{
    t_stack stack_a;
    t_stack stack_b;

	check_arguments(ac, av);
	printf("args ok\n");

    init_stacks(&stack_a, &stack_b, ac, av);
	printf("lista A :  ");print_list(stack_a.head);
	printf("lista B :  " );print_list(stack_b.head); printf("\n");

	// move from a to b


	t_dlist *chepeast;
	t_dlist *big;

	// push 2 to b
	if (stack_a.size > 3)
		pb(&stack_a, &stack_b);
	if (stack_a.size > 3)
		pb(&stack_a, &stack_b);

	// if stack size > 3 and is not sorted
	while (stack_a.size > 3 && !is_sorted(stack_a))
	{
		chepeast = find_cheapest(&stack_a, &stack_b);
		place_at_top(&stack_a, &stack_b, *chepeast, (*chepeast->target));
		pb(&stack_a, &stack_b);
	}

	// sort stack b putting it in the right order
	big = get_bigger(stack_b);
	while (big->num != stack_b.tail->num)
	{
		if (big->above_medium)
			rb(&stack_b);
		else
			rrb(&stack_b);
	}

	// sort stack a if size == 3 and is not sorted
	if (stack_a.size == 3 && !is_sorted(stack_a))
		sort_three(&stack_a);


	// move from b to a

	




    free_list(&stack_a.head);
    free_list(&stack_b.head);
    return (0);
}