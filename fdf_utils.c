/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:30:33 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/21 19:30:35 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

long long	ft_abs(long long a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	ft_strlenptr(t_end **ptr)
{
	int	a;

	a = 0;
	while (ptr[a] != 0)
		a++;
	return (a);
}

void	backwards_free(t_end **map, int i)
{
	while (i >= 0)
	{
		free(map[i]);
		map[i] = 0;
		i--;
	}
	free(map);
}

int	cond(int ecx, int steps)
{
	if (steps < 0)
		return (ecx >= steps);
	else
		return (ecx <= steps);
}

int	ft_strlenptr_x(t_end *vals)
{
	int	a;

	a = 0;
	while (!vals[a].endor0)
		a++;
	return (a);
}
