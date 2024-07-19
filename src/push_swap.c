/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:19 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/19 21:51:15 by artuda-s         ###   ########.fr       */
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
	while (i < ac)
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
