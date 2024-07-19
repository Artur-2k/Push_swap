/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:19 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/19 19:03:54 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	check_arguments(ac, av);
	printf("Ok!\n");

	t_stack stack_a;
	t_stack stack_b;

	stack_a.head = NULL;
	stack_a.tail = NULL;
	stack_a.size = 0;
	stack_b.head = NULL;
	stack_b.tail = NULL;
	stack_b.size = 0;

	int i = 1;
	while (i < ac)
	{
		insert_at_head(&stack_a, ft_atoi(av[i]));
		i++;
	}

	print_list(stack_a.head);


	free_list(&stack_a.head);
	free_list(&stack_b.head);
	return (0);
}
