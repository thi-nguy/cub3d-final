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

# MINILIBX = -L./minilibx-linux/ -lmlx -lmlx_Linux

LIBFT = -L./libft/ -lft

OTHER_LIB = -lXext -lX11 -lm -lbsd

FLAGS = -g -O3 -fsanitize=address -Wall -Wextra -Werror 
# -framework OpenGL -framework AppKit


CC = gcc -I./include/

RM = rm -f

NAME = cub3D

SRC = 	./src/main.c\
		./src/utils.c\
		

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



