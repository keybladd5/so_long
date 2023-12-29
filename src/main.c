/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Meritxu <Meritxu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:56:28 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/29 23:43:23 by Meritxu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	ft_instructions(void)
{
	ft_printf("\n  🃏Hellow! Welcome to the So_long project by @polmarti🃏\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("			Press W or ↑ to go UP!\n");
	ft_printf("			Press S or ↓ to go DOWN!\n");
	ft_printf("			Press A or ← to go LEFT!\n");
	ft_printf("			Press D or → to go RIGHT!\n");
	ft_printf("------------------------------------------------------------\n");
	ft_printf("	 Collect all the flags to WIN the game!\n");
	ft_printf("\n			Good LUCK 🏖\n\n");
	ft_printf("↓MOVEMENTS↓\n");
}

void	ft_endgame(void)
{
	ft_printf("			🏖 YOU WIN 🏖\n");
}

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
	ft_instructions();
	mlx_key_hook(data.mlx_w, key_hook, &data);
	mlx_hook(data.mlx_w, 17, 0, &ft_esc, &data);
	mlx_loop(data.mlx_c);
	return (0);
}
