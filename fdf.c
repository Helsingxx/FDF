/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 22:53:49 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/21 22:53:59 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	zoom(int key, t_mlx *mlx_var)
{
	if (key == 53)
		exit_routine(mlx_var);
	return (0);
}
