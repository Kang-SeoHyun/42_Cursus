# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokang <seokang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 18:17:56 by seokang           #+#    #+#              #
#    Updated: 2023/04/03 18:17:57 by seokang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= philo
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -fsanitize=thread
RM			= rm -f

# source files
SRCS      	= main.c 		\
			  parsing.c 	\
			  philo_utils.c \
			  philosopher.c \
			  simulate.c	

OBJS		= $(SRCS:c=o)


all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -lpthread -o $@

clean:
	@$(RM) $(OBJS)

fclean:
	@$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
