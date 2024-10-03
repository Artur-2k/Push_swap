/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_target_a_at_top.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:46:47 by artuda-s          #+#    #+#             */
/*   Updated: 2024/10/03 12:46:48 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	place_target_a_at_top(t_stack *stack_a, t_dlist target)
{
	while (stack_a->tail->num != target.num)
	{
		if (target.above_medium)
			ra(stack_a);
		else
			rra(stack_a);
	}
}
