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
	else if (data->map[y][x] == 'o')
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img2, width, height);
	else if (data->map[y][x] == 'c')
	{
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img2, width, height);
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img3, width, height);
	}
	else if (data->map[y][x] == 'p' || data->map[y][x] == 'e')
	{
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img2, width , height);
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img4, width , height);
	}
	else if (data->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img2, width, height);
		if (data->coins == data->read_coins)
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
			if (data->map[y][x] == '0')
				data->map[y][x] = 'o';
			ft_draw(data, x, y, width, height);
			x++;
			width += 32;
		}
		y++;
		height += 32;
	}
	for (int i = 0; i < data->y_; ++i)
		printf("%s\n", data->map[i]);
}
//detecta el input del teclado, modifica la matriz y vuelve a llamar a la funcion para hacer el mapa
int	key_hook(int keycode, t_data *data)
{
	static int movements = 1;
	printf("%d movements\n", movements); //cambiar por mi printf
	if (keycode == 53)
		ft_esc(data);
	else if (keycode == 126 || keycode == 13 ) //arriba
		movements += ft_up(data);
	else if (keycode == 123 || keycode == 0) //izquierda
		movements += ft_left(data);
	else if (keycode == 125 || keycode == 1) //abajo
		movements += ft_down(data);
	else if (keycode == 124 || keycode == 2) //derecha
		movements += ft_right(data);
	ft_make_map(data, data->map);
	return (0);
}
//feature: añadir la carga de imagenes nuevas en cada if en la dirección, sobran lineas 
