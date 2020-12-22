/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/15 09:20:16 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/22 16:53:57 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../support.h"

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
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * pos_neg);
}

int		parse_args(t_args *args, int argc, char **argv)
{
	args->nb_of_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]) * 1000;
	args->time_to_eat = ft_atoi(argv[3]) * 1000;
	args->time_to_sleep = ft_atoi(argv[4]) * 1000;
	args->nb_of_must_eat = (argc == 6) ? ft_atoi(argv[5]) : 0;
	return (0);
}
