/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:52:03 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/21 23:07:30 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	zoom(int key, t_mlx *mlx_var)
{
	if (key == 34 || (key == 31 && mlx_var->coef > 1))
		destroy_img(mlx_var);
	if (key == 34)
		mlx_var->coef++;
	else if (key == 31 && mlx_var->coef > 1)
		mlx_var->coef--;
	else if (key == 53)
		exit_routine(mlx_var);
	mlx_var->x = 0;
	mlx_var->y = 0;
	img_create(mlx_var, &mlx_var->imgmanip, WHITE);
	put(mlx_var, mlx_var->imgmanip);
	return (0);
}
