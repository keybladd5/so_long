/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 20:22:55 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/22 20:22:58 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"
#include "gnl/get_next_line.h"

int main(int argc, char *argv[])
{
	if (argc != 2)
		return 1;
	t_data data;

	data.x_ = 0;
	ft_map(argv, &data);
	printf("%d\n", ft_get_doubles(&data));
	ft_get_npc_yx(&data);
	ft_flood_fill(&data);
	printf("al salir del floodfill %d\n", data.flood_fill_check);
	printf("%d\n", ft_check_matrix(&data));
	for (int i = 0; i < data.y_; ++i)
		printf("%s\n", data.map[i]);
	return (0);
}
