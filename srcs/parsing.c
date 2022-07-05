/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:21:13 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/05 17:12:57 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_detect_element(char *line, int *i)
{
	int	rc ; 

	rc = 0; 
	if (ft_strncmp(&line[*i], "NO", 2))
		rc = 1;
	if (ft_strncmp(&line[*i], "SO", 2))
		rc = 2;
	if (ft_strncmp(&line[*i], "WE", 2))
		rc = 3;
	if (ft_strncmp(&line[*i], "EA", 2))
		rc = 4;
	if (ft_strncmp(&line[*i], "F", 1))
		rc = 5;
	if (ft_strncmp(&line[*i], "C", 2))
		rc = 6;
	if (ft_strncmp(&line[*i], "S", 2))
		rc = 7;
	while (line[*i] && (line[*i] < 9 || line[*i] > 13) && line[*i] != 32)
			(*i)++;
	return (rc);

}

int	ft_rm_if_already_exist(int rc, t_data *data)
{
	if (rc == 1)
	{
		if(data->no != NULL)
			free(data->no);
	}
	if (rc == 2)
	{
		if(data->so != NULL)
			free(data->so);
	}
	if (rc == 3)
	{
		if(data->we != NULL)
			free(data->we);
	}
	if (rc == 4)
	{
		if(data->ea != NULL)
			free(data->ea);
	}
	return (0);
}

int ft_parse_line(char *line, t_data *data)
{
	int i;
	int	rc;

	i = 0;
	rc = 0;
	while ((line[i] < 9 || line[i] > 13) && line[i] != 32 && line[i])
			i++;
	if (line[i])
	{
		rc = ft_detect_element(line, &i); 
		if (rc >= 1 && rc <= 4)
			ft_copy_texture(&line[i], data, rc);
		if (rc == 5 || rc == 6)
			ft_parse_color(&line[i], data, rc);
	}
	return (0);
}

int	ft_last_check(t_data *data)
{
	if (data->no == NULL || data->so == NULL || data->we == NULL || data->ea == NULL)
		printf("Error \n missing texture");
	if (data->no == NULL || data->so == NULL || data->we == NULL || data->ea == NULL)
		return (-1);
	if (data->ceiling == -1 || data->floor == -1)
		printf("Error \n missing color");
	if (data->ceiling == -1 || data->floor == -1)
		return (-1);
	return (0);
}

int ft_parsing(t_data *data, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		printf("Error\nUnable to open %s", file_name);
	return (-1);
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (ft_parse_line(line, data) != 0)
			return (1);
	}
	if (ft_last_check(data) == -1)
		return (-1);
	return (0);
}
