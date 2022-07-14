/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:38:35 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/14 17:26:45 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
int	ft_test_color(int color, t_data *data)
{
	int x; 
	int y; 

	y = 0; 
	while (y < 800)
	{
		x = 0;
		y++; 
		while (x < 800)
		{
			x++;
			mlx_pixel_put(data->mlx, data->mlx_win, x, y, color);
		}
	}	
	return (0);
}
*/
void	ft_init_texture(t_texture *tex)
{
	int	x;
	x = 0;
	while(x < 4)
	{
		tex[x].path = NULL;
		tex[x].mlx_img = NULL;
		tex[x].addr = NULL;
		tex[x].img_width = 0;
		tex[x].img_height = 0;
		tex[x].lenght = 0;
		tex[x].bit_per_pixel = 0;
		tex[x].endian = 0;
		x++;
	}
}

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
	ft_init_texture(data->texture);
	return (0);
}

int	ft_init_display(t_data *data) 
{
	data->display = mlx_new_image(data->mlx, data->resolution_x, data->resolution_y);
	data->display_add = mlx_get_data_addr(data->display, 
		&data->bits_per_pixel, &data->line_length, &data->endian);
	return (0);
}

int ft_free(t_data *data)
{
	if (data->texture[0].path != NULL)
		free(data->texture[0].path);
	if (data->texture[1].path != NULL)
		free(data->texture[1].path);
	if (data->texture[2].path != NULL)
		free(data->texture[2].path);
	if (data->texture[3].path != NULL)
		free(data->texture[3].path);
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
	
}

int	ft_init_text(t_data *data)
{
	int	x = 0;
	int	y = 0;
	t_texture *text;
	text = data->texture; 
	printf("path : %s\n ", text[0].path);
	text[0].mlx_img = mlx_xpm_file_to_image(data->mlx, text[0].path, &text[0].img_width, &text[0].img_height);
	text[0].addr = (int *)mlx_get_data_addr(text[0].mlx_img, &text[0].bit_per_pixel, &text[0].lenght, &text[0].endian);
	while (y < 256)
	{
	x = 0;
	while (x < 256)
	{
		//printf("valeur de int : %d\n", (int)(*(text[0].addr + y * text[0].lenght  + x * (text[0].bit_per_pixel / 8))));
		//my_mlx_pixel_put(data, x, y, (int)(*(text[0].addr + y * text[0].lenght  + x * (text[0].bit_per_pixel / 8))));
		printf("valeur de int : %d\n", ((text[0].addr)[x]));
		my_mlx_pixel_put(data, x, y, ((text[0].addr)[y * text[0].img_width + x]));
		x++;
	}
	y++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->display, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
	{
	(void)argc; 
	(void)argv;
	t_data data; 

	if (argc > 2)
	{
		printf("Error\nToo Much arguments");
		return (0);
	}
	if (argc < 2)
	{
		printf("Error\nNeed 2 arguments");
		return (0);
	}
	ft_init_data(&data);
	data.mlx = mlx_init(); 
	data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "LE MEILLEUR JEU AU MONDE ");
	ft_init_display(&data);
	if (ft_parsing(&data, argv[1]) == 1)
		return (ft_free(&data));
	ft_init_ray_data(&data, &data.ray_data);
	ft_init_text(&data);
//	lx_hook(data.mlx_win, 2, 1L << 0, ft_key_press, &data);
//	mlx_hook(data.mlx_win, 3, 1L << 1, ft_key_release, &data);
//	mlx_loop_hook(data.mlx, ft_render_next_frame, &data);
	mlx_loop(data.mlx);
	}