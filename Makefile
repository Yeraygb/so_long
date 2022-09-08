# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 13:39:06 by ygonzale          #+#    #+#              #
#    Updated: 2022/09/08 11:24:56 by ygonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = main.c \
	src/ft_sprites.c \
	src/get_map.c \
	src/utils.c \
	src/check_errors.c \
	src/ft_split.c \
	src/ft_strchr.c \
	src/ft_strjoin.c \
	src/ft_substr.c \
	src/get_next_line.c \
	src/get_next_line_utils.c

OBJS = $(SRC:.c=.o)
LINKS =	-L . -lmlx -framework OpenGL -framework AppKit
FLAGS = gcc  -g

$(NAME): $(OBJS)
	@echo ✅ "\033[92;3;4mcompilation done\033[0m" ✅
	@make -C minilibx
	@cp minilibx/libmlx.a .
	@$(FLAGS) $(LINKS) $(SRC) -o so_long

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@echo 🗑 "\033[31;3;4mall clean\033[0m" 🗑

fclean: clean
	@rm -f $(NAME)
	@rm -rf so_long
	@make -C minilibx clean

re: fclean all

.PHONY = all clean fclean re