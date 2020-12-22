/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 15:05:21 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/22 14:13:04 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "print_functions.h"
#include "parsing.h"

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
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
	parse_args(args, argc, argv);
	return (0);
}
