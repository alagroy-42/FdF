# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alagroy- <alagroy-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 16:37:01 by alagroy-          #+#    #+#              #
#    Updated: 2019/03/15 17:18:27 by alagroy-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = bresenham_control.c bresenham_trace.c fdf.c main.c parsing.c tools.c

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -I $(INCLUDE)

INCLUDE = /usr/local/include/mlx.h

MLX = /usr/local/lib/

FLAGS_MLX = -framework OpenGL -framework AppKit


%.o: %.c
	@printf "\033[0;32m[FdF] Compiation [.c]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32m[FdF] Compilation [.o]\r"

all: $(NAME)

$(NAME): $(OBJ)
	@printf "\033[0;32m[FdF] Compilation [OK]\n"
	@make -C libft
	@printf "\033[0;32m[FdF] Linking [.o]\r"
	@$(CC) $(CFLAGS) $(OBJ) -L $(MLX) -lmlx -L libft -lft $(FLAGS_MLX) -o $(NAME)
	@printf "\033[0;32m[FdF] Linking [OK]\n"

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@printf "\033[0;31m[FdF] Clean [OK]\n"

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@printf "\033[0;31m[FdF] Fclean [OK]\n"

re: fclean all

.PHONY: fclean clean all re
