# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/16 13:28:10 by thi-nguy          #+#    #+#              #
#    Updated: 2020/09/22 11:29:26 by thi-nguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = -L./libft/ -lft

MINILIBX = -L./minilibx-linux/ -lmlx -lmlx_Linux 		#put this on when we compile sur Linux
OTHER_LIB = -lXext -lX11 -lm -lbsd 					#put this on when we compile sur Linux

FLAGS = -O3 -Wall -Wextra -Werror -fsanitize=address
# -framework OpenGL -framework AppKit
# -fsanitize=address: dung de chi ra memory leak neu co


CC = gcc -g -I./include/

RM = rm -f

NAME = cub3D

SRC = 	./src/main.c\
		./src/check_argument.c\
		./src/get_fd.c\
		./src/parse.c\
		./src/parse_info.c\
		./src/parse_info_utils.c\
		./src/parse_map.c\
		./src/parse_map_utils.c\
		./src/init_global.c\
		./src/init_global_utils.c\
		./src/free_memory.c\
		./src/check_copy_map_element_into_array.c\
		./src/check_if_map_close.c\
		./src/init_sprite.c\
		./src/game_loop.c\
		./src/draw_floor_ceiling.c\
		./src/draw_mini_map.c\
		./src/move_player.c\
		./src/cast_ray.c\
		./src/bmp_export.c\
		./src/render_ray.c\
		./src/find_intercept.c\
		./src/find_smallest_distance.c\
		./src/draw_mini_map_utils.c\


OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(LIBFT)  $(MINILIBX) $(OTHER_LIB)

clean:
	-@echo "Removing object files..."
	make clean -C ./libft
	$(RM) $(OBJ)

fclean : clean
	-@echo "Removing object files and executive file..."
	make fclean -C ./libft
	$(RM) $(NAME)



