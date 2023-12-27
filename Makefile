# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: polmarti <polmarti@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/27 20:09:02 by polmarti          #+#    #+#              #
#    Updated: 2023/12/27 20:09:04 by polmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = So_long

SRCS =  gnl/get_next_line.c gnl/get_next_line_utils.c printf/ft_printf.c \
		printf/ft_printf_utils.c errors_check.c graphic.c matrix.c movements.c\
		utils.c main.c

INCLUDES = inc/so_long.h

FLAGS = -Wall -Wextra -Werror -MMD -g

MLX = -framework OpenGL -framework AppKit

OBJS = $(SRCS:.c=.o)

DEPS = $(SRCS:.c=.d)

all: makemlx $(NAME)

CC = gcc

%.o:%.c Makefile
	$(CC) $(FLAGS) -I ./ -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) mlx/libmlx.a $(MLX) $(OBJS) -o $(NAME)

makemlx: 
	$(MAKE) -C mlx/

clean:
	rm -rf $(OBJS) $(DEPS)
	$(MAKE) -C mlx clean

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re makemlx