/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:19 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/21 22:36:41 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	find_target(t_stack stack, int num)
{
    int	target;

    target = get_smaller(stack);
    if (num <= target)
        return (get_bigger(stack));
    while (stack.head != NULL)
    {
        if( stack.head->num < num && stack.head->num > target)
            target = stack.head->num;
        stack.head = stack.head->next;
    }
    return (target);
}

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


int	main(int ac, char **av)
{
	t_stack stack_a;
	t_stack stack_b;
	check_arguments(ac, av);
	printf("Ok args!\n");

	init_stacks(&stack_a, &stack_b, ac, av);
	printf("list read from args:\n");
	print_list(stack_a.head); //todo deleteme



	free_list(&stack_a.head);
	free_list(&stack_b.head);
	return (0);
}
