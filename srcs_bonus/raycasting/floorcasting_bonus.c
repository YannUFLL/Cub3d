/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floorcasting_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:38:32 by ydumaine          #+#    #+#             */
<<<<<<< HEAD:bonus/srcs/raycasting/floorcasting_bonus.c
/*   Updated: 2022/07/22 12:20:59 by ydumaine         ###   ########.fr       */
=======
/*   Updated: 2022/07/21 19:22:23 by jrasser          ###   ########.fr       */
>>>>>>> jm:srcs_bonus/raycasting/floorcasting_bonus.c
/*                                                                            */
/* ************************************************************************** */


#include "../../include/cub3d_bonus.h"
/*
typedef struct floor_casting
{
	float raydirx0;
	float raydirx1;
	float raydiry0;
	float raydiry1;
	int		p;
	float posZ;
	float rowdistance; 
	float floorstepx;
	float floorstepy;
	
	double	floorx;
	double	floory;
	int cellx;
	int celly;
	int tx;
	int ty;
	int floortexture;
	int ceilingtexture;
	int color;
	int *add_floor;
	int *add_ceiling;
	int width;
	int height;
}		t_flo;

void	ft_init_floor_casting(t_ray *ray, t_flo *flo, int y, t_data *data)
{
	flo->raydirx0 = ray->dir_x - ray->plane_x;
	flo->raydiry0 = ray->dir_y - ray->plane_y;
	flo->raydirx1 = ray->dir_x + ray->plane_x;
	flo->raydiry1 = ray->dir_y + ray->plane_y;
	flo->p = y - ray->resolution_y / 2;
	flo->posZ = 0.5 * ray->resolution_y;
	flo->rowdistance = flo->posZ / flo->p;
	flo->floorstepx = flo->rowdistance * (flo->raydirx1 - flo->raydirx0) / ray->resolution_x;
	printf("rowdistance : %f\n", flo->rowdistance);
	printf("dirx1 : %f\n", flo->raydirx1);
	printf("dirx0 : %f\n", flo->raydirx0);
	printf("res : %f\n", ray->resolution_x);
	flo->floorstepy = flo->rowdistance * (flo->raydiry1 - flo->raydiry0) / ray->resolution_x;
	flo->floorx = ray->pos_x + flo->rowdistance * flo->raydirx0;
	flo->floory = ray->pos_y + flo->rowdistance * flo->raydiry0;
	flo->floortexture = 4;
	flo->ceilingtexture = 5;
	flo->add_floor = data->texture[flo->floortexture].addr;
	flo->add_ceiling = data->texture[flo->ceilingtexture].addr;
	flo->width = data->texture[flo->floortexture].img_width; 
	flo->height = data->texture[flo->floortexture].img_height; 
}

void	ft_print_text(t_flo *flo, t_data *data, int y)
{
	int i; 
	i = 0;
	while (i < data->resolution_x)
	{
		flo->cellx = (int)(flo->floorx);
		flo->celly = (int)(flo->floory);
		flo->tx = (int)(flo->width * (flo->floorx - flo->cellx)) & (flo->width - 1);
		flo->ty = (int)(flo->height * (flo->floory - flo->celly)) & (flo->height - 1);
		printf("GROS CALCUL : %d\n", (int)(flo->width * (flo->floorx - flo->cellx))) ;
		printf("flo->tx : %d\n", flo->tx );
		printf("(flo->floory - flo->celly): %f\n", flo->floory - flo->celly );
		printf("(floorstepy): %f\n", flo->floorstepy );
		printf("(floor): %f\n", flo->floory );
		flo->floorx += flo->floorstepx;
		flo->floory += flo->floorstepy;
		flo->color = flo->add_floor[flo->width * flo->ty + flo->tx];
		//ft_printf("adresse texture : %d\n",flo->width * flo->ty + flo->tx);
		my_mlx_pixel_put(data, i, y, flo->color);
		flo->color = flo->add_ceiling[flo->width * flo->ty + flo->tx];
		my_mlx_pixel_put(data, i, data->resolution_y - y - 1, flo->color);
		i++;
		printf("\n\n\n\n\n");
		sleep(1);
	}
}


void	ft_floor_casting(t_data *data, t_ray *ray)
{
	t_flo	flo;
	int y; 

	y = 0;
	while (y < ray->resolution_y)
	{
		ft_init_floor_casting(ray, &flo, y, data);
		ft_print_text(&flo, data, y);
		y++;
	}
}
*/

void	ft_wall_direction(t_ray *ray, t_flo *flo)
{
	if (ray->side == 0 && ray->raydir_x > 0)
	{
		flo->floorxwall = ray->map_x;
		flo->floorywall = ray->map_y + ray->wall_x;
	}
	else if (ray->side == 0 && ray->raydir_x < 0)
	{
		flo->floorxwall = ray->map_x + 1;
		flo->floorywall = ray->map_y + ray->wall_x;
	}
	else if (ray->side == 1 && ray->raydir_y > 0)
	{
		flo->floorxwall = ray->map_x + ray->wall_x;
		flo->floorywall = ray->map_y;
	}
	else
	{
		flo->floorxwall = ray->map_x + ray->wall_x;
		flo->floorywall = ray->map_y + 1;
	}
}

void	ft_calc_pos_textfloor(t_ray *ray, t_flo *flo, t_data *data, int width)
{
	flo->currentdist = ray->resolution_y
		/ (2 * ray->drawend - ray->resolution_y);
	flo->weight = (flo->currentdist - flo->distplayer)
		/ (flo->distwall - flo->distplayer);
	flo->currentfloorx = flo->weight * flo->floorxwall
		+ (1 - flo->weight) * ray->pos_x;
	flo->currentfloory = flo->weight * flo->floorywall
		+ (1 - flo->weight) * ray->pos_y;
	flo->floortextx = (int)(flo->currentfloorx * width)
		% width;
	flo->floortexty = (int)(flo->currentfloory * width)
		% data->texture[ray->text_select].img_height;
}

<<<<<<< HEAD:bonus/srcs/raycasting/floorcasting_bonus.c
void	ft_draw_line(t_data *data, t_ray *ray, t_flo *flo, int x)
{
	int	width;
	int	*text1;
	int *text2;

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

=======
>>>>>>> jm:srcs_bonus/raycasting/floorcasting_bonus.c
void	ft_floor_casting(t_data *data, t_ray *ray, int x)
{
	t_flo	flo;

	ray->drawend = ray->drawend;
	flo.distwall = ray->walldistance;
	flo.distplayer = 0;
	ft_wall_direction(ray, &flo);
	if (ray->drawend < 0)
		ray->drawend = ray->resolution_y;
	if (data->texture[TEXTURE_FLOOR].use_color == 0 \
	&& data->texture[TEXTURE_CEIL].use_color == 0)
		ft_draw_line_both(data, ray, &flo, x);
	else if (data->texture[TEXTURE_FLOOR].use_color == 0)
		ft_draw_line_floor(data, ray, &flo, x);
	else if (data->texture[TEXTURE_CEIL].use_color == 0)
		ft_draw_line_ceil(data, ray, &flo, x);
}
