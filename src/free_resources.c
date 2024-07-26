/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:29:09 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/26 15:10:51 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

//* free the resources allocated from the given list
//* recieves the head and frees while iterating the list
void	free_list(t_dlist **head)
{
	t_dlist	*temp;

	temp = NULL;
	if (*head == NULL)
		return ;
	while ((*head)->next != NULL)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}
	free(*head);
}

void	free_last_resources(int *numbers, t_dlist *head_a, t_dlist *head_b)
{
	if (numbers)
		free(numbers);
	if (head_a)
		free_list(&head_a);
	if (head_b)
		free_list(&head_b);
}
