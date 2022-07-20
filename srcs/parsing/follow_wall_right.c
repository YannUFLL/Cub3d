/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_wall_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrasser <jrasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:40:04 by jrasser           #+#    #+#             */
/*   Updated: 2022/07/20 17:45:16 by jrasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_sub_checker_chang_dir_r_e(t_map_data *d)
{
	int	a;

	a = d->is_againt_wall;
	if (a && ft_move_is_valid(d, &(d->map[d->posY + 1][d->posX])))
		d->dir = 'S';
	else if (a && ft_move_is_valid(d, &(d->map[d->posY][d->posX + 1])))
		;
	else if (a && ft_move_is_valid(d, &(d->map[d->posY - 1][d->posX])))
		d->dir = 'N';
	else if (a && ft_move_is_valid(d, &(d->map[d->posY][d->posX - 1])))
		d->dir = 'W';
	else if (a)
		d->no_move_possible = 1;
	else if (ft_move_is_valid(d, &(d->map[d->posY][d->posX + 1])))
		;
	//else if (ft_move_is_valid(d, &(d->map[d->posY + 1][d->posX])))
	//	d->dir = 'S';
	//else if (ft_move_is_valid(d, &(d->map[d->posY][d->posX - 1])))
	//	d->dir = 'W';
	//else if (ft_move_is_valid(d, &(d->map[d->posY - 1][d->posX])))
	//	d->dir = 'N';
	else
		d->no_move_possible = 1;
}

void	ft_sub_checker_chang_dir_r_s(t_map_data *d)
{
	if (ft_move_is_valid(d, &(d->map[d->posY][d->posX - 1])))
		d->dir = 'W';
	else if (ft_move_is_valid(d, &(d->map[d->posY + 1][d->posX])))
		;
	else if (ft_move_is_valid(d, &(d->map[d->posY][d->posX + 1])))
		d->dir = 'E';
	else if (ft_move_is_valid(d, &(d->map[d->posY - 1][d->posX])))
		d->dir = 'N';
	else
		d->no_move_possible = 1;
}

void	ft_sub_checker_chang_dir_r_w(t_map_data *d)
{
    if (ft_move_is_valid(d, &(d->map[d->posY - 1][d->posX])))
		d->dir = 'N';
	else if (ft_move_is_valid(d, &(d->map[d->posY][d->posX - 1])))
		;
	else if (ft_move_is_valid(d, &(d->map[d->posY + 1][d->posX])))
		d->dir = 'S';
	
	else if (ft_move_is_valid(d, &(d->map[d->posY][d->posX + 1])))
		d->dir = 'E';
	else
		d->no_move_possible = 1;
}

void	ft_sub_checker_chang_dir_r_n(t_map_data *d)
{
	if (ft_move_is_valid(d, &(d->map[d->posY][d->posX + 1])))
		d->dir = 'E';
	else if (ft_move_is_valid(d, &(d->map[d->posY - 1][d->posX])))
		;
	else if (ft_move_is_valid(d, &(d->map[d->posY][d->posX - 1])))
		d->dir = 'W';
	else if (ft_move_is_valid(d, &(d->map[d->posY + 1][d->posX])))
		d->dir = 'S';
	else
		d->no_move_possible = 1;
}

int	ft_follow_wall_right(t_map_data *d)
{
	int	i;

	i = 0;
    if (ft_is_againt_wall(d))
		ft_set_dir_against_wall(d, 1);
	while (i == 0 || d->nb_pass != 3)
	{
		if (d->dir == 'E' || d->dir == 'S' || d->dir == 'W' || d->dir == 'N')
			if (ft_check_out(d))
				return (1);
		if (d->dir == 'E')
			ft_sub_checker_chang_dir_r_e(d);
		else if (d->dir == 'S')
			ft_sub_checker_chang_dir_r_s(d);
		else if (d->dir == 'W')
			ft_sub_checker_chang_dir_r_w(d);
		else if (d->dir == 'N')
			ft_sub_checker_chang_dir_r_n(d);
		if (d->no_move_possible)
			return (0);
		ft_move(d, 1);
		if (d->posX == d->x_start && d->posY == d->y_start)
			d->nb_pass += 1;
		i++;
	}
	return (0);
}
