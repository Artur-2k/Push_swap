/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:29:10 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/26 12:55:44 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error_exit(void)
{
	ft_printf("Error \n");
	exit(1);
}

void	error_exit_free(char **args, int *numbers)
{
	if (numbers)
		free(numbers);
	if (args)
		ft_free_split(args);
	ft_putstr_fd("Error free\n", 2);
	exit(1);
}
