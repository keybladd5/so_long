/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:48:40 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/19 11:48:43 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"
#include "gnl/get_next_line.h"

//Obtiene el tamaño de la matriz leida en el .ber
void ft_get_size_map(int fd, t_data *data)
{
	char *line;

	line = get_next_line(fd);
	if (!line)
		return ; //pendiente proteger
	data->y_ = 1;
	while (line[data->x_])
		data->x_++;
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			return ;
		data->y_++;
	}
}
//Hace la matriz accediendo al tamaño
char** ft_make_area(t_data *data, int fd)
{
	int i;

	i = 0;
	data->map = malloc(sizeof(char*) * data->y_ + 1);
	if(!data->map)
		return (NULL);
	while(data->y_ - i)
	{
		data->map[i] = get_next_line(fd);
		if(!data->map[i])
			return NULL ;
		i++;
	}
	data->map[i] = NULL;
	return (data->map);
}
//hace la matriz para la ventana
void	ft_map(char *argv[], t_data *data)
{
	int	fd;
	int h;

	h = 0;
	fd = 0;
	/*if (ft_check_ext(argv) == 0)
	{
		printf("ERROR");
		return ; //pending put error ft!!
	}*/
	fd = open(argv[1], O_RDONLY);
	ft_get_size_map(fd, data);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	data->map = ft_make_area(data, fd);
	close(fd);
	
}
