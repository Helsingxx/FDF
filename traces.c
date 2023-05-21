/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:59:50 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/21 20:08:54 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	tracelinex_calc(t_data *coords)
{
	if (coords->divx > coords->divy)
	{
		if (coords->x_diff % coords->divx == 0)
			coords->y_diff--;
		coords->x_diff--;
	}
	else if (coords->divx < coords->divy)
	{
		if (coords->y_diff % coords->divy == 0)
			coords->x_diff--;
		coords->y_diff--;
	}
	else
	{
		coords->x_diff--;
		coords->y_diff--;
	}
}

void	tracelinex(t_mlx *mlx_var, t_imgmanip *imgmanip, int x, int y)
{
	t_data	coords;

	coords.x_diff = (int)(W_BEGIN + ((x + 1) * W_SPRITE * mlx_var->coef)
			- (y * W_SPRITE * mlx_var->coef)) - (int)(W_BEGIN
			+ (x * W_SPRITE * mlx_var->coef) - (y * W_SPRITE * mlx_var->coef));
	coords.y_diff = (int)(H_BEGIN + ((x + 1) * H_SPRITE * mlx_var->coef)
			+ (y * H_SPRITE * mlx_var->coef)) - (int)(H_BEGIN
			+ (x * H_SPRITE * mlx_var->coef) + (y * H_SPRITE * mlx_var->coef));
	coords.divx = coords.x_diff / coords.y_diff;
	coords.divy = coords.y_diff / coords.x_diff;
	while (coords.x_diff > 0 || coords.y_diff > 0)
	{
		mlx_put_image_to_window(mlx_var->mlx, mlx_var->mlx_window,
			imgmanip->img, (int)(W_BEGIN + (x * W_SPRITE * mlx_var->coef)
				- (y * W_SPRITE * mlx_var->coef)) + coords.x_diff,
			(int)(H_BEGIN + (x * H_SPRITE * mlx_var->coef)
				+ (y * H_SPRITE * mlx_var->coef)) + coords.y_diff);
		tracelinex_calc(&coords);
	}
}

void	traceliney_calc(t_data *coords)
{
	if (coords->divx > coords->divy)
	{
		if (coords->xcount % coords->divx == 0)
			coords->ycount--;
		coords->xcount++;
	}
	else if (coords->divx < coords->divy)
	{
		if (-(coords->ycount) % coords->divy == 0)
			coords->xcount++;
		coords->ycount--;
	}
	else
	{	
		coords->xcount++;
		coords->ycount--;
	}
	coords->counter++;
}

void	traceliney(t_mlx *mlx_var, t_imgmanip *imgmanip, int x, int y)
{
	t_data	coords;

	coords.counter = 0;
	coords.x_diff = (int)(W_BEGIN + (x * W_SPRITE * mlx_var->coef)
			- (y * W_SPRITE * mlx_var->coef))
		- (int)(W_BEGIN + (x * W_SPRITE * mlx_var->coef)
			- ((y + 1) * W_SPRITE * mlx_var->coef));
	coords.y_diff = (int)(H_BEGIN + (x * H_SPRITE * mlx_var->coef)
			+ (y * H_SPRITE * mlx_var->coef))
		- (int)(H_BEGIN + (x * H_SPRITE * mlx_var->coef)
			+ ((y + 1) * H_SPRITE * mlx_var->coef));
	coords.xcount = 0;
	coords.ycount = 0;
	coords.divx = -(coords.x_diff / coords.y_diff);
	coords.divy = -(coords.y_diff / coords.x_diff);
	while (coords.xcount < coords.x_diff || coords.ycount > coords.y_diff)
	{
		mlx_put_image_to_window(mlx_var->mlx, mlx_var->mlx_window,
			imgmanip->img, (int)(W_BEGIN + (x * W_SPRITE * mlx_var->coef)
				- ((y + 1) * W_SPRITE * mlx_var->coef)) + coords.xcount,
			(int)(H_BEGIN + (x * H_SPRITE * mlx_var->coef)
				+ ((y + 1) * H_SPRITE * mlx_var->coef)) + coords.ycount);
		traceliney_calc(&coords);
	}
}

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
		mlx_put_image_to_window(mlx_var->mlx,
			mlx_var->mlx_window, imgmanip->img, round(x), round(y));
		x += increment_x;
		y += increment_y;
		ecx++;
	}
}
