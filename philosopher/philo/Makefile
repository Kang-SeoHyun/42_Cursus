# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokang <seokang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 21:51:26 by seokang           #+#    #+#              #
#    Updated: 2023/04/11 22:29:03 by seokang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= philo
HEADER 		= philo.h
CC          = cc
CFLAGS      = -Wall -Wextra -Werror #-g -fsanitize=thread
RM			= rm -rf

# source files
SRCS 		= parsing.c		\
			  init.c		\
	   		  philo_utils.c	\
	   		  routine.c		\
	   		  print.c		\
			  main.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -lpthread -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
