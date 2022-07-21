/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:15:52 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/21 19:21:51 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_draw_line_ceil(t_data *data, t_ray *ray, t_flo *flo, int x)
{
	int	width;
	int	*text2;

	ray->text_select = 5;
	text2 = data->texture[ray->text_select].addr;
	width = data->texture[ray->text_select].img_width;
	while (ray->drawend < ray->resolution_y)
	{
		ft_calc_pos_textfloor(ray, flo, data, width);
		my_mlx_pixel_put(data, x, data->resolution_y - ray->drawend,
			text2[width * flo->floortexty + flo->floortextx]);
		ray->drawend++;
	}
}

void	ft_draw_line_both(t_data *data, t_ray *ray, t_flo *flo, int x)
{
	int	width;
	int	*text1;
	int	*text2;

	ray->text_select = 4;
	text1 = data->texture[ray->text_select].addr;
	text2 = data->texture[ray->text_select + 1].addr;
	width = data->texture[ray->text_select].img_width;
	while (ray->drawend < ray->resolution_y)
	{
		ft_calc_pos_textfloor(ray, flo, data, width);
		my_mlx_pixel_put(data, x, ray->drawend,
			text1[width * flo->floortexty + flo->floortextx]);
		my_mlx_pixel_put(data, x, data->resolution_y - ray->drawend,
			text2[width * flo->floortexty + flo->floortextx]);
		ray->drawend++;
	}
}

void	ft_draw_line_floor(t_data *data, t_ray *ray, t_flo *flo, int x)
{
	int	width;
	int	*text1;

	ray->text_select = 4;
	text1 = data->texture[ray->text_select].addr;
	width = data->texture[ray->text_select].img_width;
	while (ray->drawend < ray->resolution_y)
	{
		ft_calc_pos_textfloor(ray, flo, data, width);
		my_mlx_pixel_put(data, x, ray->drawend,
			text1[width * flo->floortexty + flo->floortextx]);
		ray->drawend++;
	}
}
