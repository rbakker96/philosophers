/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 15:26:07 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/18 15:55:09 by roybakker     ########   odam.nl         */
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
	int length;

	length = ft_strlen(str);
	return (write(fd, str, length));
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

int		print_status(int status, int philo, long timestamp)
{
	char *thread_status[6];

	thread_status[0] = "\thas taken a left fork\n";
	thread_status[1] = "\thas taken a right fork\n";
	thread_status[2] = "\tis eating\n";
	thread_status[3] = "\tis sleeping\n";
	thread_status[4] = "\tis thinking\n";
	thread_status[5] = "\tdied\n";

	print_nb(STD_OUT, timestamp);
	print(STD_OUT, "\t");
	print_nb(STD_OUT, philo);
	print(STD_OUT, thread_status[status]);
	return (0);
}
