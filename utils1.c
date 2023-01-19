/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:07:35 by hlalouli          #+#    #+#             */
/*   Updated: 2022/12/22 16:44:31 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*res;

	res = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		res[i] = (unsigned char) c;
		i++;
	}	
	return (res);
}

void	ft_bzero(void *s, size_t n)
{
	if (n > 0)
		ft_memset(s, '\0', n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	if (!res)
		error_msg("Error");
	ft_bzero(res, size * count);
	return (res);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char )s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

long	check_non_num(char *str)
{
	int				i;
	long long		n;
	int				signe;

	i = 0;
	n = 0;
	signe = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i++] - '0';
		if (n * signe > 2147483647 || n * signe < -2147483648)
			error_msg("problem in atoi");
	}
	if (str[i] == '\0' && str[i - 1] == '-')
		error_msg("problem in atoi");
	if (str[i] && str[i] != '\n' && (str[i] < '0' || str[i] > '9'))
		error_msg("problem in atoi");
	return (n * signe);
}
