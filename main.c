/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:18:45 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/21 22:57:16 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*mlx_startup(char	*buffer)
{
	static t_mlx	mlx_var;

	mlx_var.coef = 1;
	mlx_var.buffer = buffer;
	mlx_var.mlx = mlx_init();
	if (mlx_var.mlx == 0)
		exit_routine(&mlx_var);
	mlx_var.mlx_window = mlx_new_window(mlx_var.mlx,
			WIN_WIDTH, WIN_HEIGHT, "FdF");
	if (mlx_var.mlx_window == 0)
		exit_routine(&mlx_var);
	render_image(buffer, &mlx_var);
	mlx_loop(mlx_var.mlx);
	mlx_destroy_window(mlx_var.mlx, mlx_var.mlx_window);
	return (0);
}

char	*check_empty_num(t_parse p)
{
	int	a;

	a = 0;
	p.strlen = ft_strlen(p.buffer);
	if (p.strlen == 0)
	{
		ft_printf("Your file is empty");
		free(p.buffer);
		exit(1);
	}
	return (p.buffer);
}

void	generate_buffer(t_parse *p)
{
	t_tools	var;

	ft_bzero(&var, sizeof(t_tools));
	while (1)
	{
		p->ret = get_next_line(p->fd, var);
		if (!p->ret)
			break ;
		p->temp = ft_strjointwo(p->buffer, p->ret, ft_strlen(p->ret));
		if (p->temp == 0)
		{
			free(p->buffer);
			free(p->ret);
			exit(1);
		}
		p->buffer = p->temp;
	}
}

char	*parse(char **argv)
{
	t_parse	p;

	p.buffer = 0;
	if (ft_strnstr(argv[1], ".fdf",
			ft_strlen(argv[1])) != &argv[1][ft_strlen(argv[1])] - 4)
	{
		ft_printf("Illegal file format.");
		exit(1);
	}
	p.fd = open(argv[1], O_RDONLY);
	if (p.fd < 0)
		exit (1);
	generate_buffer(&p);
	return (check_empty_num(p));
}

int	main(int argc, char **argv)
{
	char	*buffer;

	(void) argc;
	buffer = parse(argv);
	mlx_startup(buffer);
	return (0);
}
