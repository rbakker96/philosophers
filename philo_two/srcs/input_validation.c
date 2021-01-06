/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 15:05:21 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/05 19:45:14 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/input_validation.h"
#include "../headers/utils.h"

int		parse_args(t_args *args, int argc, char **argv)
{
	args->state = alive;
	args->nb_of_philo = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->nb_of_must_eat = (argc == 6) ? ft_atoi(argv[5]) : -1;
	return (0);
}

int		validate_args(t_args *args, int argc, char **argv)
{
	int i;
	int x;

	i = 1;
	if (argc != 5 && argc != 6)
		return (-1);
	while (i < argc)
	{
		x = (argv[i][0] == '+') ? 1 : 0;
		while (argv[i][x] != '\0')
		{
			if (!ft_isdigit(argv[i][x]))
				return (-1);
			x++;
		}
		i++;
	}
	return(parse_args(args, argc, argv));
}
