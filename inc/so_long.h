/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:57:17 by polmarti          #+#    #+#             */
/*   Updated: 2023/12/14 11:57:18 by polmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../gnl/get_next_line.h"
# include "../printf/ft_printf.h"
# include <stdlib.h>
# include <fcntl.h>
# include <libc.h>


typedef struct	s_data {
	void	*mlx_connection;
	void	*mlx_win;
	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	char 	**map;
	int 	y_npc;
	int		x_npc;
	int 	y_;
	int		x_;
	int 	coins;
	int 	read_coins;
	int		flood_fill_check;
}				t_data;


int 	ft_check_ext(char *argv[]);

int		ft_check_matrix(t_data *data);

void	ft_flood_fill(t_data *data);

void	ft_fill(t_data *data, int x, int y, int x_npc, int y_npc);

void 	ft_get_npc_yx_coins(t_data *data);

int		ft_check_doubles(t_data *data);

void 	ft_get_size_matrix(int fd, t_data *data);

void	ft_make_matrix(t_data *data, int fd);

void	ft_matrix(char *argv[], t_data *data);

void	ft_make_map(t_data *data);

void	ft_load_images(t_data *data);

int		key_hook(int keycode, t_data *data);

int		ft_up(t_data *data);

int		ft_left(t_data *data);

int		ft_down(t_data *data);

int		ft_right(t_data *data);

int 	ft_esc(t_data *data);

void 	ft_error(t_data *data);

void 	ft_error_checker(t_data *data);

void	ft_init_data(t_data *data);

#endif 
