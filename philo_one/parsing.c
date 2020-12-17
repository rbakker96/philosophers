/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 09:20:16 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/17 14:07:34 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int		result_check(const char *str, int i, int pos_neg)
{
	long int overflow_check;
	long int result;

	overflow_check = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (overflow_check <= result)
		{
			overflow_check = result;
			result = result * 10 + (str[i] - '0');
			i++;
		}
		else
		{
			if (pos_neg == -1)
				return (0);
			else
				return (1);
		}
	}
	return (result * pos_neg);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			pos_neg;
	long int	result;

	i = 0;
	pos_neg = 1;
	result = 0;
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' && str[i + 1] != '-')
		i++;
	if (str[i] == '-' && str[i + 1] != '+')
	{
		pos_neg = -1;
		i++;
	}
	result = result_check(str, i, pos_neg);
	return (result);
}

int		parse_args(t_simulation_args *args, int argc, char **argv)
{
	args->nb_of_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->nb_of_must_eat = (argc == 6) ? ft_atoi(argv[5]) : 0;
	return (0);
}
