# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokang <seokang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/11 17:50:07 by seokang           #+#    #+#              #
#    Updated: 2023/03/26 19:25:15 by seokang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM			= rm -f
MLX			= -Lmlx -lmlx -framework OpenGL -framework Appkit
LIBFT		= -Llibft -lft

# header files
HEADER_DIR  = mandatory/
HEADER_SRCS	= so_long.h
HEADER		= $(addprefix $(HEADER_DIR), $(HEADER_SRCS))

# source files
M_DIR		= mandatory/
M_SRCS      = init_game.c main.c map_check.c init_map.c map_valid.c init_move.c init_img.c
M_PATH		= $(addprefix $(M_DIR), $(M_SRCS))
M_OBJS		= $(M_PATH:c=o)

#gnl
G_DIR		= gnl/
G_SRCS		= get_next_line.c get_next_line_util.c
G_PATH		= $(addprefix $(G_DIR), $(G_SRCS))
G_OBJS		= $(G_PATH:c=o)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(G_OBJS) $(M_OBJS)
	@make -C mlx all
	@make -C libft all
	@$(CC) $(CFLAGS) $(MLX) $(LIBFT) $(G_OBJS) $(M_OBJS) -o $@

all: $(NAME)

clean:
	@make -C mlx clean
	@make -C libft clean
	@$(RM) $(G_OBJS)
	@$(RM) $(M_OBJS)

fclean:
	@make -C libft fclean
	@make clean
	@$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
