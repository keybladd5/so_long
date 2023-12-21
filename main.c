/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:56:28 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/19 11:56:31 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx_opengl_20191021/mlx.h"
#include "inc/so_long.h"
#include "gnl/get_next_line.h"

int main(int argc, char *argv[])
{
	t_data data;
	if (argc != 2)
		return (1);
	//ft_init_data(&data);
	data.x_ = 0;
	ft_map(argv, &data);
	data.mlx_connection = mlx_init();//inicia la conexion con XWINDOW y hace malloc
	if(!data.mlx_connection)
		return (MALLOC_ERROR);
	data.mlx_win = mlx_new_window(data.mlx_connection, (data.x_ * 32), data.y_ * 32, "TEST");// abre la ventana y hace malloc
	if (!data.mlx_win)
	{
		free(data.mlx_connection);
		return (MALLOC_ERROR);
	}
	data.img = mlx_xpm_file_to_image(data.mlx_connection, "assets/limit.xpm", &data.bits_per_pixel, &data.line_length); //carga imagen 1
	data.img2 = mlx_xpm_file_to_image(data.mlx_connection, "assets/ground.xpm",&data.bits_per_pixel, &data.line_length); //carga imagen 2
	data.img3 = mlx_xpm_file_to_image(data.mlx_connection, "assets/test_coin.xpm",&data.bits_per_pixel, &data.line_length); //carga imagen 3
	data.img4 = mlx_xpm_file_to_image(data.mlx_connection, "assets/npc.xpm",&data.bits_per_pixel, &data.line_length); //carga imagen 3
	data.img5 = mlx_xpm_file_to_image(data.mlx_connection, "assets/exit.xpm",&data.bits_per_pixel, &data.line_length); //
	ft_make_map(&data, data.map);

	mlx_key_hook(data.mlx_win, key_hook, &data);
	mlx_loop(data.mlx_connection);// mantiene en bucle para los eventos

	mlx_destroy_window(data.mlx_connection, data.mlx_win);

	free(data.mlx_connection);

	return (0);
}
