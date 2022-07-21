/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:08:02 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/21 15:16:37 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_print_wall(t_data *data, int x, int y)
{
	int	old_x;
	int	old_y;

	old_y = y * 10;
	while (old_y <= ((y * 10) + 10))
	{
		old_x = x * 10;
		while (old_x <= ((x * 10) + 10))
		{
			my_mlx_pixel_put(data, old_x, old_y, 0xD3D3D3);
			old_x++;
		}
		old_y++;
	}
}

void	ft_print_walkable(t_data *data, int x, int y)
{
	int	old_x;
	int	old_y;

	old_y = y * 10;
	while (old_y <= ((y * 10) + 10))
	{
		old_x = x * 10;
		while (((old_y != (y * 10)) || (old_y != (y * 10 + 10)))
			&& (old_x <= ((x * 10) + 10)))
		{
			my_mlx_pixel_put(data, old_x, old_y, 16777215);
			old_x++;
		}
		old_y++;
	}
}

void	ft_print_grind(t_data *data, t_ray *ray)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (ray->map[y])
	{
		x = 0;
		while (ray->map[y][x])
		{
			if (ray->map[y][x] > '0')
				ft_print_wall(data, x, y);
			if (ray->map[y][x] <= '0' || ray->map[y][x] == 'N'
				|| ray->map[y][x] == 'S' || ray->map[y][x] == 'W'
				|| ray->map[y][x] == 'E')
				ft_print_walkable(data, x, y);
			x++;
		}
	y++;
	}
}

void	ft_print_pos(t_data *data, t_ray *ray)
{
	int	x;
	int	y;

	x = (ray->pos_x * 10) - 3;
	y = (ray->pos_y * 10) - 3;
	while (y <= (ray->pos_y * 10) + 3)
	{
		x = (ray->pos_x * 10) - 3;
		while (x <= ((ray->pos_x * 10) + 3))
		{
			my_mlx_pixel_put(data, x, y, 65280);
			x++;
		}
		y++;
	}
}

void	ft_print_minimap(t_data *data, t_ray *ray)
{
	ft_print_grind(data, ray);
	ft_print_pos(data, ray);
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->display, 0, 0);
}
