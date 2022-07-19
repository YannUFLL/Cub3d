/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_mouse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:54:47 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/19 17:56:12 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_mouse_rotate_right(t_ray *ray, t_key *key)
{
	double	old_dir_x;
	double	old_plane_x;
	int		rotate_nb;

	rotate_nb = 0;
	old_dir_x = ray->dir_x;
	old_plane_x = ray->plane_x;
	while (key->mouse_rotate_right > 1)
	{
		old_dir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(-0.005)
			- ray->dir_y * sin(-0.005);
		ray->dir_y = old_dir_x * sin(-0.005)
			+ ray->dir_y * cos(-0.005);
		old_plane_x = ray->plane_x;
		ray->plane_x = ray->plane_x * cos(-0.005)
			- ray->plane_y * sin(-0.005);
		ray->plane_y = old_plane_x * sin(-0.005)
			+ ray->plane_y * cos(-0.005);
	key->mouse_rotate_right--;
	}
}

void	ft_mouse_rotate_left(t_ray *ray, t_key *key)
{
	double	old_dir_x;
	double	old_plane_x;
	int		rotate_nb;

	rotate_nb = 0;
	old_dir_x = ray->dir_x;
	old_plane_x = ray->plane_x;
	while (key->mouse_rotate_left > 1)
	{
		old_dir_x = ray->dir_x;
		ray->dir_x = ray->dir_x * cos(0.005)
			- ray->dir_y * sin(0.005);
		ray->dir_y = old_dir_x * sin(0.005)
			+ ray->dir_y * cos(0.005);
		old_plane_x = ray->plane_x;
		ray->plane_x = ray->plane_x * cos(0.005)
			- ray->plane_y * sin(0.005);
		ray->plane_y = old_plane_x * sin(0.005)
			+ ray->plane_y * cos(0.005);
	key->mouse_rotate_left--;
	}
}
