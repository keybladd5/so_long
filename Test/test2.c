/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:55:32 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/14 11:55:34 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ERROR 1

typedef struct	s_img {
	void	*img;
	int		bits_per_pixel;
	int		line_length;
}				t_img;

typedef struct	s_data {
	void	*mlx_connection;
	void	*mlx_win;
	int 	y_;
	int		x_;
	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	char 	**map_tru;
	int 	coins;
}				t_data;

typedef struct	s_point {
	int y_;
	int x_;
}				t_point;

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y_);
	for (int i = 0; i < size.y_; ++i)
	{
		new[i] = malloc(size.x_ + 1);
		for (int j = 0; j < size.x_; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x_] = '\0';
	}
	return new;
}

void ft_make_map(t_data *data, char** map)
{
	int y;
	int x;
	int width = 0;
	int height = 0;

	y = 0;
	x = 0;
	while(y < 8)
	{
		x = 0;
		width = 0;
		while(x < 16)
		{
			if (map[y][x] == '1')
				mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img, width, height);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img2, width, height);
			else if (map[y][x] == 'C')
			{
				mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img2, width, height);
				mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img3, width, height);
			}
			else if (map[y][x] == 'P')
			{
				mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img2, width, height);
				mlx_put_image_to_window(data->mlx_connection, data->mlx_win, data->img4, width, height);
				data->y_ = y;
				data->x_ = x;
			}
			x++;
			width += 16;
		}
		y++;
		height += 16;
	}
}

int	key_hook(int keycode, t_data *data, t_point *curr)
{
	static int movements = 1;
	printf("%d movements\n", movements);

	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx_connection, data->mlx_win);
		free(data->mlx_connection);
		exit (0);
	}
	else if (keycode == 126) //arriba
	{	
		if (data->map_tru[data->y_ - 1][data->x_] == 'C')
		{	
			data->coins++;
			movements++;
			data->map_tru[data->y_][data->x_] = '0';
			data->y_ -= 1; 
			data->map_tru[data->y_][data->x_] = 'P';
			ft_make_map(data, data->map_tru);
		}
		else if (data->map_tru[data->y_ - 1][data->x_] != '0')
			return (0);
		else
		{
			movements++;
			data->map_tru[data->y_][data->x_] = '0';
			data->y_ -= 1; 
			data->map_tru[data->y_][data->x_] = 'P';
			ft_make_map(data, data->map_tru);
		}
	}
	else if (keycode == 123) //izquierda
	{
		if (data->map_tru[data->y_][data->x_ - 1] == 'C')
		{
			movements++;
			data->map_tru[data->y_][data->x_] = '0';
			data->x_ -= 1; 
			data->map_tru[data->y_][data->x_] = 'P';
			ft_make_map(data, data->map_tru);
		}
		else if (data->map_tru[data->y_][data->x_ - 1] != '0')
			return (0);
		else
		{
			movements++;
			data->map_tru[data->y_][data->x_] = '0';
			data->x_ -= 1; 
			data->map_tru[data->y_][data->x_] = 'P';
			ft_make_map(data, data->map_tru);
		}
	}
	else if (keycode == 125) //abajo
	{
		if (data->map_tru[data->y_ + 1][data->x_] == 'C')
		{
			movements++;
			data->coins++;
			data->map_tru[data->y_][data->x_] = '0';
			data->y_ += 1; 
			data->map_tru[data->y_][data->x_] = 'P';
			ft_make_map(data, data->map_tru);
		}
		else if (data->map_tru[data->y_ + 1][data->x_] != '0')
			return (0);
		else
		{
			movements++;
			data->map_tru[data->y_][data->x_] = '0';
			data->y_ += 1; 
			data->map_tru[data->y_][data->x_] = 'P';
			ft_make_map(data, data->map_tru);
		}
	}
	else if (keycode == 124) //derecha
	{
		if (data->map_tru[data->y_][data->x_ + 1] == 'C')
		{
			movements++;
			data->map_tru[data->y_][data->x_] = '0';
			data->x_ += 1;  
			data->map_tru[data->y_][data->x_] = 'P';
			ft_make_map(data, data->map_tru);
		}
		else if (data->map_tru[data->y_][data->x_ + 1] != '0')
			return (0);
		else
		{
			movements++;
			data->map_tru[data->y_][data->x_] = '0';
			data->x_ += 1;  
			data->map_tru[data->y_][data->x_] = 'P';
			ft_make_map(data, data->map_tru);
		}
	}
	return (0);
}
int	main(void)
{
	t_data	data;
	t_data	*data2;
	int		bits_per_pixel;
	int		line_length;
	int x = 0;
	int y = 0;
	t_point size;
	char *map[] = {
        "111111111111111",
        "1000000C000C001",
        "1000000P0000001",
        "1000000C0000001",
        "10000C000000001",
        "1000000000C0001",
        "10000C000000001",
        "111111111111111",
    };

	size.y_ = 8;
	size.x_ = 16;

	data.mlx_connection = mlx_init();//inicia la conexion con XWINDOW y hace malloc
	if(!data.mlx_connection)
		return (MALLOC_ERROR);
	data.mlx_win = mlx_new_window(data.mlx_connection, (15 * 16), 8 * 16, "TEST");// abre la ventana y hace malloc
	if (!data.mlx_win)
	{
		free(data.mlx_connection);
		return (MALLOC_ERROR);
	}

	data.img = mlx_xpm_file_to_image(data.mlx_connection, "assets/tile_0000.xpm", &bits_per_pixel, &line_length); //carga imagen 1
	data.img2 = mlx_xpm_file_to_image(data.mlx_connection, "assets/tile_0037.xpm", &bits_per_pixel, &line_length); //carga imagen 2
	data.img3 = mlx_xpm_file_to_image(data.mlx_connection, "assets/tile_0053.xpm", &bits_per_pixel, &line_length); //carga imagen 3
	data.img4 = mlx_xpm_file_to_image(data.mlx_connection, "assets/tile_0121.xpm", &bits_per_pixel, &line_length); //carga imagen 3
	data.map_tru = make_area(map, size);
	ft_make_map(&data, data.map_tru);

	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop(data.mlx_connection);// mantiene en bucle para los eventos

	mlx_destroy_window(data.mlx_connection, data.mlx_win);

	free(data.mlx_connection);
}
