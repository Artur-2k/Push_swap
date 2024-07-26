/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:22:45 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/26 14:22:46 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Rotates stack a one position up (head becomes tail)
// Pushes head to tail and pops head and updates it.
// User must pass the correct parameters
// Rotates stack a one position up (head becomes tail)
void	rra(t_stack *stack_a)
{
	if (stack_a->size > 1)
	{
		push(stack_a, stack_a->head->num);
		remove_head(stack_a);
	}
	ft_printf("rra\n");
	return ;
}

// Pushes head to tail and pops head and updates it.
// User must pass the correct parameters
void	rrb(t_stack *stack_b)
{
	if (stack_b->size > 1)
	{
		push(stack_b, stack_b->head->num);
		remove_head(stack_b);
	}
	ft_printf("rrb\n");
	return ;
}

// ra and rb basically
// User must pass the correct parameters
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size > 1)
	{
		push(stack_a, stack_a->head->num);
		remove_head(stack_a);
	}
	if (stack_b->size > 1)
	{
		push(stack_b, stack_b->head->num);
		remove_head(stack_b);
	}
	ft_printf("rrr\n");
	return ;
}
