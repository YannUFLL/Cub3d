/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:21:13 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/18 17:59:18 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef enum e_type
{
	MAP = 1,
	F,
	C,
	NO,
	SO,
	WE,
	EA,
	DOOR, 
	FLOOR,
	CEILING,
}	t_type;

int	ft_detect_element(char *line, int *i)
{
	t_type rc; 

	rc = 0; 
	if (ft_strncmp(&line[*i], "NO", 2) == 0)
		rc = NO;
	if (ft_strncmp(&line[*i], "SO", 2) == 0)
		rc = SO;
	if (ft_strncmp(&line[*i], "WE", 2) == 0)
		rc = WE;
	if (ft_strncmp(&line[*i], "EA", 2) == 0)
		rc = EA;
	if (ft_strncmp(&line[*i], "F", 1) == 0)
		rc = F;
	if (ft_strncmp(&line[*i], "C", 1) == 0)
		rc = C;
	if (ft_strncmp(&line[*i], "1", 1) == 0)
		rc = MAP;
	if (ft_strncmp(&line[*i], "DO", 2) == 0)
		rc = DOOR;
	if (ft_strncmp(&line[*i], "TFL", 3) == 0)
		rc = FLOOR;
	if (ft_strncmp(&line[*i], "TCE", 3) == 0)
		rc = CEILING;
	while (line[*i] && (line[*i] < 9 || line[*i] > 13) && line[*i] != 32)
			(*i)++;
	return (rc);

}

void	ft_rm_if_already_exist(int rc, t_data *data)
{
	if (rc == 4)
	{
		if(data->texture[0].path != NULL)
			free(data->texture[0].path);
	}
	if (rc == 5)
	{
		if(data->texture[1].path != NULL)
			free(data->texture[1].path);
	}
	if (rc == 6)
	{
		if(data->texture[2].path != NULL)
			free(data->texture[2].path);
	}
	if (rc == 7)
	{
		if(data->texture[3].path != NULL)
			free(data->texture[3].path);
	}
}

int ft_parse_data(char *line, t_data *data, int *end)
{
	int i;
	int	rc;

	i = 0;
	rc = 0;
	while ((line[i] < 9 || line[i] > 13) && line[i] == 32 && line[i])
			i++;
	if (line[i])
	{
		rc = ft_detect_element(line, &i); 
		if (rc >= 4)
			ft_copy_texture(&line[i], data, rc);
		if (rc == 2 || rc == 3)
			return (ft_parse_color(&line[i], data, rc));
		if (rc == 1)
			*end = 1;
	}
	return (0);
}

int	ft_last_check(t_data *data)
{
	int	x;
	x = 0;

	while (x < 5)
	{
	if (data->texture[x].path == NULL)
		printf("Error \n missing texture");
	if (data->texture[x].path == NULL)
		return (1);
		x++;
	}
	if (data->ceiling == -1 || data->floor == -1)
		printf("Error \n missing color");
	if (data->ceiling == -1 || data->floor == -1)
		return (1);
	return (0);
}

int ft_parsing(t_data *data, char *file_name)
{
	int		fd;
	char	*line;
	int		end; 
	int		rc;

	rc = 0;
	end = 0;
	fd = open(file_name, O_RDONLY);
	if (fd == 1)
	{
		printf("Error\nUnable to open %s", file_name);
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		rc = ft_parse_data(line, data, &end);
		if (end == 1)
			break ;
		free(line);
		if (rc != 0)
			return (1);
		line = get_next_line(fd);
	}
	ft_parse_map(data, line, fd);
	if (ft_last_check(data) == 1)
		return (1);
	return (0);
}
