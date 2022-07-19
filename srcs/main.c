/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:38:35 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/19 16:39:23 by ydumaine         ###   ########.fr       */
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


int ft_free(t_data *data)
{
	int	x; 

	x = 0;
	while (x < data->textures_nb)
	{
		if (data->texture[3].path != NULL)
			free(data->texture[3].path);
		x++;
	}
	return (0);

}

int	ft_check_arg(int argc)
{
	if (argc > 2)
	{
		printf("Error\nToo Much arguments");
		return (1);
	}
	if (argc < 2)
	{
		printf("Error\nNeed 2 arguments");
		return (1);
	}
	return (0);
}


int	main(int argc, char **argv)
	{
	t_data data;

	if (ft_check_arg(argc) == 1)
		return (0);
	ft_init_data(&data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.resolution_x, data.resolution_y, "LE MEILLEUR JEU AU MONDE ");
	ft_init_display(&data);
	if (ft_parsing(&data, argv[1]) == 1)
		return (ft_free(&data));
	ft_init_ray_data(&data, &data.ray_data);
	ft_init_text(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, ft_key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, ft_key_release, &data);
	mlx_hook(data.mlx_win, 6, 1L << 6, ft_mouse, &data);
	mlx_loop_hook(data.mlx, ft_render_next_frame, &data);
	mlx_loop(data.mlx);
	}