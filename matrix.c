/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:48:40 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/19 11:48:43 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

//Obtiene el tamaño de la matriz leida en el .ber
void ft_get_size_matrix(int fd, t_data *data)
{
	char *line;

	line = get_next_line(fd);
	if (!line)
		ft_error(data); //pendiente proteger
	data->y_ = 1;
	while (line[data->x_])
		data->x_++;
	while(line)
	{
		free(line);
		line = get_next_line(fd);
		if (!line)
			return ; // aqui q hago? la forma de detectar el error es la misma que ya se usa para salir del bucle!! ❗️
		data->y_++;
	}
}
//Hace la matriz accediendo al tamaño
void	ft_make_matrix(t_data *data, int fd)
{
	int i;

	i = 0;
	data->map = malloc(sizeof(char*) * data->y_ + 1);
	if(!data->map)
		ft_error(data);
	while(data->y_ - i)
	{
		data->map[i] = get_next_line(fd);
		if(!data->map[i])
			ft_error(data);
		i++;
	}
	data->map[i] = NULL;
}
//hace la matriz para la ventana
void	ft_matrix(char *argv[], t_data *data)
{
	int	fd;
	int h;

	h = 0;
	fd = 0;
	if (ft_check_ext(argv) == 1)
		ft_error(data);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error(data);
	ft_get_size_matrix(fd, data);
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error(data);
	ft_make_matrix(data, fd);
	close(fd);
	
}
