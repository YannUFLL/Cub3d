/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 12:31:03 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/05 17:12:12 by ydumaine         ###   ########.fr       */
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
		return (-1);
	while (line[*i] && line[*i] != ',')
		(*i)++;
	return (0);
}

int	ft_parse_color(char *line, t_data *data, int rc)
{
	int	i;
	int reset; 
	int red; 
	int green; 
	int blue; 
	
	reset = 1;
	if ((rc == 5 && data->floor != -1) || (rc == 6 && data->ceiling != -1))
		reset = 0;
	i = 0;
	red = ft_extract_color(line, &i);
	green = ft_extract_color(line, &i);
	blue = ft_extract_color(line, &i);
	if (rc == 5 && (red > 0 && green > 0 && blue > 0))
		(data->floor) = red << 16 | green << 8 | blue; 
	if (rc == 6 && (red > 0 && green > 0 && blue > 0))
		(data->ceiling) = red << 16 | green << 8 | blue; 
	if (rc == 5 && reset == 1 && (red < 0 || green < 0 || blue < 0))
		(data->floor) = -1; 
	if (rc == 6 && reset == 1 && (red < 0 || green < 0 || blue < 0))
		(data->ceiling) = -1; 
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
	if (ft_rm_if_already_exist(rc, data) == 1)
		data->no = ft_substr(line, i, j);
	if (ft_rm_if_already_exist(rc, data) == 2)
		data->so = ft_substr(line, i, j);
	if (ft_rm_if_already_exist(rc, data) == 3)
		data->we = ft_substr(line, i, j);
	if (ft_rm_if_already_exist(rc, data) == 4)
		data->ea = ft_substr(line, i, j);
	return (0);
}