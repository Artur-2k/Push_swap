/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_targets.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:46:40 by artuda-s          #+#    #+#             */
/*   Updated: 2024/10/03 12:46:41 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_dlist	*find_target_a(t_stack stack_b, int num)
{
	t_dlist	*target_node;

	target_node = get_smaller(stack_b);
	if (num <= target_node->num)
		return (get_bigger(stack_b));
	while (stack_b.head != NULL)
	{
		if (stack_b.head->num < num && stack_b.head->num > target_node->num)
			target_node = stack_b.head;
		stack_b.head = stack_b.head->next;
	}
	return (target_node);
}

t_dlist	*find_target_b(t_stack stack_a, t_dlist node)
{
	t_dlist	*target;

	target = get_bigger(stack_a);
	if (target->num <= node.num)
		return (get_smaller(stack_a));
	while (stack_a.tail != NULL)
	{
		if (stack_a.tail->num > node.num && stack_a.tail->num < target->num)
			target = stack_a.tail;
		stack_a.tail = stack_a.tail->prev;
	}
	return (target);
}
