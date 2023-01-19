/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:13:02 by aanjaimi          #+#    #+#             */
/*   Updated: 2022/12/14 11:23:25 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	dda(t_data *data, double x, double y)
{
	t_dda	var;

	var.x = data->ply.x1;
	var.y = data->ply.y1;
	var.dx = x - var.x;
	var.dy = y - var.y;
	var.steps = fmax(fabs(var.dy), fabs(var.dx));
	var.inc_x = var.dx / var.steps;
	var.inc_y = var.dy / var.steps;
	data->var.i = -1;
	while (++data->var.i < var.steps)
	{
		my_mlx_pixel_put(data, \
			(int)(var.y), (int)(var.x), data->ray_color);
		var.x += var.inc_x;
		var.y += var.inc_y;
	}
}

double	calcule_dis(double x1, double y1, double x2, double y2)
{
	double	final;

	final = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	return (final);
}
