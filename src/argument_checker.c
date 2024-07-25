/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artuda-s <artuda-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 20:47:21 by artuda-s          #+#    #+#             */
/*   Updated: 2024/07/25 20:45:01 by artuda-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

void ft_free_split(char **split)
{
    int i;

    if (!split)
        return;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

void error_exit(char **to_free)
{
    if (to_free)
        ft_free_split(to_free);
    ft_putstr_fd("Error\n", 2);
    exit(1);
}

bool is_valid_int(const char *str, int *num)
{
    long long int result = 0;
    int sign = 1;
    int i = 0;

    if (str[i] == '-' || str[i] == '+')
    {
        sign = (str[i++] == '-') ? -1 : 1;
    }

    if (!str[i])
        return false;

    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return false;
        result = result * 10 + (str[i] - '0');
        if (result * sign > INT_MAX || result * sign < INT_MIN)
            return false;
        i++;
    }

    *num = (int)(result * sign);
    return true;
}

bool check_duplicates(int *numbers, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (numbers[i] == numbers[j])
                return true;
        }
    }
    return false;
}

int *parse_arguments(int ac, char **av, int *count)
{
    char **args = NULL;
    int *numbers = NULL;
    int num_count = 0;
    bool need_free = false;

    if (ac == 2)
    {
        args = ft_split(av[1], ' ');
        if (!args || !args[0])
      	{
			ft_printf("Error \n");
			exit(1);
		}
        need_free = true;
    }
    else
    {
        args = av + 1;
    }

    // Count the number of arguments
    for (int i = 0; args[i]; i++)
        num_count++;
	
    numbers = malloc(sizeof(int) * num_count);
    if (!numbers)
        error_exit(need_free ? args : NULL);

    // Parse and validate each number
    for (int i = 0; i < num_count; i++)
    {
        if (!is_valid_int(args[i], &numbers[i]))
        {
            free(numbers);
            error_exit(need_free ? args : NULL);
        }
    }

    // Check for duplicates
    if (check_duplicates(numbers, num_count))
    {
        free(numbers);
        error_exit(need_free ? args : NULL);
    }

    if (need_free)
        ft_free_split(args);

    *count = num_count;
    return numbers;
}



/* void	perror_and_exit(void)
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

int		ft_confirm_ac(char **av)
{
	int	i;
	
	if (!av)
	{
		ft_printf("Error\n");
		exit (1);
	}
	i = 0;
	while (!av[i])
		i++;
	return (i);
}

char **check_2_args(int ac, char **av)
{
	int		i;
	int		j;
	long	num;
	long	temp;
	
	av = ft_split(av[1], ' ');
	if (!av)
	{
		ft_printf("Error\n");
		exit (1);
	}
	i = 0;
	while (av[i] != NULL)
	{
		num = get_valid_num(av[i]);
		j = i + 1;
		while (av[j] != NULL)
		{
			temp = get_valid_num(av[j]);
			if (num == temp)
				perror_and_exit();
			j++;
		}
		i++;
	}
	return (av);
}
		
char	**check_arguments(int ac, char **av)
{
	int		i;
	int		j;
	long	num;
	long	temp;

	if (ac < 2)
		perror_and_exit();
	if (ac == 2)
		av = check_2_args(ac, av);
	else
	{	
		i = ac - 1;
		while (av[i])
		{
			num = get_valid_num(av[i]);
			j = i - 1;
			while (j >= 1)
			{
				temp = get_valid_num(av[j]);
				if (num == temp)
					perror_and_exit();
				j--;
			}
			i--;
		}
	}
	return (av);
}
 */