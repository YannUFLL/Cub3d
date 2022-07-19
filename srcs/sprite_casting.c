/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_casting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 22:15:25 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/19 16:36:45 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include "cub3d.h"

typedef struct sprite_calc
{
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
}	t_sprite_calc


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
		while (j > 0 && (sprite_distance[x] < sprite_distance[classe[j - 1]]))
		{	
				sprite[j]->sprite_order = sprite_order[j - 1]; //
				j = j - 1;
		}
		sprite_order[j] = x;
		i++;
	}	
}	

ft_sprite_casting(t_data *data, t_ray *ray, t_sprite *sprite)
{
	int	classe[1000];
	int	i;
	t_sprite_calc sp; 

	sprite = data->sprite; 
	i = 0;
	while (i < data->numsprites)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((ray->pos_x - sprite[i]->x ) * (ray->pos_x - sprite[i]->x) + (ray->pos_y - sprite[i]->y ) *(ray->pos_y - sprite[i]->y ))
		i++;
	}
	ft_sort_sprite(data->sprite_order, data->sprite_distance, data->numsprites);
	i = 0;
	while (i < data->numsprites)
	{
		sp->sprite_x = sprite[sprite_order[i]].x - ray->pox_x ;
		sp->sprite_y = sprite[sprite_order[i]].y - ray->pox_y ;

		sp->invdet = 1 / (ray->plane_x * ray->dir_y - ray-> dir_x * ray->plane_y);
		sp->transformx = sp->invdet * (ray->dir_y * sp->spritex - ray->dir_x * sp->spritey);
		sp->transformy = sp->invdet * (-ray->plane_y * sp->spritex + ray->plane_x * sp->spritey);
		sp->spritescreenx = int((data->resolution_x / 2) * (1 + ray->transformx / ray->transformy));
		sp->spriteheight = abs(int(data->resolution_y / (sp->transformy)));
		sp->drawstarty = -sp->spritewidth / 2 + data->resolution_y / 2
		if (sp->drawstarty < 0) 
			sp->drawstarty = 0;
		sp->drawendy = sp->spritewidth / 2 + data->resolution_y / 2;
		if (sp->drawendy >= data->resolution_x) 
			sp->drawendy = data->resolution_y - 1;
		sp->spritewidth = abs(int(data->resolution_y / (sp->transformy)));
		sp->drawstartyx= -sp->spritewidth / 2 + sp->spritescreenx ;
		if (sp->drawstartx < 0) 
			sp->drawstartx = 0;
		sp->drawendx = sp->spritewidth / 2 + sp->spritescreenx;  
		if (sp->drawendx >= data->resolution_x) 
			sp->drawendx = data->resolution_x- 1;
		sp->stripe = sp->drawstartx;
		while (sp->sprite < sp->drawendx)
		{
			sp->texx = (int)(256 * (sp->sprite - (-sp->spritewidth / 2 + sp->spritescreenx)) * data->texture[7].img_width / sp->spritewidth ) / 256; 
			if (sp->transformy > 0 && sp->stripe > 0 && so->stripe < data->resolution_x && sp->transformy < data->zbuffer[sp->stripe]);
			while (sp->drawstarty < sp->drawendy)
			{
				sp->d = sp->drawstarty * 256 - data->resolution_y * 128 + data->texture[7].img_height * 128;
				sp->texy = ((sp->d * data->texture[7].img_height))
				color = data->texturep
			}
		}

	}
	i = 1;
}

*/