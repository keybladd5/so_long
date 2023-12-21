/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:14:05 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/21 18:14:08 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"
#include "gnl/get_next_line.h"

void	ft_draw(t_data *data, int x, int y, int width, int height)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img, width, height);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img2, width, height);
	else if (data->map[y][x] == 'C')
	{
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img2, width, height);
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img3, width, height);
	}
	else if (data->map[y][x] == 'P')
	{
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img2, width , height);
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img4, width , height);
		data->x_npc = x;
		data->y_npc = y;
	}
	else if (data->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img2, width, height);
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img5, width, height);
	}
}
void ft_make_map(t_data *data, char** map)
{
	int y;
	int x;
	int width = 0;
	int height = 0;

	y = 0;
	x = 0;
	while(y < data->y_)
	{
		x = 0;
		width = 0;
		while(x < data->x_)
		{
			ft_draw(data, x, y, width, height);
			x++;
			width += 32;
		}
		y++;
		height += 32;
	}
}
//detecta el input del teclado, modifica la matriz y vuelve a llamar a la funcion para hacer el mapa
int	key_hook(int keycode, t_data *data)
{
	static int movements = 1;
	printf("%d movements\n", movements); //cambiar por mi printf

	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_connection, data->mlx_win);
		free(data->mlx_connection);
		exit (0);
	}
	else if (keycode == 126) //arriba
	{	
		if (data->map[data->y_npc - 1][data->x_npc] == 'C')
			data->coins++;
		else if (data->map[data->y_npc - 1][data->x_npc] == 'E')
		{
			mlx_destroy_window(data->mlx_connection, data->mlx_win);
			free(data->mlx_connection);
			exit (0);
		}
		else if (data->map[data->y_npc - 1][data->x_npc] != '0')
			return (0);
		movements++;
		data->map[data->y_npc][data->x_npc] = '0';
		data->y_npc -= 1; 
		data->map[data->y_npc][data->x_npc] = 'P';
		ft_make_map(data, data->map);
	}
	else if (keycode == 123) //izquierda
	{
		if (data->map[data->y_npc][data->x_npc - 1] == 'C')
			data->coins++;
		else if (data->map[data->y_npc][data->x_npc - 1] == 'E')
		{	
			mlx_destroy_window(data->mlx_connection, data->mlx_win);
			free(data->mlx_connection);
			exit (0);
		}
		else if (data->map[data->y_npc][data->x_npc - 1] != '0')
			return (0);
		movements++;
		data->map[data->y_npc][data->x_npc] = '0';
		data->x_npc -= 1; 
		data->map[data->y_npc][data->x_npc] = 'P';
		ft_make_map(data, data->map);
	}
	else if (keycode == 125) //abajo
	{
		if (data->map[data->y_npc + 1][data->x_npc] == 'C')
			data->coins++;
		else if (data->map[data->y_npc + 1][data->x_npc] == 'E')
		{	
			mlx_destroy_window(data->mlx_connection, data->mlx_win);
			free(data->mlx_connection);
			exit (0);
		}
		else if (data->map[data->y_npc + 1][data->x_npc] != '0')
			return (0);
		movements++;
		data->map[data->y_npc][data->x_npc] = '0';
		data->y_npc += 1; 
		data->map[data->y_npc][data->x_npc] = 'P';
		ft_make_map(data, data->map);
	}
	else if (keycode == 124) //derecha
	{
		if (data->map[data->y_npc][data->x_npc + 1] == 'C')
			data->coins++;
		else if (data->map[data->y_npc][data->x_npc + 1] == 'E')
		{
			mlx_destroy_window(data->mlx_connection, data->mlx_win);
			free(data->mlx_connection);
			exit (0);
		}
		else if (data->map[data->y_npc][data->x_npc + 1] != '0')
			return (0);
		movements++;
		data->map[data->y_npc][data->x_npc] = '0';
		data->x_npc += 1;  
		data->map[data->y_npc][data->x_npc] = 'P';
		ft_make_map(data, data->map);
	}
	return (0);
}
