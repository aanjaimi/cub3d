/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:33:51 by hlalouli          #+#    #+#             */
/*   Updated: 2022/11/20 13:34:51 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*pt;

	i = 0;
	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
	{
		if (ft_strlen(s) < len)
			len = ft_strlen(s);
		pt = (char *)malloc(len + 1);
		if (!pt)
			return (NULL);
		while (i < len)
			*(pt + i++) = *(s + start++);
		*(pt + i) = '\0';
		return (pt);
	}
	pt = malloc(1);
	if (!pt)
		return (pt);
	*(pt + i) = 0;
	return (pt);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != 0)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;
	int		s1_len;
	int		s2_len;

	if (!s1)
		s1 = ft_strdup("");
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3 = malloc(s1_len + s2_len + 1 * sizeof(char));
	if (!s3)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		s3[i] = s1[i];
	j = 0;
	while (i < s1_len + s2_len)
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	return (s3);
}

char	*ft_strdup(char *s1)
{
	int		l;
	int		i;
	char	*s2;

	if (!s1)
		return (NULL);
	l = ft_strlen(s1);
	s2 = (char *) malloc(l + 1);
	if (!s2)
		return (s2);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
