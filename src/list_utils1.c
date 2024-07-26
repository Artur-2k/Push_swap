/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:47:17 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/26 14:13:09 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//* allocate memory for a new node and assing its num
t_dlist	*create_node(int num)
{
	t_dlist	*new_node;

	new_node = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new_node)
		return (ft_printf("Malloc error!\n"), NULL);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->target = NULL;
	new_node->num = num;
	return (new_node);
}

//* insert at head
//* used to read input arg
void	insert_at_head(t_stack *stack, int num)
{
	t_dlist	*new_node;

	new_node = create_node(num);
	if (stack->head)
	{
		new_node->next = stack->head;
		stack->head->prev = new_node;
		stack->head = new_node;
	}
	else
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	stack->size++;
}

//* insert at head
//* push to stack
void	push(t_stack *stack, int num)
{
	t_dlist	*new_node;

	new_node = create_node(num);
	if (stack->tail)
	{
		(stack->tail)->next = new_node;
		new_node->prev = stack->tail;
		stack->tail = new_node;
	}
	else
	{
		stack->head = new_node;
		stack->tail = new_node;
	}
	stack->size++;
}

//* removes the last node (tail)
//* pop from stack
void	pop(t_stack *stack)
{
	t_dlist	*preview;

	preview = (stack->tail)->prev;
	if ((stack->tail)->prev != NULL)
	{
		free(stack->tail);
		preview->next = NULL;
		stack->tail = preview;
	}
	else
	{
		free(stack->tail);
		stack->head = NULL;
		stack->tail = NULL;
	}
	stack->size--;
}

void	remove_head(t_stack *stack)
{
	t_dlist	*next;

	next = NULL;
	if ((stack->head)->next != NULL)
	{
		next = (stack->head)->next;
		free(stack->head);
		next->prev = NULL;
		stack->head = next;
	}
	else
	{
		free(stack->head);
		stack->head = NULL;
		stack->tail = NULL;
	}
	stack->size--;
}
