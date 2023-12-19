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
#include "gnl/get_next_line.h"

int main(int argc, char *argv[])
{
	t_data data;
	if (argc != 2)
		return (1);
	//ft_init_data(&data);
	data.x_ = 0;
	ft_map(argv, &data);
	return (0);
}
