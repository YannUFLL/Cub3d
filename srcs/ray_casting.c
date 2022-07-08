/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:31:47 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/08 19:52:14 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct ray_data
{
	double	resolution_x; 
	double	camera_x;
	double	plane_x; 
	double	plane_y;
	double	dir_x; 
	double	dir_y; 
	double	raydir_x; 
	double	raydir_y; 
	double	pos_x;
	double	pos_y;
	double	offset_side_x;
	double	offset_side_y;
	double	offset_hypo_x; 
	double	offset_hypo_y; 
	double	side_x; 
	double	side_y;
	double	hypo_x; 
	double	hypo_y; 
	double	hit;
	char **map;
}
		t_ray

void	ft_init_direction(t_data *data, t_ray *ray)
{
	if (data->player_spawn_dir == 'S')
	{
		ray_data->dir_x = 0; 
		ray_data->dir_y = -1;
		ray_data->plane_x = -data>fov / 100; 
		ray_data->plane_y = 0;
	}
	if (data->player_spawn_dir == 'N')
	{
		ray_data->dir_x = 0; 
		ray_data->dir_y = 1;
		ray_data->plane_x = data->fov / 100;
		ray_data->plane_y = 0;
	}
	if (data->player_spawn_dir == 'W')
	{
		ray_data->dir_x = 1; 
		ray_data->dir_y = 0;
		ray_data->plane_x = 0;
		ray_data->plane_y = data->fov / 100; 
	}
	if (data->player_spawn_dir == 'E')
	{
		ray_data->dir_x = -1; 
		ray_data->dir_y = 0;
		ray_data->plane_x = 0;
		ray_data->plane_y = -data->fov / 100; 
	}
}
int ft_launch_ray(t_ray *ray_data)
void	ft_init_ray_data(t_data *data, t_ray *ray)
{
	ray->posx = data->posx; 
	ray->posy = data->posy; 
	ray->map = data->map; 
	rayrdata->resolution_x = data->resolution_x; 
	ft_init_direction(data, ray)



}
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst; 

	dst = data->display_add + (y * data->line_length + x * (data->bits_per_pixel / 8)); 
	*(unsigned int*)dst = color; 
}

// calcul of ray vector 
int	ft_render_next_frame(t_data *data)
{
	int	x; 

	x = 0;
	while (x < ray->resolution_x)
	{
		ray->camera_x = 2 * x / ray->resolution_x - 1;
		ray->raydir_x =	ray->dir_x + ray->plane_x * ray->camera_x
		ray->raydir_y =	ray->dir_y + ray->plane_y * ray->camera_x
	}
}

int	ft_launch_ray(t_ray ray)
{

}
/*
void ft_init_raycaster(t_data *data)
{

}
*/