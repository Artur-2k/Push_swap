/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:47:17 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/18 18:08:41 by artuda-s         ###   ########.fr       */
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
void insert_at_head(t_dlist **head,t_dlist **tail, int num)
{
	t_dlist *new_node = create_node(num); // allocates memory for the new node
	if (*head)
	{
		new_node->next = (*head);
		(*head)->prev = new_node;
		*head = new_node;
	}
	else
	{
		*head = new_node;
		*tail = new_node;
	}
}
//* insert at head
//* push to stack
void push(t_dlist **tail, t_dlist **head, int num)
{
	t_dlist *new_node = create_node(num);

	if (*tail)
	{
		(*tail)->next = new_node;
		new_node->prev = *tail;
		*tail = new_node;
	}
	else
	{
		*head = new_node;
		*tail = new_node;
	}
}

//* removes the last node (tail)
//* pop from stack
void pop(t_dlist **tail, t_dlist **head)
{
//   		  head
//		         	  tail
//	NULL <- data1 <-> data2  -> NULL
	t_dlist *preview = (*tail)->prev;

	if ((*tail)->prev != NULL)
	{
		preview = (*tail)->prev;
		free(*tail);
		preview->next = NULL;
		*tail = preview;
	}
	else
	{
		free(*tail);
		*head = NULL;
		*tail = NULL;
	}
}
void	remove_head(t_dlist **head, t_dlist **tail)
{
	//   		  head
	//		         	  tail
	//	NULL <- data1 <-> data2  -> NULL
	//	NULL <- data1 -> NULL
	t_dlist *next;

	next = NULL;
	if ((*head)->next != NULL)
	{
		next = (*head)->next;
		free(*head);
		next->prev = NULL;
		*head = next;
	}
	else
	{
		free(*head);
		*head = NULL;
		*tail = NULL;
	}
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
