/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Meritxu <Meritxu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:14:05 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/29 23:49:48 by Meritxu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_load_images(t_data *data)
{
	int	w;
	int	h;

	w = 32;
	h = 32;
	data->img = mlx_xpm_file_to_image(data->mlx_c, \
	"assets/rock.xpm", &w, &h);
	data->img2 = mlx_xpm_file_to_image(data->mlx_c, \
	"assets/ground.xpm", &w, &h);
	data->img3 = mlx_xpm_file_to_image(data->mlx_c, \
	"assets/flag.xpm", &w, &h);
	data->img4 = mlx_xpm_file_to_image(data->mlx_c, \
	"assets/lapras_l.xpm", &w, &h);
	data->img5 = mlx_xpm_file_to_image(data->mlx_c, \
	"assets/exit.xpm", &w, &h);
}

void	ft_draw(t_data *data, int w, int h)
{
	if (data->map[data->y][data->x] == '1')
	{
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img2, w, h);
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img, w, h);
	}
	else if (data->map[data->y][data->x] == 'o')
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img2, w, h);
	else if (data->map[data->y][data->x] == 'c')
	{
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img2, w, h);
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img3, w, h);
	}
	else if (data->map[data->y][data->x] == 'p'\
	|| data->map[data->y][data->x] == 'e')
	{
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img2, w, h);
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img4, w, h);
	}
	else if (data->map[data->y][data->x] == 'E')
	{
		mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img2, w, h);
		if (data->coins == data->read_coins)
			mlx_put_image_to_window(data->mlx_c, data->mlx_w, data->img5, w, h);
	}
}

void	ft_make_map(t_data *data)
{
	int	width;
	int	height;

	data->y = 0;
	data->x = 0;
	width = 0;
	height = 0;
	while (data->y < data->y_)
	{
		data->x = 0;
		width = 0;
		while (data->x < data->x_)
		{
			if (data->map[data->y][data->x] == '0')
				data->map[data->y][data->x] = 'o';
			ft_draw(data, width, height);
			data->x++;
			width += 32;
		}
		data->y++;
		height += 32;
	}
}

int	key_hook(int keycode, t_data *data)
{
	static int	movements = 0;
	static int	tmp;

	tmp = movements;
	if (keycode == 53)
		ft_esc(data);
	else if (keycode == 126 || keycode == 13)
		movements += ft_up(data);
	else if (keycode == 123 || keycode == 0)
	{
		data->img4 = mlx_xpm_file_to_image(data->mlx_c, \
		"assets/lapras_l.xpm", &data->x, &data->y);
		movements += ft_left(data);
	}
	else if (keycode == 125 || keycode == 1)
		movements += ft_down(data);
	else if (keycode == 124 || keycode == 2)
	{
		data->img4 = mlx_xpm_file_to_image(data->mlx_c, \
		"assets/lapras_r.xpm", &data->x, &data->y);
		movements += ft_right(data);
	}
	ft_make_map(data);
	if (tmp != movements)
		ft_printf("%d movements\n", movements);
	return (0);
}
