/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <hlalouli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:16:26 by hlalouli          #+#    #+#             */
/*   Updated: 2022/12/22 16:47:06 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cub3d.h"

int	is_valid_formats(char	**tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'S')
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

int	is_valid_formatn(char	**tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'N')
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

int	is_valid_formatw(char	**tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'W')
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

int	is_valid_formate(char	**tab)
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

void	protected_array(char **file)
{
	if (!file)
		error_msg("malloc");
}
