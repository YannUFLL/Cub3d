/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:15:20 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/22 16:08:40 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"
#include <sys/time.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	static int	octet;
	static int	line_lenght; 

	if (line_lenght == 0)
		line_lenght = data->line_length;
	if (octet == 0)
		octet = data->bits_per_pixel / 8;
	*(unsigned int *)(data->display_add
			+ (y * line_lenght + x * 4)) = color;
}

int	time_diff(struct timeval *start, struct timeval *end)
{
	return ((end->tv_sec - start->tv_sec)
		* 1000 + ((end->tv_usec - start->tv_usec) / 1000));
}


void	ft_fps(void)
{
	static struct timeval	time;
	struct timeval			actual_time;
	static int				fps;
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
