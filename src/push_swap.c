/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:17:19 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/17 20:45:40 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
troca os 2 do topo (tails)
sa	swap_data(&current_a, &(current_a->next));
sb	swap_data(&current_b, &(current_b->next));
ss  swap_data(&current_a, &(current_a->next)); swap_data(&current_b, &(current_b->next));

tira o do topo de um e mete no topo de outro
pa	push(&tail_a, &head_a, (*tail_b)->num); pop(&tail_b, &head_b);
pb	push(&tail_a, &head_a, (*tail_b)->num); pop(&tail_b, &head_b);

muda a posicao um para cima 
(o do topo passa para baixo)
ra	
rb
rr

muda a posicao um para baix 
(o do baixo passa para topo)
rra
rrb
rrr

*/

int	main(int ac, char **av)
{
    t_dlist	*head = NULL;
    t_dlist	*tail = NULL;

	check_arguments(ac, av);
	printf("Ok!\n");
	return (0);
}