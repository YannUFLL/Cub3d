/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <ydumaine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:38:35 by ydumaine          #+#    #+#             */
/*   Updated: 2022/07/05 13:43:50 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
int	ft_test_color(int color, t_data *data)
{
	int x; 
	int y; 

	y = 0; 
	while (y < 800)
	{
		x = 0;
		y++; 
		while (x < 800)
		{
			x++;
			mlx_pixel_put(data->mlx, data->mlx_win, x, y, color);
		}
	}	
	return (0);
}
*/

int	ft_init_data(t_data *data)
{
	data->mlx_win = NULL;
	data->mlx = NULL;
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->floor = -1;
	data->ceiling = -1;
	return (0);
}

int ft_free(t_data *data)
{
	if (data->no != NULL)
		free(data->no);
	if (data->no != NULL)
		free(data->so);
	if (data->no != NULL)
		free(data->we);
	if (data->no != NULL)
		free(data->ea);
	return (0);

}
int	main(int argc, char **argv)
	{
	(void)argc; 
	(void)argv;
	t_data data; 

	if (argc > 2)
		printf("Errror\nToo Much arguments");
	data.mlx = mlx_init(); 
	data.mlx_win = mlx_new_window(data.mlx, 1920, 1080, "LE MEILLEUR JEU AU MONDE ");
	if (ft_parsing(&data, argv[1]) == -1)
		return (ft_free(&data));
	//mlx_hook(data.win, 2, 1L << 0, ft_key_hook, &data);
	mlx_loop(data.mlx);


	}