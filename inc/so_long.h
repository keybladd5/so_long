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
# include "../minilibx_opengl_20191021/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include <libc.h>



# define MALLOC_ERROR 1
# define WIDTH 400
# define HEIGHT 400

typedef struct	s_data {
	void	*mlx_connection;
	void	*mlx_win;
	void	*img;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	int		bits_per_pixel;
	int		line_length;
	char 	**map;
	int 	y_npc;
	int		x_npc;
	int 	y_;
	int		x_;
	int 	coins;
}				t_data;


char	*get_next_line(int fd);

int 	ft_check_ext(char *argv[]);

void 	ft_get_size_map(int fd, t_data *data);

char	**ft_make_area(t_data *data, int fd);

void	ft_map(char *argv[], t_data *data);

void	ft_make_map(t_data *data, char** map);

int		key_hook(int keycode, t_data *data);

#endif 
