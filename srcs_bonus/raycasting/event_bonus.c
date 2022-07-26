/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:33:42 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/26 23:18:25 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_use(t_data *data, t_ray *ray)
{
	if (data->key.use == 1 && ray->walldistance < 1 \
		&& ray->text_select == TEXTURE_DOOR && ray->door_open != 1)
	{
		ray->door_open = 1;
		ray->pos_door_x = ray->map_x;
		ray->pos_door_y = ray->map_y;
	}
}

void	ft_event(t_ray *ray, t_data *data)
{
	static int count; 
	static int	count_sprite; 
	int i;
	static int sprite_texture_select; 

	i = 0;
	if (count_sprite == 10)
	{
		count_sprite = 0;
		while (i < data->sprites_nb)
		{
			data->sprite[i].select_sprite =  data->sprite[i].texture[0]; 
			if (data->sprite[i].texture[1] != -1)
				data->sprite[i].select_sprite = data->sprite[i].texture[sprite_texture_select];
			i++;
		}
		sprite_texture_select++;
		if (sprite_texture_select == 5)
			sprite_texture_select = 0;
	}
	else 
		count_sprite++; 
	

	if (ray->map[(int)ray->pos_door_y][(int)ray->pos_door_x] != '/' && ray->door_open == 1 && count != 30)
	{
		if (ray->size_door <= 0)
			ray->map[(int)ray->pos_door_y][(int)ray->pos_door_x] = '/';
		else 
			ray->size_door -= 0.020; 
	}
	else if (ray->map[(int)ray->pos_door_y][(int)ray->pos_door_x] == '/' && ray->door_open == 1
	 && ray->map[(int)ray->pos_y][(int)ray->pos_x] != '/')
	{
		if (count != 30)
			count++;
		if (count == 30)
			ray->map[(int)ray->pos_door_y][(int)ray->pos_door_x] = '2';
	}
	else if (ray->map[(int)ray->pos_door_y][(int)ray->pos_door_x] == '2' && ray->door_open == 1 && count == 30)
	{
			ray->size_door += 0.020;
			if (ray->size_door >= 1)
			{
				count = 0;
				ray->door_open = 0;
			}
	}

	else if (count != 30)
		count = 0;
}