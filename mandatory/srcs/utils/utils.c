/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:02:29 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/21 02:58:58 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_print_logo(t_map_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		printf("\u2B1B");
	else if (data->map[i][j] == '0')
		printf("\u2B1C");
	else if (data->map[i][j] == ' ')
		printf("  ");
	else if (data->map[i][j] == '.')
		printf("\u2B55");
	else if (data->map[i][j] == 'N' || data->map[i][j] == 'S' \
	|| data->map[i][j] == 'W' || data->map[i][j] == 'E')
		printf("\u2B50");
	else
		printf("%c", (data->map[i][j]));
}

void	ft_print_map(t_map_data *data)
{
	int		i;
	int		j;
	char	temp;
	int		temp_i;
	int		temp_j;

	i = -1;
	while (data->map && data->map[++i])
	{
		j = -1;
		while (data->map && data->map[i] && data->map[i][++j])
		{
			if (data->posX == j && data->posY == i)
			{
				temp_i = i;
				temp_j = j;
				temp = data->map[i][j];
				data->map[i][j] = '.';
			}
			ft_print_logo(data, i, j);
		}
		printf("\n");
	}
	data->map[temp_i][temp_j] = temp;
}

void	ft_printlogo(char **map, int i, int j)
{
	if (map[i][j] == '1')
		printf("\u2B1B");
	else if (map[i][j] == '0')
		printf("\u2B1C");
	else if (map[i][j] == ' ')
		printf("  ");
	else if (map[i][j] == 'N')
		printf(" \u2B06");
	else if (map[i][j] == 'S')
		printf(" \u2B07");
	else if (map[i][j] == 'W')
		printf(" \u2B05");
	else if (map[i][j] == 'E')
		printf(" \u27A1");
	else if (map[i][j] == '.')
		printf("\u2B55");
	else
		printf("%c", (map[i][j]));
}

void	ft_printmap(t_data *data, char **map)
{
	int		i;
	int		j;
	char	temp;
	int		temp_i;
	int		temp_j;

	i = -1;
	while (map && map[++i])
	{
		j = -1;
		while (map && map[i] && map[i][++j])
		{
			if (data->player_spawn_pos[0] == j && \
			data->player_spawn_pos[1] == i)
			{
				temp_i = i;
				temp_j = j;
				temp = map[i][j];
				map[i][j] = '.';
			}
			ft_printlogo(map, i, j);
		}
		printf("\n");
	}
	map[temp_i][temp_j] = temp;
}
