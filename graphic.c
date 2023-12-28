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

void	ft_load_images(t_data *data)
{
	int	w;
	int	h;

	w = 32;
	h = 32;
	data->img = mlx_xpm_file_to_image(data->mlx_c, \
		"assets/limit.xpm", &w, &h);
	data->img2 = mlx_xpm_file_to_image(data->mlx_c, \
	"assets/ground.xpm", &w, &h);
	data->img3 = mlx_xpm_file_to_image(data->mlx_c, \
	"assets/test_coin.xpm", &w, &h);
	data->img4 = mlx_xpm_file_to_image(data->mlx_c, \
	"assets/npc.xpm", &w, &h);
	data->img5 = mlx_xpm_file_to_image(data->mlx_c, \
	"assets/exit.xpm", &w, &h);
}

void	ft_draw(t_data *data, int x, int y, int w, int h)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img, w, h);
	else if (data->map[y][x] == 'o')
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img2, w, h);
	else if (data->map[y][x] == 'c')
	{
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img2, w, h);
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img3, w, h);
	}
	else if (data->map[y][x] == 'p' || data->map[y][x] == 'e')
	{
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img2, w, h);
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img4, w, h);
	}
	else if (data->map[y][x] == 'E')
	{
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img2, w, h);
		if (data->coins == data->read_coins)
			mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img5, w, h);
	}
}

void	ft_make_map(t_data *data)
{
	int	y;
	int	x;
	int	width;
	int	height;

	y = 0;
	x = 0;
	width = 0;
	height = 0;
	while (y < data->y_)
	{
		x = 0;
		width = 0;
		while (x < data->x_)
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
}

int	key_hook(int keycode, t_data *data)
{
	static int	movements = 1;

	ft_printf("%d movements\n", movements);
	if (keycode == 53)
		ft_esc(data);
	else if (keycode == 126 || keycode == 13)
		movements += ft_up(data);
	else if (keycode == 123 || keycode == 0)
		movements += ft_left(data);
	else if (keycode == 125 || keycode == 1)
		movements += ft_down(data);
	else if (keycode == 124 || keycode == 2)
		movements += ft_right(data);
	ft_make_map(data);
	return (0);
}
