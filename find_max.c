/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:23:08 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/23 16:23:09 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	start_img(t_mlx	*mlx_var, t_imgmanip *imgmanip, int x, int y)
{
	imgmanip->img = mlx_new_image(mlx_var->mlx, x * 2, y * 2);
	if (!imgmanip->img)
		return (0);
	imgmanip->img_data = mlx_get_data_addr(imgmanip->img,
			&imgmanip->bits_per_pixel,
			&imgmanip->line_length, &imgmanip->endian);
	return (1);
}

int	find_he(t_end **buffer, t_imgmanip *imgmanip, t_mlx *mlx_var)
{
	int	i;
	int	j;
	int	max_z;

	max_z = (int)(H_BEGIN + (0 * H_SPRITE * mlx_var->coef)
			+ (0 * H_SPRITE * mlx_var->coef))
		- imgmanip->buffercasted[0][0].val * H_SPRITE * mlx_var->coef;
	i = 0;
	while (buffer[i])
	{
		j = 0;
		while (!buffer[i][j].endor0)
		{
			if (max_z < (int)(H_BEGIN + (j * H_SPRITE * mlx_var->coef)
				+ (i * H_SPRITE * mlx_var->coef))
			- imgmanip->buffercasted[i][j].val * H_SPRITE * mlx_var->coef)
				max_z = (int)(H_BEGIN + (j * H_SPRITE * mlx_var->coef)
						+ (i * H_SPRITE * mlx_var->coef))
					- imgmanip->buffercasted[i][j].val * H_SPRITE
					* mlx_var->coef;
			j++;
		}
		i++;
	}
	return (max_z);
}

int	find_wi(t_end **buffer, t_imgmanip *imgmanip, t_mlx *mlx_var)
{
	int	i;
	int	j;
	int	max_x;

	(void) imgmanip;
	max_x = (int)(W_BEGIN + (0 * W_SPRITE * mlx_var->coef)
			- (0 * W_SPRITE * mlx_var->coef));
	i = 0;
	while (buffer[i])
	{
		j = 0;
		while (!buffer[i][j].endor0)
		{
			if (max_x < (int)(W_BEGIN + (j * W_SPRITE * mlx_var->coef)
				- (i * W_SPRITE * mlx_var->coef)))
				max_x = (int)(W_BEGIN + (j * W_SPRITE * mlx_var->coef)
						- (i * W_SPRITE * mlx_var->coef));
			j++;
		}
		i++;
	}
	return (max_x);
}
