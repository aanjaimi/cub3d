/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:32:50 by hlalouli          #+#    #+#             */
/*   Updated: 2022/11/21 20:54:20 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*new_line(char *hou)
{
	int		i;
	char	*line;

	i = 0;
	if (!hou)
		return (NULL);
	while (hou[i] && hou[i] != '\n')
		i++;
	line = ft_substr(hou, 0, i + 1);
	return (line);
}

int	line(char *hou)
{
	int	i;

	i = 0;
	if (!hou)
		return (0);
	while (hou[i])
	{
		if (hou[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*rest(char *hou)
{
	int		i;
	int		len;
	char	*line1;

	i = 0;
	if (!hou)
		return (NULL);
	len = ft_strlen(hou);
	while (hou[i] && hou[i] != '\n')
		i++;
	line1 = ft_substr(hou, i + 1, len - i + 1);
	free(hou);
	hou = NULL;
	return (line1);
}

char	*get_next_line(int fd)
{
	static char	*hou;
	int			k;
	char		*new;
	char		buff[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (line(hou) == 1)
		return (new = new_line(hou), hou = rest(hou), new);
	k = read(fd, buff, BUFFER_SIZE);
	if (k <= 0)
	{
		if (!hou)
			return (NULL);
		if (!*hou)
			return (free(hou), hou = NULL, NULL);
		new = ft_strdup(hou);
		free(hou);
		hou = NULL;
		return (new);
	}
	buff[k] = 0;
	hou = ft_strjoin(hou, buff);
	return (get_next_line(fd));
}
