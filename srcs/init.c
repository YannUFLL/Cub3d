/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:16:27 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/19 17:51:06 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_init_data(t_data *data)
{
	data->mlx_win = NULL;
	data->mlx = NULL;
	data->floor = -1;
	data->ceiling = -1;
	data->player_spawn_dir = 0;
	data->player_spawn_pos[0] = 0;
	data->player_spawn_pos[1] = 0;
	data->edge_size = 16;
	data->fov = 70;
	data->resolution_x = 1920;
	data->resolution_y = 1080;
	data->move_speed = 0.1;
	data->rotate_speed = 0.1;
	data->keycode = -1;
	data->textures_nb = 7;
	data->line_length = 0;
	data->bits_per_pixel = 0;
	data->keycode = 0;
	data->zbuffer = malloc(sizeof(double) * data->resolution_x);
	data->numsprites = 1;
	ft_init_texture(data->texture);
	return (0);
}

int	ft_init_display(t_data *data)
{
	data->display = mlx_new_image(data->mlx, data->resolution_x,
			data->resolution_y);
	data->display_add = mlx_get_data_addr(data->display,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	return (0);
}

void	ft_init_direction(t_data *data, t_ray *ray)
{
	if (data->player_spawn_dir == 'S')
	{
		ray->dir_x = 0;
		ray->dir_y = 1;
		ray->plane_x = -(double)data->fov / 100;
		ray->plane_y = 0;
	}
	if (data->player_spawn_dir == 'N')
	{
		ray->dir_x = 0;
		ray->dir_y = -1;
		ray->plane_x = (double)data->fov / 100;
		ray->plane_y = 0;
	}
	if (data->player_spawn_dir == 'W')
	{
		ray->dir_x = 1;
		ray->dir_y = 0;
		ray->plane_x = 0;
		ray->plane_y = -(double)data->fov / 100;
	}
	if (data->player_spawn_dir == 'E')
	{
		ray->dir_x = -1;
		ray->dir_y = 0;
		ray->plane_x = 0;
		ray->plane_y = (double)data->fov / 100;
	}
}

void	ft_init_key(t_key *key)
{
	key->move_forward = 0;
	key->move_back = 0;
	key->move_left = 0;
	key->move_right = 0;
	key->rotate_left = 0;
	key->rotate_right = 0;
	key->mouse_rotate_left = 0;
	key->mouse_rotate_right = 0;
}

void	ft_init_ray_data(t_data *data, t_ray *ray)
{
	ray->pos_x = data->player_spawn_pos[0] + 0.5 ;
	ray->pos_y = data->player_spawn_pos[1] + 0.5 ;
	ray->map = data->map;
	ray->hit = 0;
	ray->side = 0;
	ray->color = 0x9B9B9B;
	ray->resolution_x = data->resolution_x;
	ray->resolution_y = data->resolution_y;
	ft_init_direction(data, ray);
	ray->camera_x = 0;
	ray->raydir_x = 0;
	ray->raydir_y = 0;
	ray->ray_side_x = 0;
	ray->ray_side_y = 0;
	ray->ray_delta_x = 0;
	ray->ray_delta_y = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->map_x = 0;
	ray->map_y = 0;
	ray->texx = 0;
	ray->texy = 0;
	ray->door_open = 0;
	ray->pos_door_x = 0;
	ray->pos_door_y = 0;
	ray->wall_x = 0;
	ray->step = 0;
	ray->texpos = 0;
	ft_init_key(&data->key);
}
