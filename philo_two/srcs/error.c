/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 15:32:03 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/07 14:39:33 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error.h"
#include "../headers/utils.h"
#include <stdlib.h>
#include <unistd.h>

int		error_sequence(char *msg, t_philo *philo)
{
	if (philo)
		free(philo);
	write(ERROR_OUT, msg, ft_strlen(msg));
	return (-1);
}
