/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 15:26:07 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/22 15:11:25 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print_functions.h"
#include "structs.h"

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int		print(int fd, char *str)
{
	return (write(fd, str, ft_strlen(str)));
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		print_nb(int fd, long n)
{
	if (n >= 10)
		print_nb(fd, (n / 10));
	ft_putchar_fd(('0' + (n % 10)), fd);

}

int		print_status(char *status, int philo, long timestamp)
{
	print_nb(STD_OUT, timestamp);
	write(STD_OUT, "\t", 1);
	print_nb(STD_OUT, philo);
	write(STD_OUT, status, ft_strlen(status));
	return (0);
}
