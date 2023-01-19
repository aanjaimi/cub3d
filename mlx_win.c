/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_win.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:53:00 by hlalouli          #+#    #+#             */
/*   Updated: 2022/12/22 16:55:49 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	ft_count_height(char	**str)
{
	int	j;

	j = 0;
	while (str[j])
		j++;
	return (j);
}

int	init_window(t_data *data)
{
	data->var.win = mlx_new_window(data->var.mlx, \
		WIDTH, \
		HEIGHT, "CUB3D");
	if (data->var.win == NULL)
	{
		free(data->var.win);
		error_msg("Error in window");
	}
	data->num_rays = WIDTH;
	data->rays = calloc(data->num_rays, sizeof(t_rays));
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= data->var.win_width * SIZE_MINI
		&& y >= 0 && y <= data->var.win_height * SIZE_MINI)
	{
		dst = data->var.img_mini.addr + (y * data->var.img_mini.line_length + \
		x * (data->var.img_mini.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	my_mlx_pixel_put_map(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= WIDTH
		&& y >= 0 && y <= HEIGHT)
	{
		dst = data->var.img_map.addr + (y * data->var.img_map.line_length + \
		x * (data->var.img_map.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	loop_mlx(t_data *data)
{
	mlx_loop_hook(data->var.mlx, &render, data);
	mlx_hook(data->var.win, 2, 1L, &handle_keypress, data);
	mlx_hook(data->var.win, 3, 1L, &handle_keyrelease, data);
	mlx_hook(data->var.win, 17, 1L, &handle_btnrealease, data);
	mlx_hook(data->var.win, 6, 1L, &handle_mouse, data);
	mlx_loop(data->var.mlx);
}
