/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 12:07:40 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/23 12:07:43 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int ft_esc(t_data *data)
{
	int i;

	i = 0;
	mlx_destroy_window(data->mlx_connection, data->mlx_win);
	free(data->mlx_connection);
	while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
	free(data->map);
	exit (0);
}
//FUNCIONA!!!!!!!!!!!!!!! TOMAR COMO REFERENCIA PARA EL CAMBIO CON LAS OTRAS
int	ft_up(t_data *data)
{
	if (data->map[data->y_npc - 1][data->x_npc] == 'c') //la siguiente
	{
		data->coins++;
		if (data->map[data->y_npc][data->x_npc] == 'p') //actual
			data->map[data->y_npc][data->x_npc] = 'o';
	}
	else if (data->map[data->y_npc - 1][data->x_npc] == 'E')
	{
		if (data->read_coins == data->coins)
			ft_esc(data);
		data->map[data->y_npc][data->x_npc] = 'o';
		data->map[--data->y_npc][data->x_npc] = 'e';
		return (0);
	}
	else if (data->map[data->y_npc - 1][data->x_npc] == 'e')
		data->map[data->y_npc][data->x_npc] = 'E';
	else if (data->map[data->y_npc - 1][data->x_npc] != 'o')
		return (0);
	if (data->map[data->y_npc][data->x_npc] == 'e')
		data->map[data->y_npc][data->x_npc] = 'E';
	else
		data->map[data->y_npc][data->x_npc] = 'o';
	data->y_npc -= 1; 
	data->map[data->y_npc][data->x_npc] = 'p';
	return (1);
}

int	ft_left(t_data *data)
{
	if (data->map[data->y_npc][data->x_npc - 1] == 'c')
		data->coins++;
	else if (data->map[data->y_npc][data->x_npc - 1] == 'E')
	{	
		if (data->read_coins == data->coins)
			ft_esc(data);
		return (0);
	}
	else if (data->map[data->y_npc][data->x_npc - 1] != 'o')
		return (0);
	data->map[data->y_npc][data->x_npc] = 'o';
	data->x_npc -= 1; 
	data->map[data->y_npc][data->x_npc] = 'p';
	return (1);
}
int	ft_down(t_data *data)
{
	if (data->map[data->y_npc + 1][data->x_npc] == 'c')
			data->coins++;
	else if (data->map[data->y_npc + 1][data->x_npc] == 'E')
	{	
		if (data->read_coins == data->coins)
			ft_esc(data);
		return (0);
	}
	else if (data->map[data->y_npc + 1][data->x_npc] != 'o')
		return (0);
	data->map[data->y_npc][data->x_npc] = 'o';
	data->y_npc += 1; 
	data->map[data->y_npc][data->x_npc] = 'p';
	return (1);
}

int	ft_right(t_data *data)
{
	if (data->map[data->y_npc][data->x_npc + 1] == 'c')
		data->coins++;
	else if (data->map[data->y_npc][data->x_npc + 1] == 'E')
	{
		if (data->read_coins == data->coins)
			ft_esc(data);
		return (0);
	}
	else if (data->map[data->y_npc][data->x_npc + 1] != 'o')
		return (0);
	data->map[data->y_npc][data->x_npc] = 'o';
	data->x_npc += 1;  
	data->map[data->y_npc][data->x_npc] = 'p';
	return (1);
}
