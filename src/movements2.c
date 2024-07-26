/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:20:47 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/26 14:22:14 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Rotates stack a one position down (tail becomes head)
// Inserts tail node before head and updates it and pops tail and updates it.
// User must pass the correct parameters
void	ra(t_stack *stack_a)
{
	if (stack_a->size > 1)
	{
		insert_at_head(stack_a, stack_a->tail->num);
		pop(stack_a);
	}
	ft_printf("ra\n");
	return ;
}

// Rotates stack a one position down (tail becomes head)
// Inserts tail node before head and updates it and pops tail and updates it.
// User must pass the correct parameters
void	rb(t_stack *stack_b)
{
	if (stack_b->size > 1)
	{
		insert_at_head(stack_b, stack_b->tail->num);
		pop(stack_b);
	}
	ft_printf("rb\n");
	return ;
}

// rra and rrb basically
// User must pass the correct parameters
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 1)
	{
		insert_at_head(stack_a, stack_a->tail->num);
		pop(stack_a);
	}
	if (stack_b->size > 1)
	{
		insert_at_head(stack_b, stack_b->tail->num);
		pop(stack_b);
	}
	ft_printf("rr\n");
	return ;
}
