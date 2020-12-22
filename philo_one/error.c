/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/21 15:32:03 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/21 15:33:47 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "print_functions.h"

int		error_sequence(char *msg)
{
	print(ERROR_OUT, msg);
	return (-1);
}
