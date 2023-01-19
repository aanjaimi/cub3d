/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:34:03 by hlalouli          #+#    #+#             */
/*   Updated: 2022/12/22 16:45:45 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	error_msg(char *str)
{
	printf("%s\n", str);
	exit(0);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (0);
}

void	line_num(char *line)
{
	int	j;

	j = 0;
	while (line[j] && line[j] != '\n')
	{
		if (!ft_strchr("01ESNW ", line[j++]))
		{	
			free(line);
			error_msg("Error\nInvalid Map");
		}
	}
}

char	*free_and_null(char	*line, int fd)
{
	free(line);
	line = NULL;
	line = get_next_line(fd);
	return (line);
}

int	open_fd(char	*name)
{
	int	fd;

	fd = open(name, O_RDONLY);
	if (fd < 0)
		error_msg("Error in open file");
	return (fd);
}
