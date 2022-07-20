/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:15:25 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/20 15:27:28 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "../../include/cub3d.h"

typedef struct sprite_calc
{
	int		i; 
	double sprite_x;
	double sprite_y;
	double invdet;
	double transformx;
	double transformy;
	int spritescreenx;
	int spriteheight;
	int drawstarty;
	int drawendy;
	int	drawstartx;
	int drawendx;
	int spritewidth;
	int stripe;
	int texx;
	int texy;
	int d;
	int	color; 
}	t_sprite_calc;


void	ft_sort_sprite(int	*sprite_order, double *sprite_distance, int numsprites)
{
	int	i;
	int	j;
	int	x;

	i = 1;
	while (i < numsprites)
	{
		x = sprite_order[i];
		j = i;
		while (j > 0 && (sprite_distance[x] < sprite_distance[sprite_order[j - 1]]))
		{	
				sprite_order[j] = sprite_order[j - 1]; //
				j = j - 1;
		}
		sprite_order[j] = x;
		i++;
	}	
}	

void	ft_calc_pos(t_sprite *sprite, t_sprite_calc *sp, t_ray *ray, t_data *data)
{
		sp->sprite_x = sprite[data->sprite_order[sp->i]].x - ray->pos_x ;
		sp->sprite_y = sprite[data->sprite_order[sp->i]].y - ray->pos_y ;
		sp->invdet = 1 / (ray->plane_x * ray->dir_y - ray-> dir_x * ray->plane_y);
		sp->transformx = sp->invdet * (ray->dir_y * sp->sprite_x - ray->dir_x * sp->sprite_y);
		sp->transformy = sp->invdet * (-ray->plane_y * sp->sprite_x + ray->plane_x * sp->sprite_y);
		sp->spritescreenx = (int)((data->resolution_x / 2) * (1 + sp->transformx / sp->transformy));
		sp->spriteheight = abs((int)(data->resolution_y / (sp->transformy)));
		sp->drawstarty = -sp->spritewidth / 2 + data->resolution_y / 2;
		if (sp->drawstarty < 0) 
			sp->drawstarty = 0;
		sp->drawendy = sp->spritewidth / 2 + data->resolution_y / 2;
		if (sp->drawendy >= data->resolution_x) 
			sp->drawendy = data->resolution_y - 1;
		sp->spritewidth = abs((int)(data->resolution_y / (sp->transformy)));
		sp->drawstartx= -sp->spritewidth / 2 + sp->spritescreenx ;
		if (sp->drawstartx < 0) 
			sp->drawstartx = 0;
		sp->drawendx = sp->spritewidth / 2 + sp->spritescreenx;  
		if (sp->drawendx >= data->resolution_x) 
			sp->drawendx = data->resolution_x- 1;
		sp->stripe = sp->drawstartx;
}

void	ft_print_sprite(t_sprite *sprite, t_sprite_calc *sp, t_data *data)
{
		while (sp->stripe < sp->drawendx)
		{
			sp->texx = (int)(256 * (sp->stripe - (-sp->spritewidth / 2 + sp->spritescreenx)) * data->texture[7].img_width / sp->spritewidth ) / 256; 
			if (sp->transformy > 0 && sp->stripe > 0 && sp->stripe < data->resolution_x && sp->transformy < data->zbuffer[sp->stripe])
				while (sp->drawstarty < sp->drawendy)
				{
					sp->d = sp->drawstarty * 256 - data->resolution_y * 128 + data->texture[7].img_height * 128;
					sp->texy = ((sp->d * data->texture[7].img_height));
					sp->color = data->texture[sprite[sp->i].texture].addr[data->texture[sprite[sp->i].texture].img_width * sp->texy + sp->texx];
					if (sp->color != 16777215)
					my_mlx_pixel_put(data, sp->drawstarty, sp->stripe, sp->color);
					sp->drawstarty++;
				}
		}
}

void	ft_sprite_casting(t_data *data, t_ray *ray, t_sprite *sprite)
{
	t_sprite_calc sp; 

	sprite = data->sprite; 
	sp.i = 0;
	while (sp.i < data->numsprites)
	{
		data->sprite_order[sp.i] = sp.i;
		data->sprite_distance[sp.i] = ((ray->pos_x - sprite[sp.i].x ) * (ray->pos_x - sprite[sp.i].x) + (ray->pos_y - sprite[sp.i].y ) *(ray->pos_y - sprite[sp.i].y ));
		sp.i++;
	}
	ft_sort_sprite(data->sprite_order, data->sprite_distance, data->numsprites);
	sp.i = 0;
	while (sp.i < data->numsprites)
	{
		ft_calc_pos(sprite, &sp, ray, data);
		ft_print_sprite(sprite, &sp, data);
		sp.i++;
	}
}*/

