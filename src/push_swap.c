/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:19 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/18 18:23:24 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int ac, char **av)
{
	check_arguments(ac, av);
	printf("Ok!\n");

	t_dlist	*head_a = NULL;
    t_dlist	*tail_a = NULL;
	push(&tail_a, &head_a, 1);
	push(&tail_a, &head_a, 2);
	push(&tail_a, &head_a, 3);
	push(&tail_a, &head_a, 4);
	push(&tail_a, &head_a, 5);

    t_dlist	*head_b = NULL;
    t_dlist	*tail_b = NULL;
	push(&tail_b, &head_b, 6);
	push(&tail_b, &head_b, 7);
	push(&tail_b, &head_b, 8);
	push(&tail_b, &head_b, 9);
	push(&tail_b, &head_b, 10);

	printf("LISTA A: ");
	print_list(head_a);
	printf("LISTA B: ");
	print_list(head_b);
	printf("\n\n");

	free_list(&head_a);
	free_list(&head_b);
	return (0);
}
