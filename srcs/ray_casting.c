/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:31:47 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/09 20:17:42 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct ray_data
{
	double	resolution_x; 
	double	camera_x;
	double	plane_x; // vecteur plan camera
	double	plane_y;
	double	dir_x; // vecteur du regard du joueur
	double	dir_y; 
	double	raydir_x; // vecteur rayon lanceé pour detecter un mur
	double	raydir_y; 
	double	pos_x;	// position du joueur 
	double	pos_y;
	int		map_x; // position du carre dans lequel est le joueur sur la carte
	int		map_y; 
	double	side_x; //distance a parcourir avant la premiere intersection de la position du joueur 
	double	side_y;
	double	delta_x;// distance a parcourir avant une intersection 
	double	delta_y;
	int		step_x; // sens du rayon ( positif ou negatif ) x
	int		step_y; // sens du rayon ( positif ou negatif ) y
	int		hit;	// indique si un mur a ete touche 
	int		side =
	int		walldistance;
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
	ray->map_x = (int)pos_x;
	ray->map_y = (int)pos_y;
	while (x < ray->resolution_x)
	{
		ray->camera_x = 2 * x / ray->resolution_x - 1;
		ray->raydir_x =	ray->dir_x + ray->plane_x * ray->camera_x
		ray->raydir_y =	ray->dir_y + ray->plane_y * ray->camera_x
		if ray->dir_x = 0;
			ray->dir_x = exp(30);
		if ray->dir_y = 0;
			ray->dir_y = exp(30);
		deltay = sqrt(1 + ((ray->raydirx * ray->raydirx ) / ( ray->radiry * ray->raydiry)); // distance a parcourir pour aller a l'intersection suivante
		deltax = sqrt(1 + ((ray->raydiry * ray->raydiry ) / ( ray->radirx * ray->raydirx));
		if (ray->raydirx < 0)
		{
			ray->step_x = -1;
			ray->side_x = (ray->pos_x - ray->map_x) * ray->dist_x; 
		}
		else
		{
			ray->step_x = 1;
			ray->side_x = (ray->map_x + 1 - ray->pos_x) * ray->dist_x; 
		}
		if (ray->raydiry < 0)
		{
			ray->step_y = -1;
			ray->side_y = (ray->pos_y - ray->map_y) * ray->dist_y; 
		}
		else
		{
			ray->step_y = 1;
			ray->side_y = (ray->map_y + 1 - ray->pos_y) * ray->dist_y; 
		}
		while (ray->hit == 0) 
		{
			if (ray->side_x < ray->side_y)
			{
				ray->side_x += ray->delta_x; 
				ray->map_x += ray->step_x; 
				ray->side = 0;
			}
			else 
			{
				ray->side_y += delta_y;
				ray->map_y += step_y; 
				ray->side = 1;
			}
			if (ray->map[ray->map_x][ray->map_y] > 0) 
				ray->hit = 1; 
		}
		if (ray->side == 0)
			ray->walldistance = (ray->side_x - ray->delta_x)
		else 
			ray->walldistance = (ray->side_y - ray->delta_y)
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