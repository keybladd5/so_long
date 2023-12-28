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

#include "inc/so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		exit (1);
	ft_init_data(&data);
	ft_matrix(argv, &data);
	ft_error_checker(&data);
	data.mlx_c = mlx_init();
	if (!data.mlx_c)
		exit (1);
	data.mlx_w = mlx_new_window(data.mlx_c, \
	(data.x_ * 32), data.y_ * 32, "So_long");
	if (!data.mlx_w)
	{
		free(data.mlx_c);
		exit (1);
	}
	ft_load_images(&data);
	ft_make_map(&data);
	mlx_key_hook(data.mlx_w, key_hook, &data);
	mlx_hook(data.mlx_w, 17, 0, &ft_esc, &data);
	mlx_loop(data.mlx_c);
	return (0);
}
