/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:29:54 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/12 16:15:21 by ydumaine         ###   ########.fr       */
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

typedef struct ray_data
{
	double	resolution_x; 
	double	resolution_y; 
	double	camera_x;
	double	plane_x; // vecteur plan camera
	double	plane_y;
	double	dir_x; // vecteur du regard du joueur
	double	dir_y; 
	double	raydir_x; // vecteur rayon lanceé pour detecter un mur
	double	raydir_y; 
	double	pos_x;	// position du joueur 
	double	pos_y;
	int		map_x; // position du carre dans lequel est le joueur sur la carte
	int		map_y; 
	double	ray_side_x; //distance a parcourir avant la premiere intersection de la position du joueur 
	double	ray_side_y;
	double	ray_delta_x;// distance a parcourir avant une intersection 
	double	ray_delta_y;
	int		step_x; // sens du rayon ( positif ou negatif ) x
	int		step_y; // sens du rayon ( positif ou negatif ) y
	int		hit;	// indique si un mur a ete touche 
	int		side;
	double	walldistance; // distance du rayon jusqu au mur
	int		lineheight; // hauteur de la ligne de pixel 
	int		drawstart; // debut de la ligne de pixel 
	int		drawend;  // fin de la ligne de pixel 
	int		color; 
	char	 **map;
}
		t_ray;

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
	int		resolution_x;
	int		resolution_y;
	int		move_speed;
	int		rotate_speed; 
	t_ray	ray_data; 
}		t_data;

int		ft_copy_texture(char *line, t_data *data, int rc);
int		ft_parse_color(char *line, t_data *data, int rc);
int		ft_extract_color(char *line, int *i);
int		ft_parsing(t_data *data, char *file_name);
void	ft_rm_if_already_exist(int rc, t_data *data);
int		ft_parse_map(t_data *data, char *line, int fd);
int		ft_render_next_frame(t_data *data);
int		ft_key_hook(int keycode, t_data *data);

#endif