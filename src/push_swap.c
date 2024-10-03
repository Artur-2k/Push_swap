/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:46:59 by artuda-s          #+#    #+#             */
/*   Updated: 2024/10/03 12:47:04 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stacks(t_stack *stack_a, t_stack *stack_b, int	*numbers, int count)
{
	int	i;

	i = 0;
	stack_a->head = NULL;
	stack_a->tail = NULL;
	stack_a->size = 0;
	stack_b->head = NULL;
	stack_b->tail = NULL;
	stack_b->size = 0;
	while (i < count)
		insert_at_head(stack_a, numbers[i++]);
	return ;
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*numbers;
	int		count;

	if (ac < 2)
		error_exit();
	numbers = parse_arguments(ac, av, &count);
	init_stacks(&stack_a, &stack_b, numbers, count);
	if (!is_sorted(stack_a))
	{
		if (stack_a.size == 2)
			sa(&stack_a);
		else if (stack_a.size == 3)
			sort_three(&stack_a);
		else
			turk_algorithm(&stack_a, &stack_b);
	}
	free_last_resources(numbers, stack_a.head, stack_b.head);
	return (0);
}
