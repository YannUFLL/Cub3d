/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallcasting_part_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 20:06:52 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/17 20:18:46 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_calc_wall_line(t_ray *ray)
{
	ray->lineheight = (int)(ray->resolution_y / ray->walldistance);
	ray->drawstart = (-ray->lineheight / 2) + (ray->resolution_y / 2);
	ray->drawend = (ray->lineheight / 2) + (ray->resolution_y / 2);
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	if (ray->drawend >= ray->resolution_y)
		ray->drawend = ray->resolution_y - 1;
}