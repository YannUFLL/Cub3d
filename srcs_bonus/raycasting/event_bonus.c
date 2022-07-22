/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:33:42 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/22 00:27:35 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_use(t_data *data, t_ray *ray)
{
	if (data->key.use == 1 && ray->walldistance < 1 \
	&& ray->text_select == TEXTURE_DOOR)
		ray->map[ray->map_y][ray->map_x] = '/';
}

void	ft_event(t_ray *ray)
{
	if (ray->map[(int)ray->pos_y][(int)ray->pos_x] == '/'
		&& ray->door_open == 0)
	{
		ray->pos_door_y = (int)ray->pos_y;
		ray->pos_door_x = (int)ray->pos_x;
		ray->door_open = 1;
	}
	if (ray->map[(int)ray->pos_y][(int)ray->pos_x] != '/'
		&& ray->door_open == 1)
	{
		ray->door_open = 0;
		ray->map[(int)ray->pos_door_y][(int)ray->pos_door_x] = '2';
	}
}
