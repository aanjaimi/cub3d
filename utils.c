/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:33:37 by hlalouli          #+#    #+#             */
/*   Updated: 2022/12/22 16:55:00 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	initialisation(t_data *data)
{
	init1(data);
	init2(data);
}

void	put_color(t_data *data, char **sp, int flag)
{
	if (flag == 0)
		data->ceil_color = create_trgb(0, check_non_num(sp[0]), \
		check_non_num(sp[1]), check_non_num(sp[2]));
	else
		data->floor_color = create_trgb(0, check_non_num(sp[0]), \
		check_non_num(sp[1]), check_non_num(sp[2]));
}

void	check_color(char *line, char *line1, t_data *data, int flag)
{
	char	**sp;
	int		i;
	int		j;

	i = 0;
	j = -1;
	i = ft_count(line, ',');
	if (i != 3)
	{
		free(line);
		error_msg("Problem in color");
	}
	sp = ft_split(line, ',');
	while (sp[++j])
	{
		if (check_non_num(sp[j]) < 0 || check_non_num(sp[j]) > 255)
		{
			free(line1);
			error_msg("ERROR : out of range ");
		}
	}
	put_color(data, sp, flag);
	ft_free(sp);
}

void	check_paths(t_data *data, char **sp, char *line)
{
	if ((!ft_strncmp(sp[0], "EA", 255) || !ft_strncmp(sp[0], "NO", 255) \
		||!ft_strncmp(sp[0], "WE", 255) || !ft_strncmp(sp[0], "SO", 255)))
	{
		check_which_one(sp[0], data);
		if (!ft_strncmp(sp[0], "EA", 255))
			check_path(sp[1], line, data, EA);
		else if (!ft_strncmp(sp[0], "NO", 255))
			check_path(sp[1], line, data, NO);
		else if (!ft_strncmp(sp[0], "WE", 255))
			check_path(sp[1], line, data, WE);
		else
			check_path(sp[1], line, data, SO);
	}
	else if (!ft_strncmp(sp[0], "F", 255) || !ft_strncmp(sp[0], "C", 255))
	{
		check_which_one(sp[0], data);
		if (!ft_strncmp(sp[0], "F", 255))
			check_color(sp[1], line, data, 1);
		else
			check_color(sp[1], line, data, 0);
	}
	else
		error_msg("Invalid Identifier");
}

void	check_line(char *line, t_data *data)
{
	char	**sp;
	int		i;

	i = ft_count(line, ' ');
	if (i != 2)
	{
		free(line);
		error_msg("problem in line");
	}
	sp = ft_split(line, ' ');
	check_paths(data, sp, line);
	ft_free(sp);
}
