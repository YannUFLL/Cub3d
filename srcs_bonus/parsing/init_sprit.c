/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 14:36:35 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/27 01:43:49 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_cpy_old_texture(t_data *data, t_texture **new_texture)
{
	int	i;

	*new_texture = malloc(sizeof(t_texture) * (data->textures_nb + 1));
	i = 0;
	while (i < data->textures_nb - 1)
	{
		(*new_texture)[i].path = malloc(sizeof(char) \
		* (ft_strlen(data->texture[i].path) + 1));
		ft_strlcpy((*new_texture)[i].path, data->texture[i].path,
			ft_strlen(data->texture[i].path) + 1);
		if (data->texture[i].path && ft_is_not_sprite(data, i))
			free(data->texture[i].path);
		(*new_texture)[i].mlx_img = data->texture[i].mlx_img;
		(*new_texture)[i].addr = data->texture[i].addr;
		(*new_texture)[i].img_width = data->texture[i].img_width;
		(*new_texture)[i].img_height = data->texture[i].img_height;
		(*new_texture)[i].lenght = data->texture[i].lenght;
		(*new_texture)[i].bit_per_pixel = data->texture[i].bit_per_pixel;
		(*new_texture)[i].endian = data->texture[i].endian;
		(*new_texture)[i].use_color = data->texture[i].use_color;
		(*new_texture)[i].type = data->texture[i].type;
		i++;
	}
	free(data->texture);
}

void	ft_fill_new_texture2(t_data *data, t_texture **new_texture, char c, int i)
{
	if (c == 'M' && i == 0)
		(*new_texture)[data->textures_nb - 1].path = "./sprites/champ_1.xpm";
	else if (c == 'M' && i == 1)
		(*new_texture)[data->textures_nb - 1].path = "./sprites/champ_2.xpm";
	else if (c == 'M' && i == 2)
		(*new_texture)[data->textures_nb - 1].path = "./sprites/champ_3.xpm";
	else if (c == 'M' && i == 3)
		(*new_texture)[data->textures_nb - 1].path = "./sprites/champ_4.xpm";
	else if (c == 'M' && i == 4)
		(*new_texture)[data->textures_nb - 1].path = "./sprites/champ_5.xpm";
	else if (c == 'M' && i == 5)
		(*new_texture)[data->textures_nb - 1].path = "./sprites/champ_6.xpm";
	(*new_texture)[data->textures_nb - 1].mlx_img = NULL;
	(*new_texture)[data->textures_nb - 1].addr = NULL;
	(*new_texture)[data->textures_nb - 1].img_width = 0;
	(*new_texture)[data->textures_nb - 1].img_height = 0;
	(*new_texture)[data->textures_nb - 1].lenght = 0;
	(*new_texture)[data->textures_nb - 1].bit_per_pixel = 0;
	(*new_texture)[data->textures_nb - 1].endian = 0;
	(*new_texture)[data->textures_nb - 1].use_color = 0;
	(*new_texture)[data->textures_nb - 1].type = c;
}

void	ft_add_texture_anime(t_data *data, int x, int y, int *j)
{
	t_texture	*new_texture;
	char		c;
	int 		i;

	printf("add sprite anime: x : %d, y : %d", x, y);

	i = 0;
	data->sprites_nb += 1;
	data->sprite[*j].x = x + 0.5;
	data->sprite[*j].y = y + 0.5;
	while (i < 6)
	{
		data->textures_nb += 1;
		new_texture = NULL;
		ft_cpy_old_texture(data, &new_texture);
		c = data->map.tab[y][x];
		ft_fill_new_texture2(data, &new_texture, c, i);
		data->sprite[*j].texture[i] = data->textures_nb - 1;
		data->sprite[*j].select_sprite = 0;
		data->texture = new_texture;
		i++;
	}
	*j += 1;
}