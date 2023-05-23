/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 23:49:31 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/23 16:24:13 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	len;

	len = ft_strlen(src);
	a = 0;
	while (a < len && a + 1 < dstsize)
	{
		dst[a] = src[a];
		a++;
	}
	if (dstsize > 0)
		dst[a] = '\x00';
	return (len);
}
