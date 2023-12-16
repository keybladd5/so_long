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

#include "minilibx_opengl_20191021/mlx.h"
#include <stdlib.h>

#define MALLOC_ERROR 1
#define WIDTH 400
#define HEIGHT 400

typedef struct	s_data {
	void	*mlx_con;
	void	*mlx_win;
	void	*img;
}				t_data;

