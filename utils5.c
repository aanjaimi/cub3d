/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 10:16:27 by aanjaimi          #+#    #+#             */
/*   Updated: 2023/01/15 22:20:28 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	wall(char *wall)
{
	int		i;

	i = 0;
	while (wall[i])
	{
		while (wall[i] == ' ')
			i += 1;
		if (wall[i] == '1')
			return (1);
		return (0);
	}
	return (1);
}

int	somme_players(t_data *data)
{
	return (data->map.n + data->map.s + data->map.e + data->map.w);
}

void	check_path(char *name, char	*line, t_data *data, int flag)
{
	int		i;
	char	*file;

	file = malloc(ft_strlen(name));
	protected(file);
	i = -1;
	while (++i < ft_strlen(name) - 1)
		file[i] = name[i];
	file[i] = 0;
	i = open(file, O_RDONLY);
	if (i == -1)
	{
		free(line);
		free(file);
		error_msg("failed path");
	}
	data->img = mlx_xpm_file_to_image(data->var.mlx, file, \
	&data->texture_img[flag].path_img_width, \
	&data->texture_img[flag].path_img_heigth);
	data->texture_img[flag].dst = mlx_get_data_addr(data->img, \
	&data->texture_img[flag].bpp, &data->texture_img[flag].ln, \
	&data->texture_img[flag].en);
	free(file);
	close(i);
}

void	calcule_distances(t_data *data)
{
	data->hor_dis = calcule_dis(data->ply.x1, data->ply.y1, \
	data->ray.next_hor_touch_x, data->ray.next_hor_touch_y);
	data->ver_dis = calcule_dis(data->ply.x1, data->ply.y1, \
	data->ray.next_ver_touch_x, data->ray.next_ver_touch_y);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
