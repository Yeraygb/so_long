# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 13:39:06 by ygonzale          #+#    #+#              #
#    Updated: 2022/12/14 15:29:25 by ygonzale         ###   ########.fr        #
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
	src/get_next_line.c \
	src/get_next_line_utils.c \
	src/get_hooks.c \
	src/check_errors2.c \
	src/ft_itoa.c \
	src/utils2.c \
	src/way.c \
	
OBJS = $(SRC:.c=.o)
LINKS =	-L . -lmlx -framework OpenGL -framework AppKit  -g3 -fsanitize=address
FLAGS = gcc -Wall -Werror -Wextra

$(NAME): $(OBJS)
	@echo ✅ "\033[92;3;4mcompilation done\033[0m" ✅
	@make -C minilibx
	@cp minilibx/libmlx.a .
	@$(FLAGS) $(LINKS) $(SRC) -o so_long

%.o : %.c
	$(FLAGS) -c $< -o $@

#.SILENT:

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@echo 🗑 "\033[31;3;4mall clean\033[0m" 🗑

fclean: clean
	@rm -f $(NAME)
	@rm -rf so_long
	@make -C minilibx clean
	@rm -f libmlx.a

re: fclean all

.PHONY = all clean fclean re