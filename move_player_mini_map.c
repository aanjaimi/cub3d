/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_mini_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:13:31 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/12/22 14:12:57 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	find_p(t_data *data)
{
	data->p_i = 0;
	while (data->var.d[data->p_i])
	{
		data->p_j = 0;
		while (data->var.d[data->p_i][data->p_j] &&
			data->var.d[data->p_i][data->p_j] != '\n')
		{
			if (data->var.d[data->p_i][data->p_j] == 'N'
				|| data->var.d[data->p_i][data->p_j] == 'S'
				|| data->var.d[data->p_i][data->p_j] == 'W'
				|| data->var.d[data->p_i][data->p_j] == 'E')
			{
				set_rotation(data, data->var.d[data->p_i][data->p_j]);
				return ;
			}
			data->p_j++;
		}
		data->p_i++;
	}
}

static int	check_nor(t_data *data, double x, double y)
{
	if (x / SIZE_MINI >= 0 && x / SIZE_MINI < data->var.win_height
		&& y / SIZE_MINI >= 0 && y / SIZE_MINI < data->var.win_width
		&& data->var.d[(int)(x / SIZE_MINI)][(int)(y / SIZE_MINI)] == '1')
		return (0);
	return (1);
}

int	check_wall(t_data *data, char dir)
{
	double	x;
	double	y;

	if (dir == 2)
		data->ply.side_dir = -1;
	else if (dir == 0)
		data->ply.side_dir = 1;
	else if (dir == 13)
		data->ply.walk_dir = 1;
	else
		data->ply.walk_dir = -1;
	if (data->ply.side_dir != 0)
	{
		x = next_x_pos_side(data);
		y = next_y_pos_side(data);
	}
	else
	{
		x = next_x_pos(data);
		y = next_y_pos(data);
	}
	return (check_nor(data, x, y));
}

void	move_player(t_data *data, char dir)
{
	if ((dir == 2 || dir == 0) && check_wall(data, dir))
	{
		data->ply.side_dir = 1;
		if (dir == 2)
			data->ply.side_dir = -1;
		data->ply.x1 = next_x_pos_side(data);
		data->ply.y1 = next_y_pos_side(data);
	}
	else if ((dir == 1 || dir == 13) && check_wall(data, dir))
	{
		data->ply.walk_dir = 1;
		if (dir == 1)
			data->ply.walk_dir = -1;
		data->ply.x1 = next_x_pos(data);
		data->ply.y1 = next_y_pos(data);
	}
	else if (dir == 123 || dir == 124)
	{
		data->ply.turn_dir = 1;
		if (dir == 123)
			data->ply.turn_dir = -1;
		data->ply.rotation_angle += (data->ply.turn_dir \
		* data->ply.turn_speed);
	}
	render(data);
}

void	ft_reset(t_data *data, char dir)
{
	if (dir == 2)
		data->ply.side_dir = 0;
	else if (dir == 0)
		data->ply.side_dir = 0;
	else if (dir == 1)
		data->ply.walk_dir = 0;
	else if (dir == 13)
		data->ply.walk_dir = 0;
	else if (dir == 123)
		data->ply.turn_dir = 0;
	else if (dir == 124)
		data->ply.turn_dir = 0;
	render(data);
}
