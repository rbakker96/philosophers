/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 14:33:11 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/05 15:28:03 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/utils.h"
#include <unistd.h>

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar_fd(const char c, int fd)
{
	write(fd, &c, 1);
}

void		print_nb(const int fd, long n)
{
	if (n >= 10)
		print_nb(fd, (n / 10));
	ft_putchar_fd(('0' + (n % 10)), fd);

}

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

int		ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
