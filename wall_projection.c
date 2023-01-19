/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_projection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 11:52:50 by aanjaimi          #+#    #+#             */
/*   Updated: 2023/01/19 03:54:57 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	calc_3d(t_data	*data, int i)
{
	data->prj.dist_pro = (WIDTH / 2) \
	/ tan(data->fov_angle / 2);
	data->prj.project_wall_h = (double)(IMG_SIZE / data->rays[i].cor) * \
		data->prj.dist_pro;
		data->prj.wall_strip_h = data->prj.project_wall_h;
		data->prj.wall_tp_p = (HEIGHT / 2) \
			- (data->prj.wall_strip_h / 2);
		data->prj.wall_bot_p = (HEIGHT / 2) \
			+ (data->prj.wall_strip_h / 2);
}

void	color_ciel_floor(t_data *data, int i)
{
	int	x;

	x = -1;
	while (++x < data->prj.wall_tp_p)
		my_mlx_pixel_put_map(data, i, x, data->ceil_color);
	x = data->prj.wall_bot_p - 1;
	while (++x < HEIGHT)
		my_mlx_pixel_put_map(data, i, x, data->floor_color);
}

void	render_wall_3d(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->num_rays)
	{
		calc_3d(data, i);
		color_ciel_floor(data, i);
		j = data->prj.wall_tp_p - 1;
		while (++j < data->prj.wall_bot_p)
		{
			if (data->rays[i].ver == 0 && data->rays[i].up)
				img_no(data, i, j, calc_x(data, i, NO));
			else if (data->rays[i].ver == 0 && data->rays[i].down)
				img_so(data, i, j, calc_x(data, i, SO));
			else if (data->rays[i].ver && data->rays[i].right)
				img_ea(data, i, j, calc_x(data, i, EA));
			else if (data->rays[i].ver && data->rays[i].left)
				img_we(data, i, j, calc_x(data, i, WE));
		}
	}
}
