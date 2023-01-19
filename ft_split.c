/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:06:06 by hlalouli          #+#    #+#             */
/*   Updated: 2022/11/21 16:28:10 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	ft_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (*s)
	{
		if (*s != c && count == 0)
		{
			count = 1;
			i++;
		}
		else if (*s == c)
			count = 0;
		s++;
	}
	return (i);
}

static char	**free_sp(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
		free(sp[i++]);
	free(sp);
	return (NULL);
}

static char	**ft_ha(char *s, char **sp, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j != 0)
			sp[k++] = ft_substr(s, i, j);
		if (j != 0 && !sp[k - 1])
			return (free_sp(sp));
		i += j;
	}
	return (sp);
}

char	**ft_split(char *s, char c)
{
	char	**sp;

	if (!s)
		return (0);
	sp = ft_calloc(ft_count(s, c) + 1, sizeof(char *));
	if (!sp)
		return (NULL);
	sp = ft_ha(s, sp, c);
	return (sp);
}
