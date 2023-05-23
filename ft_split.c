/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eamrati <eamrati@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:18:02 by eamrati           #+#    #+#             */
/*   Updated: 2023/05/23 16:23:56 by eamrati          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	freeing(char **list, int listindex)
{
	while (listindex >= 0)
	{
		free(list[listindex]);
		listindex--;
	}
	return (0);
}

static int	spliit(char const *s, char c, char **list, int listindex)
{
	size_t	a;
	int		save;
	size_t	strlen;

	strlen = ft_strlen(s);
	a = 0;
	while (a < strlen)
	{
		if (s[a] != c)
		{
			save = a;
			while (s[a] != c && s[a] != '\x00')
				a++;
			list[listindex] = ft_calloc(a - save + 1, 1);
			if (list[listindex] == 0)
				return (freeing(list, listindex));
			ft_strlcpy(list[listindex], &s[save], a - save + 1);
			listindex++;
		}
		a++;
	}
	list[listindex] = 0;
	return (a);
}

char	**ft_split(char const *s, char c)
{
	char	**list;
	int		listindex;

	listindex = 0;
	if (s == 0)
		return (0);
	list = ft_calloc (ft_strlen(s) + 1, sizeof(char *));
	if (list == 0)
		return (0);
	if (!spliit(s, c, list, listindex))
	{
		free(list);
		return (0);
	}
	return (list);
}
