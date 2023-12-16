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
#include "minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ERROR 1
#define WIDTH 800
#define HEIGHT 800
#define SIZE_XPM 16

typedef struct	s_img {
	void	*img;
	int		bits_per_pixel;
	int		line_length;
}				t_img;

typedef struct	s_data {
	void	*mlx_connection;
	void	*mlx_win;
}				t_data;


void ft_make_map(t_data data, t_img img, t_img img2, t_img img3, char** map)
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
				mlx_put_image_to_window(data.mlx_connection, data.mlx_win, img.img, width, height);
			else if (map[y][x] == '0')
				mlx_put_image_to_window(data.mlx_connection, data.mlx_win, img2.img, width, height);
			else if (map[y][x] == 'P')
				mlx_put_image_to_window(data.mlx_connection, data.mlx_win, img3.img, width, height);
			x++;
			width += 16;
		}
		y++;
		height += 16;
	}
}

int	main(void)
{
	t_data	data;
	t_img	img;
	t_img	img2;
	t_img	img3;
	int x = 0;
	int y = 0;
	char *map[] = {
        "111111111111111",
        "100000000000001",
        "1000000P0000001",
        "100000000000001",
        "100000000000001",
        "100000000000001",
        "100000000000001",
        "111111111111111",
    };
	char **map_true;

	data.mlx_connection = mlx_init();//inicia la conexion con XWINDOW y hace malloc
	if(!data.mlx_connection)
		return (MALLOC_ERROR);
	data.mlx_win = mlx_new_window(data.mlx_connection, (15 * 16), 8 * 16, "TEST");// abre la ventana y hace malloc
	if (!data.mlx_win)
	{
		free(data.mlx_connection);
		return (MALLOC_ERROR);
	}

	img.img = mlx_xpm_file_to_image(data.mlx_connection, "assets/tile_0000.xpm", &img.bits_per_pixel, &img.line_length); //carga imagen 1
	img2.img = mlx_xpm_file_to_image(data.mlx_connection, "assets/tile_0037.xpm", &img.bits_per_pixel, &img.line_length); //carga imagen 2
	img3.img = mlx_xpm_file_to_image(data.mlx_connection, "assets/tile_0053.xpm", &img.bits_per_pixel, &img.line_length); //carga imagen 3
	ft_make_map(data, img, img2, img3, map);

	mlx_key_hook(data.mlx_connection, )
	mlx_loop(data.mlx_connection);// mantiene en bucle para los eventos

	mlx_destroy_window(data.mlx_connection, data.mlx_win);

	free(data.mlx_connection);
}
