/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:15:52 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/21 18:15:53 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"
#include "gnl/get_next_line.h"

//Checkea que la extension sea ber y nada mas
int ft_check_ext(char *argv[])
{
	int i;
	int size;

	i = 0;
	size = 0;
	while(argv[1][size])
		size++;
	while(size - i != 3)
		i++;
	if (argv[1][i] == 'b' && argv[1][i + 1] == 'e' && argv[1][i + 2] == 'r' \
		&& argv[1][i +3] == '\0')
		return(1);
	return (0);
}
int ft_get_doubles(t_data *data)
{
	int i;
	int lines;
	int e;
	int p;

	e = 0;
	p = 0;
	lines = 1;
	while (lines < data->y_)
	{
		i = 0;
		while (i < data->x_)
		{
			if (data->map[lines][i] == 'E')
				e++;
			else if (data->map[lines][i] == 'P')
				p++;
			i++;
		}
		lines++;
	}
	if (e > 1 || p > 1)
		return (1);
	return (0);
}
void ft_get_npc_yx(t_data *data)
{
	int i;
	int lines;

	lines = 1;
	while (lines < data->y_)
	{
		i = 0;
		while (i < data->x_)
		{
			if (data->map[lines][i] == 'P')
			{
				data->x_npc = i;
				data->y_npc = lines;
				return ;
			}
			i++;
		}
		lines++;
	}
}
int	ft_check_matrix(t_data *data)
{
	int i;
	int line;

	i = 0;
	line = 0;
	while (i < data->x_)
	{
		if (data->map[line][i] != '1')
			return 1;
		i++; 
	}
	while (line < data->y_)
	{
		if (data->map[line][0] != '1' && data->map[line][i] )
			return 2;
		line++; 
	}
	i = 0;
	line--;
	while (i < data->x_)
	{
		if (data->map[line][i] != '1')
			return 3;
		i++; 
	}
	return (0);
}


//TODO: Check if the way is aviable
void	ft_fill(t_data *data, int x, int y, int x_npc, int y_npc)
{
	if (y_npc < 0 || y_npc >= y || x_npc < 0 || x_npc >= x \
		|| data->map[y_npc][x_npc] != '0' && data->map[y_npc][x_npc] != 'C' && data->map[y_npc][x_npc] != 'P' \
		&& data->map[y_npc][x_npc] != 'E')	
			return ;
	else if (data->map[y_npc][x_npc] == 'E')
	{
		data->flood_fill_check = 1;
		printf("despues del check del floodfill %d\n", data->flood_fill_check);
	}
	if (data->map[y_npc][x_npc] == '0')
		data->map[y_npc][x_npc] = 'o';
	else if (data->map[y_npc][x_npc] == 'C')
		data->map[y_npc][x_npc] = 'c';
	else if (data->map[y_npc][x_npc] == 'P')
		data->map[y_npc][x_npc] = 'p';
	ft_fill(data, x, y, x_npc - 1, y_npc);
	ft_fill(data, x, y, x_npc + 1, y_npc);
	ft_fill(data, x, y, x_npc, y_npc - 1);
	ft_fill(data, x, y, x_npc, y_npc + 1);
}

void	ft_flood_fill(t_data *data)
{
	int size_x;
	int size_y;
	int npc_begin_x;
	int npc_begin_y;

	size_x = data->x_;
	size_y = data->y_;
	npc_begin_x = data->x_npc;
	npc_begin_y = data->y_npc;
	ft_fill(data, size_x, size_y, npc_begin_x, npc_begin_y);
}
