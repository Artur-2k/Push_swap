/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:47:17 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/26 14:10:00 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//* swaps the data from node1 and node2
//* keeps the list structure the same
void	swap_data(t_dlist **node1, t_dlist **node2)
{
	int	temp;

	temp = (*node1)->num;
	(*node1)->num = (*node2)->num;
	(*node2)->num = temp;
}

void	update_index(t_stack *stack)
{
	int		index;
	int		medium;
	t_dlist	*current;

	current = stack->head;
	medium = stack->size / 2;
	index = 1;
	while (current != NULL)
	{
		current->index = index++;
		if (index > medium)
			current->above_medium = 1;
		else
			current->above_medium = 0;
		current = current->next;
	}
}

t_dlist	*get_smaller(t_stack stack)
{
	t_dlist	*smaller_node;

	if (!stack.head)
		return (0);
	smaller_node = stack.head;
	while (stack.head != NULL)
	{
		if (smaller_node->num > stack.head->num)
			smaller_node = stack.head;
		stack.head = stack.head->next;
	}
	return (smaller_node);
}

t_dlist	*get_bigger(t_stack stack)
{
	t_dlist	*bigger_node;

	if (!stack.head)
		return (0);
	bigger_node = stack.head;
	while (stack.head != NULL)
	{
		if (bigger_node->num < stack.head->num)
			bigger_node = stack.head;
		stack.head = stack.head->next;
	}
	return (bigger_node);
}

int	is_sorted(t_stack stack)
{
	if (stack.head == NULL)
		return (0);
	while (stack.head->next != NULL)
	{
		if (stack.head->num < stack.head->next->num)
			return (0);
		stack.head = stack.head->next;
	}
	return (1);
}
