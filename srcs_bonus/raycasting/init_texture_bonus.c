/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 19:18:52 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/21 21:50:18 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d_bonus.h"

void	ft_add_texture(t_data *data, char **map, int x, int y)
{
	t_texture	*new_texture;
	int			i;
	static int	j = 0;

	data->textures_nb += 1;


	new_texture = malloc(sizeof(t_texture) * (data->textures_nb + 1));
	i = 0;
	while (i < data->textures_nb - 1)
	{
		new_texture[i].path = malloc(sizeof(char) * (ft_strlen(data->texture[i].path) + 1));
		ft_strlcpy(
			new_texture[i].path,
			data->texture[i].path,
			ft_strlen(data->texture[i].path) + 1
		);

		printf("str a del : %s\n", data->texture[i].path);
		if (data->texture[i].path)
			free(data->texture[i].path);
		new_texture[i].mlx_img = data->texture[i].mlx_img;
		new_texture[i].addr = data->texture[i].addr;
		new_texture[i].img_width = data->texture[i].img_width;
		new_texture[i].img_height = data->texture[i].img_height;
		new_texture[i].lenght = data->texture[i].lenght;
		new_texture[i].bit_per_pixel = data->texture[i].bit_per_pixel;
		new_texture[i].endian = data->texture[i].endian;
		new_texture[i].use_color = data->texture[i].use_color;
		new_texture[i].type = data->texture[i].type;
		i++;
	}
	free(data->texture);

	new_texture[i].path = "sprites/door_256.xpm";
	new_texture[i].mlx_img = NULL;
	new_texture[i].addr = NULL;
	new_texture[i].img_width = 0;
	new_texture[i].img_height = 0;
	new_texture[i].lenght = 0;
	new_texture[i].bit_per_pixel = 0;
	new_texture[i].endian = 0;
	new_texture[i].use_color = 0;
	new_texture[i].type = map[y][x];


	data->sprites_nb += 1;
	data->sprite[j].x = x;
	data->sprite[j].x = y;
	data->sprite[j].texture = i;
	j++;

	data->texture = new_texture;

}

void	ft_init_texture(t_data *data)
{
	int	x;
	
	data->textures_nb = 6;
	data->sprites_nb = 0;
	data->texture = malloc(sizeof(t_texture) * data->textures_nb);
	x = 0;
	while(x < data->textures_nb)
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
			text[x].mlx_img = mlx_xpm_file_to_image(data->mlx,
				text[x].path, &text[x].img_width, &text[x].img_height);
			if (text[x].mlx_img == NULL)
			{
				printf("Error\nTexture %d not found: %s\n", x, text[x].path);
				exit(0);
			}
			text[x].addr = (int *)mlx_get_data_addr(text[x].mlx_img,
				&text[x].bit_per_pixel, &text[x].lenght, &text[x].endian);
		}
		x++; 
	}
	return (0);
}
