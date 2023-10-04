/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:06:15 by eamrati           #+#    #+#             */
/*   Updated: 2023/10/04 11:25:26 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "printf/ft_printf.h"
# define WIN_WIDTH 1920
# define WIN_HEIGHT	1080
# define W_BEGIN 600
# define H_BEGIN 400
# define W_SPRITE 8
# define H_SPRITE 4
# define WHITE 0x00FFFFFF

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_end
{
	int	val;
	int	end;
}	t_end;

typedef struct s_parse
{
	int		fd;
	char	*buffer;
	char	*temp;
	char	*ret;
	int		strlen;
}	t_parse;

typedef struct s_imgmanip
{
	int		lenoutside;
	int		leninside;
	t_end	**buffercasted;
	void	*img;
	char	*img_data;
	int		endian;
	int		bits_per_pixel;
	int		line_length;
	int		temp1;
	int		temp2;
	int		x;
	int		y;
	int		x_prota;
	int		y_prota;
	int		coordsx_diff;
	int		coordsy_diff;
	int		ratiox;
	int		ratioy;
}	t_imgmanip;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_window;
	double		coef;
	t_end		**frees;
	char		*buffer;
	t_imgmanip	imgmanip;
	void		*img;
	void		*r_rimg;
	int			rrimg_h;
	int			rrimg_w;
	int			x;
	int			y;
	int			horizon;
	int			x_modif;
	int			y_modif;
	int			x_modif_max;
	int			y_modif_max;
}	t_mlx;

typedef struct s_data
{
	int	x_diff;
	int	y_diff;
	int	divx;
	int	divy;
	int	xcount;
	int	ycount;
	int	counter;
}	t_data;

char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strjointwo(char *buffer1, char *buffer2, int len_buffer2);
char		*ft_strchr(const char *s, int c);
void		*ft_realloc_append(void **acc, void *to_add);
int			ft_isdigit(char	*buffer);
char		**ft_split(char const *s, char c);
int			render_image(char *buffer, t_mlx *mlx_var);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strlenptr(t_end **ptr);
int			ft_atoi(const char *str, int *a, int *check_err);
void		exit_routine(t_mlx *mlx_var);
int			ft_isnumber(char *buffer);
void		free_fdf(t_end	**buffer);
void		ft_bzero(void *s, size_t n);
void		trace_it(t_mlx *mlx_var, t_imgmanip *imgmanip, float x, float y);
void		traceline(t_mlx *mlx_var, t_imgmanip *imgmanip, int x, int y);
void		put_the_shit(t_mlx *mlx_var, t_imgmanip *imgmanip, int x, int y);
void		put(t_mlx *mlx_var, t_imgmanip	imgmanip);
int			exit1(int key, t_mlx *mlx_var);
int			render_image(char *buffer, t_mlx *mlx_var);
void		*ft_split_struct(char *buffer);
int			img_draw(t_mlx *mlx_var, t_imgmanip *imgmanip, int x, int y);
t_end		**parse_into_map(char	*buffer, t_mlx *mlx_var);
void		traceline_anon(t_mlx *mlx_var, t_imgmanip *imgmanip, int x, int y);
void		traceline_z(t_mlx *mlx_var, t_imgmanip *imgmanip, int x, int y);
void		free_fdf(t_end	**buffer);
long long	ft_abs(long long a);
int			ft_strlenptr(t_end **ptr);
void		backwards_free(t_end **map, int i);
int			cond(int ecx, int steps);
int			ft_strlenptr_x(t_end *vals);
void		destroy_img(t_mlx *mlx_var);
int			start_img(t_mlx	*mlx_var, t_imgmanip *imgmanip, int x, int y);
int			checky(t_imgmanip *imgmanip, int y, int x);
int			check_error(int flag);
void		parse_hex(const char *str, int *a, int *check_err);
int			exit2(t_mlx *mlx_var);

#endif