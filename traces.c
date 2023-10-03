/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:59:50 by eamrati           #+#    #+#             */
/*   Updated: 2023/10/03 21:28:30 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	trace_it(t_mlx *mlx_var, t_imgmanip *imgmanip, float x, float y)
{
	int		steps;
	int		ecx;
	float	increment_x;
	float	increment_y;

	ecx = 0;
	if (ft_abs(imgmanip->coordsx_diff) > ft_abs(imgmanip->coordsy_diff))
		steps = ft_abs(imgmanip->coordsx_diff);
	else
		steps = ft_abs(imgmanip->coordsy_diff);
	increment_x = (float) imgmanip->coordsx_diff / (float) steps;
	increment_y = (float) imgmanip->coordsy_diff / (float) steps;
	while (ecx <= steps)
	{
		img_draw(mlx_var, imgmanip, round(x), round(y));
		x += increment_x;
		y += increment_y;
		ecx++;
	}
}
