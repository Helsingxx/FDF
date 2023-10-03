/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:10:35 by eamrati           #+#    #+#             */
/*   Updated: 2023/10/03 21:27:54 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_the_shit(t_mlx *mlx_var, t_imgmanip *imgmanip, int x, int y)
{
	img_draw(mlx_var, imgmanip, (int)(W_BEGIN
			+ (x * W_SPRITE * mlx_var->coef)
			- (y * W_SPRITE * mlx_var->coef)),
		(int)(H_BEGIN + (x * H_SPRITE * mlx_var->coef)
			+ (y * H_SPRITE * mlx_var->coef))
		- imgmanip->buffercasted[y][x].val * H_SPRITE * mlx_var->coef);
	traceline(mlx_var, imgmanip, x, y);
}

void	put(t_mlx *mlx_var, t_imgmanip	imgmanip)
{
	int	i;
	int	j;

	i = 0;
	while (imgmanip.buffercasted[i])
	{
		j = 0;
		while (!imgmanip.buffercasted[i][j].end)
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
	if (!start_img(mlx_var, &imgmanip, WIN_WIDTH,
			WIN_HEIGHT))
		exit_routine(mlx_var);
	mlx_var->imgmanip = imgmanip;
	put(mlx_var, imgmanip);
	mlx_hook(mlx_var->mlx_window, 2, 0, exit1, mlx_var);
	mlx_hook(mlx_var->mlx_window, 17, 0, exit2, mlx_var);
	return (1);
}

int	img_draw(t_mlx *mlx_var, t_imgmanip *imgmanip, int x, int y)
{
	unsigned int	*dst;

	(void) mlx_var;
	if (y >= WIN_HEIGHT || x >= WIN_WIDTH || y < 0 || x < 0)
		return (0);
	dst = (unsigned int *)(imgmanip->img_data
			+ (y * imgmanip->line_length + x * (imgmanip->bits_per_pixel / 8)));
	*dst = WHITE;
	return (1);
}
