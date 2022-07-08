/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:29:54 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/07 14:57:17 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"
/*
typedef struct r_caster
{
	int	pos[2];
}
*/

typedef struct data
{
	void	*mlx_win;
	void	*mlx;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		floor;
	int		ceiling;
	char	**map;
	void	*display;
	char	*display_add; 
	int		bits_per_pixel; 
	int		line_length;
	int		endian;
	char	player_spawn_dir;
	int		player_spawn_pos[2];
	int		edge_size; 
	int		fov; 
			
}		t_data;

int		ft_copy_texture(char *line, t_data *data, int rc);
int		ft_parse_color(char *line, t_data *data, int rc);
int		ft_extract_color(char *line, int *i);
int		ft_parsing(t_data *data, char *file_name);
void	ft_rm_if_already_exist(int rc, t_data *data);
int		ft_parse_map(t_data *data, char *line, int fd);

#endif