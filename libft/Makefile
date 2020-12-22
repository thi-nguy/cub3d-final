# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thi-nguy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/05 13:06:33 by thi-nguy          #+#    #+#              #
#    Updated: 2019/12/09 13:14:24 by thi-nguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc -c

AR = ar rc

#HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

SRC = ft_isdigit.c ft_memset.c ft_strjoin.c ft_strtrim.c ft_isprint.c\
ft_putchar_fd.c ft_strlcat.c ft_substr.c ft_atoi.c ft_itoa.c ft_putendl_fd.c\
ft_strlcpy.c ft_tolower.c ft_bzero.c ft_memccpy.c ft_putnbr_fd.c ft_strlen.c\
ft_toupper.c ft_calloc.c ft_memchr.c ft_putstr_fd.c ft_strmapi.c ft_isalnum.c\
ft_memcmp.c ft_split.c ft_strncmp.c ft_isalpha.c ft_memcpy.c ft_strchr.c\
ft_strnstr.c ft_isascii.c ft_memmove.c ft_strdup.c ft_strrchr.c\
ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c\
get_next_line.c get_next_line_utils.c ft_strcmp.c

# BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c\
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = $(SRC:.c=.o)

#OBJBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRC)
	$(AR) $(NAME) $(OBJ)
	ranlib $(NAME)

#bonus: 
#	$(CC) $(FLAGS) $(BONUS)
#	$(AR) $(NAME) $(OBJBONUS)
#	ranlib $(NAME)
clean:
	#rm -f $(OBJ) $(OBJBONUS)
	rm -f $(OBJ)

fclean: clean
	#rm -f $(NAME) bonus
	rm -f $(NAME)

re: fclean all
