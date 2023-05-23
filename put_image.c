/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:10:35 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/23 16:23:35 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_the_shit(t_mlx *mlx_var, t_imgmanip *imgmanip, int x, int y)
{	
	if (imgmanip->buffercasted[y][x].val == 0)
	{
		img_draw(mlx_var, imgmanip, (int)(W_BEGIN
				+ (x * W_SPRITE * mlx_var->coef)
				- (y * W_SPRITE * mlx_var->coef)),
			(int)(H_BEGIN + (x * H_SPRITE * mlx_var->coef)
				+ (y * H_SPRITE * mlx_var->coef)));
		if (!imgmanip->buffercasted[y][x + 1].endor0
			&& imgmanip->buffercasted[y][x + 1].val == 0)
			tracelinex(mlx_var, imgmanip, x, y);
		if (imgmanip->buffercasted[y + 1]
			&& imgmanip->buffercasted[y + 1][x].val == 0)
			traceliney(mlx_var, imgmanip, x, y);
	}
	if (imgmanip->buffercasted[y][x].val != 0)
	{	
		img_draw(mlx_var, imgmanip, (int)(W_BEGIN
				+ (x * W_SPRITE * mlx_var->coef)
				- (y * W_SPRITE * mlx_var->coef)),
			(int)(H_BEGIN + (x * H_SPRITE * mlx_var->coef)
				+ (y * H_SPRITE * mlx_var->coef))
			- imgmanip->buffercasted[y][x].val * H_SPRITE * mlx_var->coef);
		traceline_z(mlx_var, imgmanip, x, y);
	}
}

void	put(t_mlx *mlx_var, t_imgmanip	imgmanip)
{
	int	i;
	int	j;

	i = 0;
	while (imgmanip.buffercasted[i])
	{
		j = 0;
		while (!imgmanip.buffercasted[i][j].endor0)
		{
			put_the_shit(mlx_var, &imgmanip, j, i);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx_var->mlx, mlx_var->mlx_window,
		mlx_var->imgmanip.img, 0, 0);
}

int	render_image(char *buffer, t_mlx *mlx_var)
{
	t_imgmanip	imgmanip;

	imgmanip.buffercasted = parse_into_map(buffer, mlx_var);
	mlx_var->frees = imgmanip.buffercasted;
	imgmanip.lenoutside = ft_strlenptr((t_end **)imgmanip.buffercasted);
	if (!start_img(mlx_var, &imgmanip, find_wi(imgmanip.buffercasted,
				&imgmanip, mlx_var),
			find_he(imgmanip.buffercasted, &imgmanip, mlx_var)))
		exit_routine(mlx_var);
	mlx_var->imgmanip = imgmanip;
	put(mlx_var, imgmanip);
	mlx_hook(mlx_var->mlx_window, 2, 1L << 0, zoom, mlx_var);
	return (1);
}

int	img_draw(t_mlx *mlx_var, t_imgmanip *imgmanip, int y, int x)
{
	(void) mlx_var;
	imgmanip->img_data += (x * imgmanip->line_length
			+ y * (imgmanip->bits_per_pixel / 8));
	*((unsigned int *)imgmanip->img_data) = WHITE;
	imgmanip->img_data -= (x * imgmanip->line_length
			+ y * (imgmanip->bits_per_pixel / 8));
	return (1);
}
