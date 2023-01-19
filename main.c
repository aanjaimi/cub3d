/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:39:44 by hlalouli          #+#    #+#             */
/*   Updated: 2022/12/23 09:33:05 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

void	set_images(t_data *data)
{
	data->var.img_mini.img = mlx_new_image(data->var.mlx, \
	data->var.win_width * SIZE_MINI + 1, data->var.win_height * SIZE_MINI + 1);
	data->var.img_mini.addr = mlx_get_data_addr(data->var.img_mini.img, \
	&data->var.img_mini.bits_per_pixel, \
	&data->var.img_mini.line_length, &data->var.img_mini.endian);
	data->var.img_map.img = mlx_new_image(data->var.mlx, \
	WIDTH + 1, \
	HEIGHT + 1);
	data->var.img_map.addr = mlx_get_data_addr(data->var.img_map.img, \
	&data->var.img_map.bits_per_pixel, \
	&data->var.img_map.line_length, &data->var.img_map.endian);
}

void	unit_mlx_p(t_data *data)
{
	data->var.mlx = mlx_init();
	if (data->var.mlx == NULL)
		error_msg("Error in mlx");
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (ac == 2)
	{
		if (check_extension(av[1]) == 1)
			error_msg("Invalid extension");
	}
	initialisation(data);
	unit_mlx_p(data);
	data->var.d = check_doc(av[1], data);
	check_map(data, data->var.d);
	init_window(data);
	data->var.win_height = ft_count_height(data->var.d);
	data->var.win_width = ft_strlen(data->var.d[0]);
	set_images(data);
	find_p(data);
	loop_mlx(data);
	mlx_destroy_image(data->var.mlx, data->var.img_mini.img);
	mlx_destroy_image(data->var.mlx, data->var.img_map.img);
	free(data->rays);
	free(data);
	ft_free(data->var.d);
}
