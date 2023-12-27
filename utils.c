/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:15:52 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/21 18:15:53 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void ft_get_npc_yx_coins(t_data *data)
{
	int i;
	int lines;

	lines = 1;
	while (lines < data->y_)
	{
		i = 0;
		while (i < data->x_)
		{
			if (data->map[lines][i] == 'P')
			{
				data->x_npc = i;
				data->y_npc = lines;
			}
			else if(data->map[lines][i] == 'C')
				data->read_coins++;
			i++;
		}
		lines++;
	}
}
//funcion para iniciar el stack de data
void	ft_init_data(t_data *data)
{
	data->mlx_connection = NULL;
	data->mlx_win = NULL;
	data->img = NULL;
	data->img2 = NULL;
	data->img3 = NULL;
	data->img4 = NULL;
	data->img5 = NULL;
	data->map = NULL;
	data->y_npc = 0;
	data->x_npc = 0;
	data->y_ = 0;
	data->x_ = 0;
	data->coins = 0;
	data->read_coins = 0;
	data->flood_fill_check = 0;
}
//funcion para mandar por fd2 el mensaje de error y liberar memoria de pointers
void ft_error(t_data *data)
{
	int i;

	i = 0;
	if (data->mlx_win && data->mlx_connection)
		mlx_destroy_window(data->mlx_connection, data->mlx_win);
	if (data->map)
	{	
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	write(2, "Error\n", 7);
	exit(1);
}


//funcion para hacer toda la bateria de pruebas de errores
void ft_error_checker(t_data *data)
{
	if (ft_check_doubles(data) == 1)
		ft_error(data);
	if (ft_check_matrix(data) == 1)
		ft_error(data);
	ft_get_npc_yx_coins(data);
	ft_flood_fill(data);
	if (data->flood_fill_check != 1)
		ft_error(data);
}
