/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 23:22:56 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/21 16:13:54 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

typedef struct s_tools
{
	char	*result;
	int		ret;
	char	*temp;
	int		newlinepos;
	int		freeallsignal;
	int		x;
	int		p;
}	t_tools;

size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
char	*get_next_line(int fd, t_tools	tools);
char	*ft_strdup(char **str, int len, int fd);
char	*ft_strjoin(char **buffer1, char *buffer2, int len, int fd);
void	*freeall(char **buffer, t_tools *tools, int signal, int fd);

#endif