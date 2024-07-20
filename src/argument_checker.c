/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s < artuda-s@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:47:21 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/20 18:43:13 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	perror_and_exit(void)
{
	ft_printf("Error\n");
	exit(1);
}

// se tiver uma letra/simbolo ou mais carateres que um intmin(-)
long	get_valid_num(char *str)
{
	long	num;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]) || i > 10)
			perror_and_exit();
		else
			num = num * 10 + str[i] - '0';
		i++;
	}
	num *= sign;
	if (!(-2147483647 <= num && num <= 2147483647))
		perror_and_exit();
	return (num);
}

void	check_arguments(int ac, char **av)
{
	int		j;
	long	num;
	int		temp2;
	int		i;

	if (ac < 2)
		perror_and_exit();
	if (ac == 2)
		av = ft_split(av[1], ' ');
	i = ac - 1;
	while (av[i])
	{
		num = get_valid_num(av[i]);
		j = i - 1;
		while (j >= 1)
		{
			temp2 = ft_atoi(av[j]);
			if (num == temp2)
				perror_and_exit();
			j--;
		}
		i++;
	}
}