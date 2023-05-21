/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 22:48:04 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/21 16:02:11 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr_fd(char *s, int fd)
{
	if (s == 0)
	{
		if (write (fd, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	if (write(fd, s, ft_strlen(s)) == -1)
		return (-1);
	return (ft_strlen(s));
}
