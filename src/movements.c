/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:47:23 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/18 18:21:36 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Swaps the last two of the stack a integers with swap_data
// User must pass the correct parameters
void    sa(t_dlist **tail_a, t_dlist **tail_prev_a)
{
    swap_data(tail_a, tail_prev_a);
}
// Swaps the last two of the stack a integers with swap_data
// User must pass the correct parameters
void    sb(t_dlist **tail_b, t_dlist **tail_prev_b)
{
    swap_data(tail_b, tail_prev_b);
}
// Swaps the last two of the stack a and b integers with swap_data
// User must pass the correct parameters
void	ss(t_dlist **tail_a, t_dlist **tail_prev_a, t_dlist **tail_b, t_dlist **tail_prev_b)
{
	swap_data(tail_a, tail_prev_a);
	swap_data(tail_b, tail_prev_b);
}

// Adds the tail from stack b to a and removes tail from b
// User must pass the correct parameters
void	pa(t_dlist **tail_a, t_dlist **head_a, t_dlist **tail_b, t_dlist **head_b)
{
	push(tail_a, head_a, (*tail_b)->num);
	pop(tail_b, head_b);
}

// Adds the tail from stack a to b and removes tail from a
// User must pass the correct parameters
void	pb(t_dlist **tail_b, t_dlist **head_b, t_dlist **tail_a, t_dlist **head_a)
{
	push(tail_b, head_b, (*tail_a)->num);
	pop(tail_a, head_a);
}

// Rotates stack a one position up (head becomes tail)
// Pushes head to tail and pops head and updates it.
// User must pass the correct parameters
void	ra(t_dlist **head_a, t_dlist **tail_a)
{
	push(tail_a, head_a, (*head_a)->num);
	remove_head(head_a, tail_a);
}
// Rotates stack a one position up (head becomes tail)
// Pushes head to tail and pops head and updates it.
// User must pass the correct parameters
void	rb(t_dlist **head_b, t_dlist **tail_b)
{
	push(tail_b, head_b, (*head_b)->num);
	remove_head(head_b, tail_b);
}
// ra and rb basically
// User must pass the correct parameters
void	rr(t_dlist **head_a, t_dlist **tail_a, t_dlist **head_b, t_dlist **tail_b)
{
	push(tail_a, head_a, (*head_a)->num);
	remove_head(head_a, tail_a);
	push(tail_b, head_b, (*head_b)->num);
	remove_head(head_b, tail_b);
}

// Rotates stack a one position down (tail becomes head)
// Inserts tail node before head and updates it and pops tail and updates it.
// User must pass the correct parameters
void	rra(t_dlist **head_a, t_dlist **tail_a)
{
	insert_at_head(head_a, tail_a, (*tail_a)->num);
	pop(tail_a, head_a);
}

// Rotates stack a one position down (tail becomes head)
// Inserts tail node before head and updates it and pops tail and updates it.
// User must pass the correct parameters
void	rrb(t_dlist **head_b, t_dlist **tail_b)
{
	insert_at_head(head_b, tail_b, (*tail_b)->num);
	pop(tail_b, head_b);
}

// rra and rrb basically
// User must pass the correct parameters
void rrr(t_dlist **head_a, t_dlist **tail_a, t_dlist **head_b, t_dlist **tail_b)
{
	insert_at_head(head_a, tail_a, (*tail_a)->num);
	pop(tail_a, head_a);
	insert_at_head(head_b, tail_b, (*tail_b)->num);
	pop(tail_b, head_b);
}