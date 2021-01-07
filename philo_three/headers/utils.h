/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: roybakker <roybakker@student.codam.nl>       +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 14:33:19 by roybakker     #+#    #+#                 */
/*   Updated: 2021/01/05 15:01:26 by roybakker     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

int		ft_strlen(const char *s);
void	ft_putchar_fd(const char c, int fd);
void	print_nb(const int fd, long n);
int		ft_atoi(const char *str);
int		ft_isdigit(char c);

#endif
