/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcasting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:02:24 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/17 20:19:31 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calc_ray_dir(t_ray *ray)
{
	ray->raydir_x =	ray->dir_x + ray->plane_x * ray->camera_x;
	ray->raydir_y =	ray->dir_y + ray->plane_y * ray->camera_x;
	if (ray->raydir_x == 0)
		ray->raydir_x = 0.000001;
	if (ray->dir_y == 0)
		ray->raydir_y = 0.000001;
}

void ft_calc_ray_delta(t_ray *ray)
{
		//ay->ray_delta_y = sqrt(1 + ((ray->raydir_x * ray->raydir_x ) / ( ray->raydir_y * ray->raydir_y))); // distance a parcourir pour aller a l'intersection suivante
		//ray->ray_delta_x = sqrt(1 + ((ray->raydir_y * ray->raydir_y ) / ( ray->raydir_x * ray->raydir_x)));  // attention si cette formule fisheyes 
		ray->ray_delta_y = fabs(1 / ray->raydir_y);
		ray->ray_delta_x = fabs(1 / ray->raydir_x);
		//printf("ray->delta_y : %f\n", ray->ray_delta_y);
		//printf("ray->delta_x : %f\n", ray->ray_delta_x);
}

void ft_calc_rayside(t_ray *ray)
{
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;  //composante de la direction du rayon (si -1 negative)
		ray->ray_side_x = (ray->pos_x - ray->map_x) * ray->ray_delta_x; 
	}
	else
	{
		ray->step_x = 1;
		ray->ray_side_x = (ray->map_x + 1 - ray->pos_x) * ray->ray_delta_x; 
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->ray_side_y = (ray->pos_y - ray->map_y) * ray->ray_delta_y; 
	}
	else
	{
		ray->step_y = 1;
		ray->ray_side_y = (ray->map_y + 1 - ray->pos_y) * ray->ray_delta_y; 
	}
}

void ft_launch_ray(t_ray *ray)
{
	while (ray->hit == 0) 
	{
		if (ray->ray_side_x < ray->ray_side_y)
		{
			ray->ray_side_x += ray->ray_delta_x; 
			ray->map_x += ray->step_x; 
			ray->side = 0;
		}
		else 
		{
			ray->ray_side_y += ray->ray_delta_y;
			ray->map_y += ray->step_y; 
			ray->side = 1;
		}
		if (ray->map[ray->map_y][ray->map_x] == '1' || ray->map[ray->map_y][ray->map_x] == '2')
			ray->hit = 1; 
		if (ray->map[ray->map_y][ray->map_x] == '2')
			ray->text_select = 4;
	}
}

void	ft_calc_wall_distance(t_ray *ray)
{
	if (ray->side == 0)
		ray->walldistance = (ray->ray_side_x - ray->ray_delta_x); // on prend la distance dx car c'est le rayon x qui a connecte au mur en premier
	else if (ray->side == 1) 
		ray->walldistance = (ray->ray_side_y - ray->ray_delta_y); // come on est un carre trop loin il faut enlever la distance de 1 carrere

}

