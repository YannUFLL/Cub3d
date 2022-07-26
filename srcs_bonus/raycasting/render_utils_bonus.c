/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 21:15:20 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/26 02:50:40 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"
#include <sys/time.h>

typedef struct s_color 
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
}	t_color;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	data->b[x][y] = color;
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

int	ft_mix_color(int color1, int color2, float power)
{
	t_color c1;
	t_color c2;

	if (power > 1)
		power = 1;
	c1.blue = (char)color1;  
	c1.green = (char)(color1 >> 8);
	c1.red = (char)(color1 >> 16);  
	c2.blue = (char)color2;
	c2.green = (char)(color2 >> 8);  
	c2.red = (char)(color2 >> 16);  
	c1.red = (1 - power) * c1.red + power * c2.red; 
	c1.green = (1 - power) * c1.green + power * c2.green; 
	c1.blue = (1 - power) * c1.blue + power * c2.blue; 
	return ( c1.red << 16 | c1.green << 8 | c1.blue);

}
