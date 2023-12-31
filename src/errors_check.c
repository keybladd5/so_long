/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 17:43:52 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/27 17:43:55 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_check_ext(char *argv[])
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (argv[1][size])
		size++;
	while (size - i != 3)
		i++;
	if (argv[1][i] == 'b' && argv[1][i + 1] == 'e' && argv[1][i + 2] == 'r'\
		&& argv[1][i +3] == '\0')
		return (0);
	return (1);
}

int	ft_check_doubles(t_data *data)
{
	int	i;
	int	lines;
	int	e;
	int	p;

	e = 0;
	p = 0;
	lines = 1;
	while (lines < data->y_)
	{
		i = -1;
		while (++i < data->x_)
		{
			if (data->map[lines][i] == 'E')
				e++;
			else if (data->map[lines][i] == 'P')
				p++;
			else if (!ft_strchr("EPC01", data->map[lines][i]))
				return (1);
		}
		lines++;
	}
	if (e > 1 || p > 1)
		return (1);
	return (0);
}

int	ft_check_matrix(t_data *data)
{
	int	i;
	int	line;

	i = -1;
	line = 0;
	while (++i < data->x_)
	{
		if (data->map[line][i] != '1')
			return (1);
	}
	while (line < data->y_)
	{
		if (data->map[line][0] != '1' && data->map[line][i])
			return (1);
		line++;
	}
	i = -1;
	line--;
	while (++i < data->x_)
	{
		if (data->map[line][i] != '1')
			return (1);
	}
	return (0);
}

void	ft_fill(t_data *data, int x_npc, int y_npc)
{
	if ((y_npc < 0 || y_npc >= data->y || x_npc < 0 || x_npc >= data->x \
	|| data->map[y_npc][x_npc] != '0') \
	&& (data->map[y_npc][x_npc] != 'C' && data->map[y_npc][x_npc] != 'P'\
	&& data->map[y_npc][x_npc] != 'E'))
		return ;
	if (data->map[y_npc][x_npc] == '0')
		data->map[y_npc][x_npc] = 'o';
	else if (data->map[y_npc][x_npc] == 'C')
	{
		data->map[y_npc][x_npc] = 'c';
		if (data->read_coins > data->read_coins_flood)
			data->read_coins_flood++;
	}
	else if (data->map[y_npc][x_npc] == 'P')
		data->map[y_npc][x_npc] = 'p';
	else if (data->map[y_npc][x_npc] == 'E')
		data->flood_fill_check = 1;
	ft_fill(data, x_npc - 1, y_npc);
	ft_fill(data, x_npc + 1, y_npc);
	ft_fill(data, x_npc, y_npc - 1);
	ft_fill(data, x_npc, y_npc + 1);
}

void	ft_flood_fill(t_data *data)
{
	int	npc_begin_x;
	int	npc_begin_y;

	data->x = data->x_;
	data->y = data->y_;
	npc_begin_x = data->x_npc;
	npc_begin_y = data->y_npc;
	ft_fill(data, npc_begin_x, npc_begin_y);
	if (data->read_coins != data->read_coins_flood)
		ft_error(data);
}
