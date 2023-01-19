/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:57:17 by hlalouli          #+#    #+#             */
/*   Updated: 2022/12/22 16:46:41 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	check_which_one(char *s, t_data *data)
{
	if (!ft_strncmp(s, "EA", 255))
		data->map.ea++;
	if (!ft_strncmp(s, "SO", 255))
		data->map.so++;
	if (!ft_strncmp(s, "NO", 255))
		data->map.no++;
	if (!ft_strncmp(s, "WE", 255))
		data->map.we++;
	if (!ft_strncmp(s, "F", 255))
		data->map.f++;
	if (!ft_strncmp(s, "C", 255))
		data->map.c++;
}

int	is_valid_format(char	**tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '0')
			{
				if (tab[i + 1][j] == ' ' || tab[i + 1][j] == '\0')
					return (1);
				else if (tab[i - 1][j] == ' ' || tab[i - 1][j] == '\0')
					return (1);
				else if (tab[i][j + 1] == ' ' || tab[i][j + 1] == '\0')
					return (1);
				else if (tab[i][j - 1] == ' ' || tab[i][j - 1] == '\0')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	check_map(t_data *data, char **tab)
{
	if (is_valid_format(tab) == 1)
		error_msg("Invalid map");
	else if (check_player(data, tab) == 1)
		error_msg("Invalid map");
	else if (is_valid_formats(tab) == 1)
		error_msg("Invalid map");
	else if (is_valid_formate(tab) == 1)
		error_msg("Invalid map");
	else if (is_valid_formatw(tab) == 1)
		error_msg("Invalid map");
	else if (is_valid_formatn(tab) == 1)
		error_msg("Invalid map");
}

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

void	protected(char *file)
{
	if (!file)
		error_msg("malloc");
}
