/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:27:54 by hlalouli          #+#    #+#             */
/*   Updated: 2022/12/22 16:49:07 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	check_extension(char *name_map)
{
	int	len;

	len = 0;
	len = ft_strlen(name_map);
	if ((name_map[len - 1] == 'b' && name_map[len - 2] == 'u'
			&& name_map[len - 3] == 'c'
			&& name_map[len - 4] == '.'))
		return (0);
	return (1);
}

int	check_player(t_data *data, char	**tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'E')
				data->map.e++;
			else if (tab[i][j] == 'N')
				data->map.n++;
			else if (tab[i][j] == 'S')
				data->map.s++;
			else if (tab[i][j] == 'W')
				data->map.w++;
			j++;
		}
		i++;
	}
	if (somme_players(data) != 1)
		return (1);
	else
		return (0);
}

char	**alloc_map(int a, int somme, t_var var, char	*name_map)
{
	var.d = malloc(sizeof(char *) * (a + 1));
	protected_array(var.d);
	var.j = -1;
	var.fd = open_fd(name_map);
	var.line = get_next_line(var.fd);
	while (var.line && !wall(var.line))
		var.line = free_and_null(var.line, var.fd);
	while (a-- > 0)
	{
		var.i = 0;
		var.k = 0;
		var.d[++var.j] = malloc(somme + 1);
		protected(var.d[var.j]);
		while (var.k < somme)
		{
			if (var.line[var.i] == '\n')
				var.d[var.j][var.k++] = ' ';
			else
				var.d[var.j][var.k++] = var.line[var.i++];
		}
		var.d[var.j][var.k] = '\0';
		var.line = free_and_null(var.line, var.fd);
	}
	var.d[++var.j] = NULL;
	return (var.d);
}

void	check_numb(t_data *data)
{
	if (data->map.ea != 1 || data->map.we != 1
		|| data->map.no != 1 || data->map.so != 1
		|| data->map.c != 1 || data->map.f != 1)
		error_msg("Invalid texture");
}

char	**check_doc(char *name_map, t_data *data)
{
	char	**d;

	data->var.a = 0;
	data->var.i = 0;
	data->var.fd = open_fd(name_map);
	data->var.somme = 0;
	data->var.line = get_next_line(data->var.fd);
	while (data->var.line && !wall(data->var.line))
	{
		if (data->var.line[0] != '\n')
			check_line(data->var.line, data);
		data->var.line = free_and_null(data->var.line, data->var.fd);
	}
	check_numb(data);
	while (data->var.line != NULL)
	{
		line_num(data->var.line);
		if (ft_strlen(data->var.line) >= data->var.somme)
			data->var.somme = ft_strlen(data->var.line);
		data->var.a++;
		data->var.line = free_and_null(data->var.line, data->var.fd);
	}
	d = alloc_map(data->var.a, data->var.somme - 1, data->var, name_map);
	return (close(data->var.fd), d);
}
