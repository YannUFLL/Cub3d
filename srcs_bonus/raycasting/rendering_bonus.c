/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:31:47 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/26 23:11:53 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

/*
void	ft_printf_ray(t_ray *ray)
{
	printf("\n\n");
	printf("camera x : %f \n", ray->camera_x);
	printf("plane x : %f \n", ray->plane_x);
	printf("plane y : %f \n", ray->plane_y);
	printf("dir x  : %f \n ", ray->dir_x);
	printf("dir y : %f \n", ray->dir_y);
	printf("raydir x : %f \n", ray->raydir_x);
	printf("raydir y : %f \n", ray->raydir_y);
	printf("pos x : %f \n", ray->pos_x);
	printf("pos y : %f \n", ray->pos_y);
	printf("map x : %d \n", ray->map_x);
	printf("map y : %d \n", ray->map_y);
	printf("ray_side_x : %f \n", ray->ray_side_x);
	printf("ray_side_y : %f \n", ray->ray_side_y);
	printf("ray_delta_x : %f \n", ray->ray_delta_x);
	printf("ray_delta_y : %f \n", ray->ray_delta_y);
	printf("step x : %d \n", ray->step_x);
	printf("step y : %d \n", ray->step_y);
	printf("ray_wall_distance : %f \n", ray->walldistance);
}
*/

#if FOG == 1
void	ft_put_ceiling_and_roof(t_data *data)
{
	int	x;
	int	y;
	int color;
	float shade;
	float ratio;

	ratio = 1 / ((float)data->resolution_y / 2);
	shade = 0.40;
	y = 0;
	while (y < data->resolution_y)
	{
		x = 0;
		if (y > data->resolution_y / 2)
		{
			shade -= ratio;
			color = ft_mix_color(data->floor,data->fog_color, shade);
		}
		else
		{
			shade += ratio; 
			color = ft_mix_color(data->ceiling,data->fog_color, shade);
		}
		while (x < data->resolution_x)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
	y++;
	}
}
#else

void	ft_put_ceiling_and_roof(t_data *data)
{
	int	x;
	int	y;
	int color;

	y = 0;
	while (y < data->resolution_y)
	{
		x = 0;
		if (y > data->resolution_y / 2)
			color = data->floor;
		else
			color = data->ceiling; 
		while (x < data->resolution_x)
		{
			my_mlx_pixel_put(data, x, y, color);
			x++;
		}
	y++;
	}
}
#endif

void	ft_init_ray(t_ray *ray, int x)
{
	ray->hit = 0;
	ray->text_select = 0;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->camera_x = 2 * x / ray->resolution_x - 1;
}

void	ft_movements(t_data *data)
{
	t_key	*key;

	key = &data->key;
	ft_move_straight(&data->ray_data, data, key);
	ft_move_right(&data->ray_data, data, key);
	ft_move_left(&data->ray_data, data, key);
	ft_rotate_left(&data->ray_data, data, key);
	ft_rotate_right(&data->ray_data, data, key);
	ft_mouse_rotate_left(&data->ray_data, key);
	ft_mouse_rotate_right(&data->ray_data, key);
	return ;
}
#include <sys/time.h>
int	time_diff(struct timeval *start, struct timeval *end);
void	ft_wall_casting(t_data *data, t_ray *ray)
{
	int	x;

	x = 0;
	while (x < ray->resolution_x)
	{
		ft_init_ray(ray, x);
		ft_calc_ray_dir(ray);
		ft_calc_ray_delta(ray);
		ft_calc_rayside(ray);
		ft_launch_ray(ray);
		ft_calc_wall_distance(ray);
		ft_use(data, ray);
		ft_calc_wall_line(ray);
		ft_choose_texture(ray);
		ft_calc_x_texture(data);
		ft_calc_y_texture(data);
		data->zbuffer[x] = ray->walldistance;
		ft_print_texture(data, ray, x);
		//ft_printf_ray(ray);
		ft_floor_casting(data, ray, x);
		x++;
	}
}

int	ft_render_next_frame(t_data *data)
{
	t_ray	*ray;

	ray = &data->ray_data;
	ft_put_ceiling_and_roof(data);
	ft_fps();
	ft_movements(data);
	ft_wall_casting(data, ray);
	ft_sprite_casting(data, ray, data->sprite);
	ft_print_minimap_render(data, ray, &data->minimap);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->display, 0, 0);
	ft_event(ray, data);
	return (0);
}
