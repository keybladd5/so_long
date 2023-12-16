/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:52:46 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/11 10:52:48 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>

#define MALLOC_ERROR 1
#define WIDTH 800
#define HEIGHT 800
#define SIZE_XPM 16

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx_connection;
	void	*mlx_win;
	t_data	img;
	t_data	img2;
	int x = 0;
	int y = 0;

	mlx_connection = mlx_init();//inicia la conexion con XWINDOW y hace malloc
	if(!mlx_connection)
		return (MALLOC_ERROR);
	mlx_win = mlx_new_window(mlx_connection, WIDTH, HEIGHT, "TEST");// abre la ventana y hace malloc
	if (!mlx_win)
	{
		free(mlx_connection);
		return (MALLOC_ERROR);
	}

	img.img = mlx_xpm_file_to_image(mlx_connection, "assets/tile_0000.xpm", &img.bits_per_pixel, &img.line_length);
	img2.img = mlx_xpm_file_to_image(mlx_connection, "assets/tile_0037.xpm", &img.bits_per_pixel, &img.line_length);
	while(y < 799)
	{
		x = 0;
		while(x < 799)
		{
			if ((x + y) % 32 == 0)
				mlx_put_image_to_window(mlx_connection, mlx_win, img.img, x, y);
			else
				mlx_put_image_to_window(mlx_connection, mlx_win, img2.img, x, y);
			x += 16;
		}
		y += 16;
	}

	//mlx_put_image_to_window(mlx_connection, mlx_win, img.img, , 0);
	/*img.img = mlx_new_image(mlx_connection, WIDTH, HEIGHT);

	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);



	while(y != 50)
	{
		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		x++;
		y++;
	}
	while(y != 100)
	{
		my_mlx_pixel_put(&img, x, y, 0x00AA0000);
		x++;
		y++;
	}
	while(y != 150)
	{
		my_mlx_pixel_put(&img, x, y, 0x33B1FF00);
		x++;
		y++;
	}
	while(y != 190)
	{
		my_mlx_pixel_put(&img, x, y, 0x33B1FF99);
		y++;
	}
*/

	mlx_loop(mlx_connection);// mantiene en bucle para los eventos

	mlx_destroy_window(mlx_connection, mlx_win);

	free(mlx_connection);
}
