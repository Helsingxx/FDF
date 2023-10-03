/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:53:49 by eamrati           #+#    #+#             */
/*   Updated: 2023/10/03 21:22:17 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	start_img(t_mlx	*mlx_var, t_imgmanip *imgmanip, int x, int y)
{
	imgmanip->img = mlx_new_image(mlx_var->mlx, x, y);
	if (!imgmanip->img)
		return (0);
	imgmanip->img_data = mlx_get_data_addr(imgmanip->img,
			&imgmanip->bits_per_pixel,
			&imgmanip->line_length, &imgmanip->endian);
	return (1);
}

int	exit1(int key, t_mlx *mlx_var)
{
	if (key == 53)
		exit_routine(mlx_var);
	return (0);
}

int	exit2(t_mlx *mlx_var)
{
	exit_routine(mlx_var);
	return (0);
}
