/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:29:06 by eamrati           #+#    #+#             */
/*   Updated: 2023/10/03 21:21:59 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	checky(t_imgmanip *imgmanip, int y, int x)
{
	int	a;

	a = 0;
	while (!imgmanip->buffercasted[y][a].end)
	{
		if (x == a)
			return (1);
		a++;
	}
	return (0);
}

int	check_error(int flag)
{
	if (flag)
		ft_printf("Parsing error.");
	return (flag);
}

void	free_fdf(t_end	**buffer)
{
	int	a;

	a = 0;
	if (buffer)
	{
		while (buffer[a])
		{
			free(buffer[a]);
			a++;
		}
		free(buffer);
	}
}
