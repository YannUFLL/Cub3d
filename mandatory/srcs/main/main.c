/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:38:35 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/20 23:25:48 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;

	ft_init_data(&data);
	if (ft_checker(argc, argv, &data) || ft_parsing(&data))
		return (ft_free_texture(&data));
	// FOR TESTING A SUPPRIMER
	/*
	data.texture[4].path = "texture/door_256.xpm";
	data.texture[5].path = "texture/floor_512.xpm";
	data.texture[6].path = "texture/ceiling_512.xpm";
	data.texture[7].path = "texture/barrel.xpm";
	data.sprite[0].texture = 7;
	data.sprite[0].x = 8;
	data.sprite[0].y = 8;
	data.sprite[1].x = 9;
	data.sprite[1].y = 9;
	*/
	ft_replace_space(&data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.resolution_x, data.resolution_y, "WOLFENCHTEIN");
	ft_init_display(&data);
	ft_init_ray_data(&data, &data.ray_data);
	ft_init_text(&data);
	mlx_hook(data.mlx_win, 2, 1L << 0, ft_key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, ft_key_release, &data);
	mlx_hook(data.mlx_win, 6, 1L << 6, ft_mouse, &data);
	mlx_loop_hook(data.mlx, ft_render_next_frame, &data);
	mlx_loop(data.mlx);
}
