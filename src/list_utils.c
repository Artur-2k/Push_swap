/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:47:17 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/19 18:34:38 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//* allocate memory for a new node and assing its num
t_dlist *create_node(int num)
{
	t_dlist *new_node = (t_dlist*)malloc(sizeof(t_dlist));
	if (!new_node)
		return (ft_printf("Malloc error!\n"), NULL);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->num = num;
	return (new_node);
}
//* insert at head
//* used to read input arg
void	insert_at_head(t_stack *stack, int num)
{
	t_dlist *new_node;

	new_node = create_node(num); // allocates memory for the new node
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
	t_dlist *new_node;

	new_node = create_node(num); // allocates memory for the new node
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
//   		  head
//		         	  tail
//	NULL <- data1 <-> data2  -> NULL
	t_dlist *preview;

	preview = (stack->tail)->prev;
	if ((stack->tail)->prev != NULL)
	{
		preview = (stack->tail)->prev;
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
	//   		  head
	//		         	  tail
	//	NULL <- data1 <-> data2  -> NULL
	//	NULL <- data1 -> NULL
	t_dlist *next;

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

//* swaps the data from node1 and node2
//* keeps the list structure the same
void swap_data(t_dlist **node1, t_dlist **node2)
{
	int temp;

	temp = (*node1)->num;
	(*node1)->num = (*node2)->num;
	(*node2)->num = temp;
}

//* free the resources allocated from the given list
//* recieves the head and frees while iterating the list
void free_list(t_dlist **head)
{
//					   temp
//			  head
//	NULL <-> data1 <-> data2 <-> data3 <-> NULL
	t_dlist *temp = NULL;

	if (*head == NULL)
		return;
	while ((*head)->next != NULL)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	free(*head);
}

//* prints list from head to tail
//* used for debugging
void print_list(t_dlist *head)
{
    t_dlist *current = head;
    while (current != NULL)
    {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");  // Print a newline at the end
}
