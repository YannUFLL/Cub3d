/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_border_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:44:17 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/13 17:44:17 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	ft_check_player_spawn(t_map_data *d, t_data *data)
{
	int				i;
	int				j;
	char			**map;
	int				is_spawn;
	static int		add_door = 0;

	is_spawn = 1;
	map = data->map.tab;
	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map && map[i] && map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' \
			|| map[i][j] == 'E')
			{
				d->posY = i;
				d->posX = j;
				is_spawn = 0;
			}

			if (map[i][j] == 'D' && add_door == 0)
			{
				printf("ajoue de texture!!!\n");
				add_door = 1;
				ft_add_texture(data, map, j, i);
			}
			j++;
		}
		i++;
	}
	return (is_spawn);
}

void	ft_init_map_data(t_map_data *map_data, t_data *data)
{
	map_data->map = data->map.tab;
	map_data->posX = -1;
	map_data->posY = -1;
	map_data->x_start = -1;
	map_data->y_start = -1;
	map_data->dir = 'E';
	map_data->height = data->map.height;
	map_data->width = data->map.width;
	map_data->nb_pass = 0;
	map_data->nb_move = 0;
	map_data->no_move_possible = 0;
	map_data->is_againt_wall = 0;
}

int	ft_check_map_border(t_map_data *d, t_data *data)
{
	int	i;
	int	ret;

	i = 0;
	while (i < 4)
	{
		ret = ft_follow_wall_left(d, i);
		if (ret)
			return (1);
		ft_init_map_data(d, data);
		ft_check_player_spawn(d, data);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		ret = ft_follow_wall_right(d, i);
		if (ret)
			return (1);
		ft_init_map_data(d, data);
		ft_check_player_spawn(d, data);
		i++;
	}
	return (0);
}

int	ft_check_map(t_data *data)
{
	t_map_data	map_data;
	int			ret;

	ft_init_map_data(&map_data, data);
	if (ft_check_player_spawn(&map_data, data))
	{
		printf("Error\nNo spawner\n");
		exit(0);
	}
	ret = ft_check_map_border(&map_data, data);
	if (ret)
	{
		printf("Error\nMap is open in (%d, %d)\n\n", map_data.posX, map_data.posY);
		ft_print_map(&map_data);
		return (1);
	}
	if (ft_check_ext_wall(&map_data))
	{
		printf("Error\nMap is not close in (%d, %d)\n\n", \
		map_data.posX, map_data.posY);
		ft_print_map(&map_data);
		exit (0);
	}
	ft_print_map(&map_data);
	return (0);
}
