/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:29:06 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/21 22:41:08 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	destroy_img(t_mlx *mlx_var)
{
	mlx_destroy_image(mlx_var->mlx, mlx_var->imgmanip.img);
	mlx_var->imgmanip.img = mlx_new_image(mlx_var->mlx,
			WIN_WIDTH, WIN_HEIGHT);
	mlx_put_image_to_window(mlx_var->mlx, mlx_var->mlx_window,
		mlx_var->imgmanip.img, 0, 0);
}

void	exit_routine(t_mlx *mlx_var)
{
	if (mlx_var->imgmanip.img)
		mlx_destroy_image(mlx_var->mlx, mlx_var->imgmanip.img);
	if (mlx_var->r_rimg)
		mlx_destroy_image(mlx_var->mlx, mlx_var->r_rimg);
	if (mlx_var->mlx_window)
		mlx_destroy_window(mlx_var->mlx, mlx_var->mlx_window);
	if (mlx_var->buffer)
		free(mlx_var->buffer);
	free_fdf(mlx_var->frees);
	exit (0);
}
