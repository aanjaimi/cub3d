/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanjaimi <aanjaimi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:18:15 by hlalouli          #+#    #+#             */
/*   Updated: 2023/01/19 03:59:44 by aanjaimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	img_no(t_data *data, int i, int j, int x)
{
	int	y;
	int	color;

	y = (j - data->prj.wall_tp_p) * \
		((double)data->texture_img[NO].path_img_heigth \
		/ data->prj.wall_strip_h);
	color = *((int *)((data->texture_img[NO].dst) + \
		((int)(y % data->texture_img[NO].path_img_heigth) * \
		data->texture_img[NO].ln + \
		(int)(x % data->texture_img[NO].path_img_width) * \
		(data->texture_img[NO].bpp / 8))));
	my_mlx_pixel_put_map(data, i, j, color);
}

void	img_so(t_data *data, int i, int j, int x)
{
	int	y;
	int	color;

	y = (j - data->prj.wall_tp_p) * \
		((double)data->texture_img[SO].path_img_heigth \
		/ data->prj.wall_strip_h);
	color = *((int *)((data->texture_img[SO].dst) + \
		((int)(y % data->texture_img[SO].path_img_heigth) * \
		data->texture_img[SO].ln + \
		(int)(x % data->texture_img[SO].path_img_width) * \
		(data->texture_img[SO].bpp / 8))));
	my_mlx_pixel_put_map(data, i, j, color);
}

void	img_we(t_data *data, int i, int j, int x)
{
	int	y;
	int	color;

	y = (j - data->prj.wall_tp_p) * \
		((double)data->texture_img[WE].path_img_heigth \
		/ data->prj.wall_strip_h);
	color = *((int *)((data->texture_img[WE].dst) + \
		((int)(y % data->texture_img[WE].path_img_heigth) * \
		data->texture_img[WE].ln + \
		(int)(x % data->texture_img[WE].path_img_width) * \
		(data->texture_img[WE].bpp / 8))));
	my_mlx_pixel_put_map(data, i, j, color);
}

void	img_ea(t_data *data, int i, int j, int x)
{
	int	y;
	int	color;

	y = (j - data->prj.wall_tp_p) * \
		((double)data->texture_img[EA].path_img_heigth \
		/ data->prj.wall_strip_h);
	color = *((int *)((data->texture_img[EA].dst) + \
		((int)(y % data->texture_img[EA].path_img_heigth) * \
		data->texture_img[EA].ln + \
		(int)(x % data->texture_img[EA].path_img_width) * \
		(data->texture_img[EA].bpp / 8))));
	my_mlx_pixel_put_map(data, i, j, color);
}

int	calc_x(t_data *data, int i, int dir)
{
	int	x;

	x = 0;
	if (data->rays[i].ver)
		x = (data->rays[i].y / IMG_SIZE - (int)(data->rays[i].y) / IMG_SIZE) \
		* data->texture_img[dir].path_img_width;
	else
		x = (data->rays[i].x / IMG_SIZE - (int)(data->rays[i].x) / IMG_SIZE) \
		* data->texture_img[dir].path_img_width;
	return (x);
}
