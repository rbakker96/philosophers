/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/14 15:26:07 by roybakker     #+#    #+#                 */
/*   Updated: 2020/12/15 14:51:42 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "print_functions.h"

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

int		print_status()
{
	char *thread_status[5];

	thread_status[0] = " has taken a fork";
	thread_status[1] = " is eating";
	thread_status[2] = " is sleeping";
	thread_status[3] = " is thinking";
	thread_status[4] = " died";
	return (0);
}

// void		ft_putnbr_fd(int n, int fd)
// {
// 	if (n < 0)
// 	{
// 		if (n == -2147483648)
// 		{
// 			ft_putchar_fd(('-'), fd);
// 			ft_putchar_fd(('2'), fd);
// 			n = 147483648;
// 		}
// 		else
// 		{
// 			ft_putchar_fd(('-'), fd);
// 			n = n * -1;
// 		}
// 	}
// 	if (n >= 10)
// 	{
// 		ft_putnbr_fd((n / 10), fd);
// 	}
// 	ft_putchar_fd(('0' + (n % 10)), fd);
// }
