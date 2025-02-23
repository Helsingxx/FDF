/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 21:23:44 by eamrati           #+#    #+#             */
/*   Updated: 2023/10/03 21:25:38 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static long	ft_nbcmp(const char *s1, const char *s2)
{
	size_t	a;
	size_t	b;

	b = 0;
	a = 0;
	while (s1[b] >= 48 && s1[b] <= 57)
		b++;
	if (b > ft_strlen(s2))
		return (1);
	else if (b < ft_strlen(s2))
		return (-1);
	while (s2[a] != 0 && s1[a] >= 48 && s1[a] <= 57)
	{
		if (s1[a] > s2[a])
			return (1);
		else if (s1[a] < s2[a])
			return (-1);
		a++;
	}
	return (0);
}

static unsigned long	positive(const char *str, int *a,
									int sign, int *check_err)
{
	unsigned long	number;

	number = 0;
	if (sign == 1 && ft_nbcmp(&str[*a], "9223372036854775807") > 0)
	{
		*check_err = 1;
		return (-1);
	}
	if (sign == -1 && ft_nbcmp(&str[*a], "9223372036854775808") > 0)
	{
		*check_err = 1;
		return (0);
	}
	if (str[*a] != 0 && (str[*a] < 48 || str[*a] > 57))
		*check_err = 1;
	while (str[*a] >= 48 && str[*a] <= 57)
	{
		number *= 10;
		number += str[*a] - 48;
		(*a)++;
	}
	return (number);
}

int	ft_atoi(const char *str, int *a, int *check_err)
{
	while (str[*a] == '\t' || str[*a] == '\n' || str[*a] == '\v'
		|| str[*a] == '\f' || str[*a] == '\r' || str[*a] == ' ')
		(*a)++;
	if (str[*a] == ',' && str[(*a) + 1] == '0' && str[(*a) + 2] == 'x')
		parse_hex(str, a, check_err);
	if (str[*a] == '-')
	{
		(*a)++;
		if (str[*a] < 48 || str[*a] > 57)
			*check_err = 1;
		return (positive(str, a, -1, check_err) * -1);
	}
	else if (str[*a] == '+')
	{
		(*a)++;
		if (str[*a] < 48 || str[*a] > 57)
			*check_err = 1;
	}
	return (positive(str, a, 1, check_err));
}

void	parse_hex(const char *str, int *a, int *check_err)
{
	int	tmp;

	(*a)++;
	(*a)++;
	(*a)++;
	tmp = *a;
	while ((str[*a] >= '0' && str[*a] <= '9')
		|| (str[*a] >= 'a' && str[*a] <= 'f')
		|| (str[*a] >= 'A' && str[*a] <= 'F'))
		(*a)++;
	if (tmp == *a)
		*check_err = 1;
	while (str[*a] == '\t' || str[*a] == '\n' || str[*a] == '\v'
		|| str[*a] == '\f' || str[*a] == '\r' || str[*a] == ' ')
		(*a)++;
}
