/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:19 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/22 22:24:08 by artuda-s         ###   ########.fr       */
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

t_dlist *find_cheapest(t_stack stack_a, t_stack stack_b)
{
	t_dlist *current;
	t_dlist	*cheapeast;
	int		cost_a;
	int		cost_b;
	int		lower_cost = stack_a.size + stack_b.size;

	update_index(&stack_a);
	update_index(&stack_b);

	current = stack_a.head;
	while (current != NULL)
	{
		current->target = find_target(stack_b, current->num);
		//cost a
		if (current->above_medium)
			cost_a = stack_a.size - current->index - 1;
		else
			cost_a = current->index + 1;
		//cost b
		if (current->target->above_medium)
			cost_b = stack_b.size - current->target->index - 1;
		else
			cost_b = current->target->index + 1;
		// cheapeast update
		if (cost_a + cost_b < lower_cost)
		{
			lower_cost = cost_a + cost_b;
			cheapeast = current;
		}
		//next value check
		current = current->next;
	}
	return (cheapeast);
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

	

    free_list(&stack_a.head);
    free_list(&stack_b.head);
    return (0);
}