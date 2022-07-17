/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:29:54 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/17 18:26:58 by ydumaine         ###   ########.fr       */
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


typedef struct texture 
{
	char	*path;
	void	*mlx_img; 
	int		*addr; 
	int	img_width;	
	int	img_height; 
	int	lenght; 
	int	bit_per_pixel; 
	int	endian; 
}		t_texture;

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
	double	rotate_left; 
	double	rotate_right; 
	int		texx;
	int		texy;
	int		text_select;
	int		door_open;
	int		pos_door_x; 
	int		pos_door_y;
	char	 **map;
	double	wall_x; 
	double	step;
	double	texpos; 
}
		t_ray;

typedef	struct key
{
	int	move_forward;
	int	move_back;
	int	move_left;
	int	move_right;
	int	rotate_left;
	int	rotate_right;
	int	use; 
}
	t_key;

typedef struct data
{
	void	*mlx_win;
	void	*mlx;
	t_texture	texture[5];
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
	double	move_speed;
	double	rotate_speed;
	t_ray	ray_data; 
	t_key	key;
	int		keycode;
	int		textures_nb;
}		t_data;

int		ft_copy_texture(char *line, t_data *data, int rc);
int		ft_parse_color(char *line, t_data *data, int rc);
int		ft_extract_color(char *line, int *i);
int		ft_parsing(t_data *data, char *file_name);
void	ft_rm_if_already_exist(int rc, t_data *data);
int		ft_parse_map(t_data *data, char *line, int fd);
int		ft_render_next_frame(t_data *data);
int		ft_key_press(int keycode, t_data *data);
int		ft_key_release(int keycode, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif