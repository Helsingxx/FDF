/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:59:30 by eamrati           #+#    #+#             */
/*   Updated: 2023/10/03 21:28:19 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*ft_split_struct(char *buffer)
{
	int		a;
	int		j;
	t_end	*res;
	int		check_err;

	check_err = 0;
	res = ft_calloc(ft_strlen(buffer), sizeof(t_end));
	a = 0;
	j = 0;
	if (!res)
		return (0);
	while (buffer[a])
	{
		res[j].val = ft_atoi(buffer, &a, &check_err);
		if (check_error(check_err))
			return (0);
		res[j].end = 0;
		j++;
	}
	if (buffer[a] == 0)
		res[j].end = 1;
	free(buffer);
	return (res);
}

t_end	**parse_into_map(char	*buffer, t_mlx *mlx_var)
{
	t_end	**map;
	size_t	i;
	size_t	line_map_len;

	map = (t_end **) ft_split(buffer, '\n');
	free(buffer);
	mlx_var->buffer = 0;
	if (!map)
		exit_routine(mlx_var);
	line_map_len = ft_strlenptr(map);
	i = 0;
	while (i < line_map_len)
	{
		map[i] = ft_split_struct((char *)map[i]);
		if (!map[i])
		{
			backwards_free(map, i);
			exit_routine(mlx_var);
		}
		i++;
	}
	return (map);
}

void	traceline_anon(t_mlx *mlx_var, t_imgmanip *imgmanip, int x, int y)
{
	imgmanip->temp1 = x;
	imgmanip->temp2 = y;
	x = (int)(W_BEGIN + (x * W_SPRITE * mlx_var->coef)
			- (y * W_SPRITE * mlx_var->coef));
	y = (int)(H_BEGIN + (imgmanip->temp1 * H_SPRITE
				* mlx_var->coef) + (imgmanip->temp2 * H_SPRITE * mlx_var->coef))
		- imgmanip->buffercasted[imgmanip->temp2][imgmanip->temp1].val
		* H_SPRITE * mlx_var->coef;
	imgmanip->coordsx_diff = imgmanip->x_prota - x;
	imgmanip->coordsy_diff = imgmanip->y_prota - y;
	trace_it(mlx_var, imgmanip, x, y);
}

void	traceline(t_mlx *mlx_var, t_imgmanip *imgmanip, int x, int y)
{
	imgmanip->x_prota = (int)(W_BEGIN + (x * W_SPRITE
				* mlx_var->coef) - (y * W_SPRITE * mlx_var->coef));
	imgmanip->y_prota = (int)(H_BEGIN + (x * H_SPRITE
				* mlx_var->coef) + (y * H_SPRITE * mlx_var->coef))
		- imgmanip->buffercasted[y][x].val * H_SPRITE * mlx_var->coef;
	if (!imgmanip->buffercasted[y][x + 1].end)
		traceline_anon(mlx_var, imgmanip, x + 1, y);
	if (x - 1 >= 0)
		traceline_anon(mlx_var, imgmanip, x - 1, y);
	if (y - 1 >= 0 && checky(imgmanip, y - 1, x))
		traceline_anon(mlx_var, imgmanip, x, y - 1);
	if (imgmanip->buffercasted[y + 1] && checky(imgmanip, y + 1, x))
		traceline_anon(mlx_var, imgmanip, x, y + 1);
}
