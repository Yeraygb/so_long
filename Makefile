# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygonzale <ygonzale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 13:39:06 by ygonzale          #+#    #+#              #
#    Updated: 2022/06/29 13:44:15 by ygonzale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = main.c

OBJS = $(SRC:.c=.o)

FLAGS = gcc -Wall -Werror -Wextra -g

$(NAME): $(OBJS)
	@echo ✅ "\033[92;3;4mcompilation done\033[0m" ✅
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(FLAGS) $(SRC) -o so_long

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@echo 🗑 "\033[31;3;4mall clean\033[0m" 🗑

fclean: clean
	@rm -f $(NAME)
	@rm -rf so_long

re: fclean all

.PHONY = all clean fclean re