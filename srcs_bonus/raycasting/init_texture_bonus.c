/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:18:52 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/27 17:22:14 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_cpy_texture(t_data *data, t_texture **new_texture)
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

void	ft_fill_new_texture(t_data *data, t_texture **new_texture, char c)
{
	if (c == 'B')
		(*new_texture)[data->textures_nb - 1].path = "./sprites/barrel.xpm";
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

void	ft_add_texture(t_data *data, int x, int y, int *j)
{
	t_texture	*new_texture;
	char		c;

	printf("add texture : x : %d, y : %d", x, y);
	data->textures_nb += 1;
	new_texture = NULL;
	ft_cpy_texture(data, &new_texture);
	c = data->map.tab[y][x];
	ft_fill_new_texture(data, &new_texture, c);
	data->sprites_nb += 1;
	data->sprite[*j].x = x + 0.5;
	data->sprite[*j].y = y + 0.5;
	data->sprite[*j].texture[0] = data->textures_nb - 1;
	data->sprite[*j].texture[1] = -1;
	data->sprite[*j].select_sprite = 0;
	*j += 1;
	data->texture = new_texture;
}

void	ft_init_texture(t_data *data)
{
	int	x;

	data->textures_nb = 8;
	data->sprites_nb = 0;
	data->texture = malloc(sizeof(t_texture) * data->textures_nb);
	x = 0;
	while (x < data->textures_nb)
	{
		data->texture[x].path = NULL;
		data->texture[x].mlx_img = NULL;
		data->texture[x].addr = NULL;
		data->texture[x].img_width = 0;
		data->texture[x].img_height = 0;
		data->texture[x].lenght = 0;
		data->texture[x].bit_per_pixel = 0;
		data->texture[x].endian = 0;
		data->texture[x].type = 0;
		if (x == TEXTURE_FLOOR || x == TEXTURE_CEIL)
			data->texture[x].use_color = 1;
		else
			data->texture[x].use_color = 0;
		x++;
	}
}

int	ft_init_text(t_data *data)
{
	int			x;
	t_texture	*text;

	x = 0;
	text = data->texture;
	while (x < data->textures_nb)
	{
		if (!(text[x].use_color))
		{
			text[x].mlx_img = mlx_xpm_file_to_image(data->mlx, \
				text[x].path, &text[x].img_width, &text[x].img_height);
			if (text[x].mlx_img == NULL)
			{
				printf("Error\nTexture %d not found: %s\n", x, text[x].path);
				exit(0);
			}
			text[x].addr = (int *)mlx_get_data_addr(text[x].mlx_img, \
				&text[x].bit_per_pixel, &text[x].lenght, &text[x].endian);
		}
		x++;
	}
	return (0);
}
