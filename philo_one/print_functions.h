/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 15:29:25 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/15 14:49:40 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_FUNCTIONS_H
# define PRINT_FUNCTIONS_H

# define STD_OUT 1
# define ERROR_OUT 2

int		print(int fd, char *str);

typedef enum		e_thread_status
{
	forks = 0,
	eating = 1,
	sleaping = 2,
	thinking = 3,
	died = 4
}					t_thread_status;

#endif
