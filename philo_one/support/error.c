/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 15:32:03 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/22 16:53:50 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../support.h"

int		error_sequence(char *msg)
{
	print(ERROR_OUT, msg);
	return (-1);
}
