/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:21:13 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/12 16:32:11 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef enum e_type
{
	NO = 1,
	SO,
	WE,
	EA,
	F,
	C,
	S,
	MAP, 
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
	if (ft_strncmp(&line[*i], "S", 1) == 0 && line[*i + 1] != 'O')
		rc = S;
	if (ft_strncmp(&line[*i], "1", 1) == 0)
		rc = MAP;
	while (line[*i] && (line[*i] < 9 || line[*i] > 13) && line[*i] != 32)
			(*i)++;
	return (rc);

}

void	ft_rm_if_already_exist(int rc, t_data *data)
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
		printf("valeur de rc :%d\n",rc);
		if (rc >= 1 && rc <= 4)
			ft_copy_texture(&line[i], data, rc);
		if (rc == 5 || rc == 6)
			return (ft_parse_color(&line[i], data, rc));
		if (rc == 8)
			*end = 1;
	}
	return (0);
}

int	ft_last_check(t_data *data)
{
	if (data->no == NULL || data->so == NULL || data->we == NULL || data->ea == NULL)
		printf("Error \n missing texture");
	if (data->no == NULL || data->so == NULL || data->we == NULL || data->ea == NULL)
		return (1);
	if (data->ceiling == -1 || data->floor == -1)
		printf("Error \n missing color");
	if (data->ceiling == -1 || data->floor == -1)
		return (1);
	return (0);
}

void	ft_printdata(t_data *data)
{
	int	i;

	i = 0;
	printf("           DATA             \n\n");
	if (data->no != NULL)
	printf("no : %s \n", data->no);
	if (data->no != NULL)
	printf("so : %s \n", data->so);
	if (data->we != NULL)
	printf("we : %s \n", data->we);
	if (data->ea != NULL)
	printf("ea : %s \n", data->ea);
	printf("floor : %d \n", data->floor);
	printf("ceiling : %d \n", data->ceiling);
	printf("direction spawn player : %d \n", data->player_spawn_dir);
	printf("pos x player : %d \n", data->player_spawn_pos[0]); 
	printf("pos y player : %d \n", data->player_spawn_pos[1]); 
	printf("\n\n          MAP           \n");
	while (data->map && data->map[i])
	{
		printf("%s\n", (data->map[i]));
		i++;
	}
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
	ft_printdata(data);
	if (ft_last_check(data) == 1)
		return (1);
	return (0);
}
