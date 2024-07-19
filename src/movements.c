/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:47:23 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/19 18:42:31 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Swaps the last two of the stack a integers with swap_data
// User must pass the correct parameters
void    sa(t_stack *stack_a)
{
	if (!stack_a->tail || !stack_a->tail->prev)
		return ;
	swap_data(&stack_a->tail, &stack_a->tail->prev);
}

// Swaps the last two of the stack a integers with swap_data
// User must pass the correct parameters
void    sb(t_stack *stack_b)
{
	if (!stack_b->tail || !stack_b->tail->prev)
		return ;
	swap_data(&stack_b->tail, &stack_b->tail->prev);
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
	else
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
	else
		return ;
}

// Rotates stack a one position up (head becomes tail)
// Pushes head to tail and pops head and updates it.
// User must pass the correct parameters
void	ra(t_stack *stack_a)
{
	if (stack_a->size > 1)
	{
		push(stack_a, stack_a->head->num);
		remove_head(stack_a);
	}
	else
		return ;
}
// Rotates stack a one position up (head becomes tail)
// Pushes head to tail and pops head and updates it.
// User must pass the correct parameters
void	rb(t_stack *stack_b)
{
	if (stack_b->size > 1)
	{
		push(stack_b, stack_b->head->num);
		remove_head(stack_b);
	}
	else
		return ;
}
// ra and rb basically
// User must pass the correct parameters
void	rr(t_stack *stack_a, t_stack *stack_b)
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
	return ;
}

// Rotates stack a one position down (tail becomes head)
// Inserts tail node before head and updates it and pops tail and updates it.
// User must pass the correct parameters
void	rra(t_stack *stack_a)
{
	if (stack_a->size > 1)
	{
		insert_at_head(stack_a, stack_a->tail->num);
		pop(stack_a);
	}
	else
		return ;
}

// Rotates stack a one position down (tail becomes head)
// Inserts tail node before head and updates it and pops tail and updates it.
// User must pass the correct parameters
void	rrb(t_stack *stack_b)
{
	if (stack_b->size > 1)
	{
		insert_at_head(stack_b, stack_b->tail->num);
		pop(stack_b);
	}
	else
		return ;
}


// rra and rrb basically
// User must pass the correct parameters
void rrr(t_stack *stack_a, t_stack *stack_b)
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
	return ;
}