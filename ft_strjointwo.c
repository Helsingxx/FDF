/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjointwo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:35:51 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/21 16:10:18 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*ft_strjointwo(char *buffer1, char *buffer2, int len_buffer2)
{
	int		a;
	int		b;
	char	*res;
	int		len_buffer1;

	len_buffer1 = ft_strlen(buffer1);
	a = 0;
	b = 0;
	res = ft_calloc (len_buffer1 + len_buffer2 + 1, 1);
	if (res == 0)
		return (0);
	while (a < len_buffer1)
	{
		res[a] = buffer1[a];
		a++;
	}
	while (b < len_buffer2)
	{
		res[a] = buffer2[b];
		a++;
		b++;
	}
	free(buffer1);
	free(buffer2);
	return (res);
}
