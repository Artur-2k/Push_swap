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

	if (ac < 2)
		perror_and_exit();
	while (--ac >= 1)
	{
		num = get_valid_num(av[ac]);
		j = ac - 1;
		while (j >= 1)
		{
			temp2 = ft_atoi(av[j]);
			if (num == temp2)
				perror_and_exit();
			j--;
		}
	}
}