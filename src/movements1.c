/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:47:23 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/26 14:21:30 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Swaps the last two of the stack a integers with swap_data
// User must pass the correct parameters
void	sa(t_stack *stack_a)
{
	if (!stack_a->tail || !stack_a->tail->prev)
		return ;
	swap_data(&stack_a->tail, &stack_a->tail->prev);
	ft_printf("sa\n");
	return ;
}

// Swaps the last two of the stack a integers with swap_data
// User must pass the correct parameters
void	sb(t_stack *stack_b)
{
	if (!stack_b->tail || !stack_b->tail->prev)
		return ;
	swap_data(&stack_b->tail, &stack_b->tail->prev);
	ft_printf("sb\n");
	return ;
}

// Swaps the last two of the stack a and b integers with swap_data
// User must pass the correct parameters
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a->tail || !stack_a->tail->prev)
		return ;
	if (!stack_b->tail || !stack_b->tail->prev)
		return ;
	swap_data(&stack_a->tail, &stack_a->tail->prev);
	swap_data(&stack_b->tail, &stack_b->tail->prev);
	ft_printf("ss\n");
	return ;
}

// Adds the tail from stack b to a and removes tail from b
// User must pass the correct parameters
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->tail)
	{
		push(stack_a, stack_b->tail->num);
		pop(stack_b);
	}
	ft_printf("pa\n");
	return ;
}

// Adds the tail from stack a to b and removes tail from a
// User must pass the correct parameters
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->tail)
	{
		push(stack_b, stack_a->tail->num);
		pop(stack_a);
	}
	ft_printf("pb\n");
	return ;
}
