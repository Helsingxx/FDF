/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:47:33 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/21 16:10:37 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

// double while loops, fixate a character then search the needle, 
// don't overpass the limits "strlen needle\haystack" & "maxlen"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		a;
	size_t		b;

	a = 0;
	if (!haystack || !needle)
		return (0);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (a < len && haystack[a] != 0)
	{
		b = 0;
		while (b < ft_strlen(needle) && b < ft_strlen(haystack) - a
			&& b < len - a)
		{
			if (haystack[a + b] != needle[b])
				break ;
			b++;
		}
		if (b == ft_strlen(needle))
		{
			return ((char *)(haystack + a));
		}
		a++;
	}
	return (0);
}
