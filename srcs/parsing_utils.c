/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:31:03 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/14 16:06:14 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_extract_color(char *line, int *i)
{
	int color;

	while (((line[*i] && line[*i] >= 9 && line[*i] <= 13) || line[*i] == 32))
		(*i)++;
	color =	ft_atoi(&line[*i]);
	if (color < 0 || color > 255)
	{
		printf("Error\ncolor not standard");
		return (-1);
	}
	while (line[*i] && line[*i] != ',')
		(*i)++;
	(*i)++;
	return (color);
}

int	ft_parse_color(char *line, t_data *data, int rc)
{
	int	i;
	int red; 
	int green; 
	int blue; 
	
	i = 0;
	red = ft_extract_color(line, &i);
	green = ft_extract_color(line, &i);
	blue = ft_extract_color(line, &i);
	if (red == -1 || green == -1 || blue == -1)
		return (1);
	if (rc == 5)
		(data->floor) = red << 16 | green << 8 | blue; 
	if (rc == 6)
		(data->ceiling) = red << 16 | green << 8 | blue; 
	return (0);
}

int	ft_copy_texture(char *line, t_data *data, int rc)
{
	int	i; 
	int	j;

	i = 0; 
	j = 0;
	while (((line[i] >= 9 && line[i] <= 13) || line[i] == 32) && line[i])
		i++;
	if (line[i])
	{
		j = i;
		while ((line[j] < 9 || line[j] > 13) && line[j] != 32 && line[j])
			j++;
	}
	ft_rm_if_already_exist(rc, data);
	if (rc == 1)
		data->texture[0].path = ft_substr(line, i, j);
	if (rc == 2)
		data->texture[1].path = ft_substr(line, i, j);
	if (rc == 3)
		data->texture[2].path = ft_substr(line, i, j);
	if (rc == 4)
		data->texture[3].path = ft_substr(line, i, j);
	return (0);
}
