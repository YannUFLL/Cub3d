/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 15:31:47 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/17 20:15:43dumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <unistd.h>
#include <sys/time.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->display_add + (y * data->line_length + x * (data->bits_per_pixel / 8)); 
	*(unsigned int*)dst = color;
}
int	time_diff(struct timeval *start, struct timeval *end)
{
	return ((end->tv_sec - start->tv_sec)
		* 1000 + ((end->tv_usec - start->tv_usec) / 1000));
}

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


void	ft_put_ceiling_and_roof(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while(x <= data->resolution_x)
	{
		y = data->resolution_y / 2;
		y = 0;
		while (y <= data->resolution_y / 2)
		{
			my_mlx_pixel_put(data, x, y, data->floor);
			y++;
		}
		/*
		while (y <= data->resolution_y)
		{
			my_mlx_pixel_put(data, x, y,0x87CEEB );
			y++;
		}*/
	x++;
	}
}

void	ft_fps(void)
{
	static struct timeval time;
	struct timeval actual_time;
	static int	fps; 
	if (fps == 0)
	{
		gettimeofday(&time, NULL);
	}
	fps++;
	gettimeofday(&actual_time, NULL); 
	if (time_diff(&time, &actual_time) > 1000)
	{
		ft_printf("fps : %d\n", fps);
		fps = 0; 
	}
	return ;
}


void	ft_init_ray(t_ray *ray, int x)
{
	ray->hit = 0; 
	ray->text_select = 0;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->camera_x =  2 * x / ray->resolution_x - 1;
}
void	ft_movements(t_data *data)
{
	
	t_key *key;
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
int	ft_render_next_frame(t_data *data)
{
	int	x;
	t_ray *ray;

	ray = &data->ray_data;
	x = 0;
	ft_printf("1\n");
	ft_put_ceiling_and_roof(data);
	ft_fps();
	ft_movements(data);
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
		ft_print_texture(data, ray, x);
		//ft_printf_ray(ray);
		ft_floor_casting(data, ray, x);
		data->zbuffer[x] = ray->walldistance; 
		x++;
	}
	ft_print_minimap(data, ray);
	ft_printf("12\n");
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->display, 0, 0);
	ft_printf("13\n");
	ft_event(ray);
	return (0);
}


	
	/*if (keycode == 53)
		ft_exit(data->map);*/
