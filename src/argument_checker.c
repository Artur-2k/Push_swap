/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:47:21 by artuda-s          #+#    #+#             */
/*   Updated: 2024/10/03 12:58:15 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	is_valid_int(const char *str, int *num)
{
	long			result;
	long int		sign;

	result = 0;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		result = result * 10 + (*str - '0');
		if (result * sign > INT_MAX || result * sign < -2147483648L)
			return (0);
		str++;
	}
	*num = (int)(result * sign);
	return (1);
}

int	check_duplicates(int *numbers, int count, char **args, int need_free)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (numbers[i] == numbers[j])
			{
				if (need_free)
					error_exit_free(args, numbers, need_free);
				else
					error_exit_free(NULL, numbers, need_free);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	count_numbers(char **args)
{
	int	num_count;

	num_count = 0;
	while (args[num_count])
		num_count++;
	if (num_count == 0)
		error_exit_free(args, NULL, 1);
	return (num_count);
}

void	get_valid_numbers(int count, int *numbers, char **args, int need_free)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (!is_valid_int(args[i], &numbers[i]))
		{
			free(numbers);
			if (need_free)
				ft_free_split(args);
			error_exit();
		}
		i++;
	}
}

int	*parse_arguments(int ac, char **av, int *count)
{
	char	**args;
	int		*numbers;
	int		need_free;

	need_free = 0;
	if (ac == 2)
	{
		if (ft_strlen(av[1]) == 0)
			error_exit();
		args = ft_split(av[1], ' ');
		if (!args)
			error_exit();
		need_free = 1;
	}
	else
		args = av + 1;
	*count = count_numbers(args);
	numbers = malloc(sizeof(int) * (*count));
	if ((!numbers && ac == 2))
		error_exit_free(args, NULL, 1);
	get_valid_numbers(*count, numbers, args, need_free);
	check_duplicates(numbers, *count, args, need_free);
	if (need_free)
		ft_free_split(args);
	return (numbers);
}
