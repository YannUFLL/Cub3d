/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 21:55:08 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/17 23:17:41 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int	keycode, t_data *data)
{
	t_key *key;

	key = &data->key; 
	(void)keycode;
	if (keycode == 0)
	key->move_left = 1;
	if (keycode == 2)
	key->move_right = 1;
	if (keycode == 13)
	key->move_forward = 1;
	if (keycode == 1)
	key->move_back = 1;
	if (keycode == 123)
	key->rotate_left = 1;
	if (keycode == 124)
	key->rotate_right = 1;
	if (keycode == 3)
		key->use = 1;
	if (keycode == 53)
		exit(0);
	data->keycode = keycode;
	return(0);
}

int	ft_key_release(int	keycode, t_data *data)
{
	t_key *key;

	key = &data->key;
	(void)keycode;
	if (keycode == 0)
		key->move_left = 0;
	if (keycode == 2)
		key->move_right = 0;
	if (keycode == 13)
		key->move_forward = 0;
	if (keycode == 1)
		key->move_back = 0;
	if (keycode == 123)
		key->rotate_left = 0;
	if (keycode == 124)
		key->rotate_right = 0;
	if (keycode == 3)
		key->use = 0;
	return(0);
}

int	ft_mouse(int x, int y, t_data *data)
{
	static int old_x; 
	static int first;

	if (first == 0)
	{
		old_x = x; 
		first = 1;
	}
	(void)y;
	//mlx_mouse_hide();
	if (old_x - x < 0)
		data->key.mouse_rotate_left =  abs(x - old_x); 
	if (old_x - x > 0)
		data->key.mouse_rotate_right =  abs(x - old_x); 
	old_x = x; 
	return (0);
}