/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:38:35 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/21 21:42:31 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_data data;

	ft_init_data(&data);
	if (ft_checker(argc, argv, &data) || ft_parsing(&data))
		return (ft_free_texture(&data));
	ft_replace_space(&data);
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, data.resolution_x, \
	data.resolution_y, "WOLFENCHTEIN");
	data.texture[4].path = "bonus/texture/floor_512.xpm";
	data.texture[5].path = "bonus/texture/ceiling_512.xpm";
	data.texture[6].path = "bonus/texture/door_256.xpm";
	data.texture[7].path = "bonus/texture/barrel.xpm";
	data.sprite[0].texture = 7;
	data.sprite[1].texture = 7;
	data.sprite[2].texture = 7;
	data.sprite[0].x = 4.5;
	data.sprite[0].y = 1.5; 
	data.sprite[2].x = 4.7;
	data.sprite[2].y = 1.7; 
	data.sprite[1].x = 4.7;
	data.sprite[1].y = 2.7; 
	ft_init_display(&data);
	ft_init_ray_data(&data, &data.ray_data);
	ft_init_text(&data);
	mlx_hook(data.mlx_win, 17, 0, ft_exit_game, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, ft_key_press, &data);
	mlx_hook(data.mlx_win, 3, 1L << 1, ft_key_release, &data);
	mlx_hook(data.mlx_win, 6, 1L << 6, ft_mouse, &data);
	mlx_loop_hook(data.mlx, ft_render_next_frame, &data);
	mlx_loop(data.mlx);
}
