# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokang <seokang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/15 01:03:39 by seokang           #+#    #+#              #
#    Updated: 2023/01/15 01:03:52 by seokang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC= cc
CFLAGS= -Wall -Wextra -Werror
RM= rm -rf

NAME= server
NAMEC= client

SERVER_SRCS = server.c utils.c
CLIENT_SRCS = client.c utils.c
SERVERB_SRCS = server_bonus.c utils.c
CLIENTB_SRCS = client_bonus.c utils.c

SERVER_OBJS= $(SERVER_SRCS:.c=.o)
CLIENT_OBJS= $(CLIENT_SRCS:.c=.o)
SERVERB_OBJS= $(SERVERB_SRCS:.c=.o)
CLIENTB_OBJS= $(CLIENTB_SRCS:.c=.o)

ifdef WITH_BONUS
		SERVER_FILES = $(SERVERB_OBJS)
		CLIENT_FILES = $(CLIENTB_OBJS)
	else
		SERVER_FILES = $(SERVER_OBJS)
		CLIENT_FILES = $(CLIENT_OBJS)
endif

all: $(NAME) $(NAMEC)

$(NAME): $(SERVER_FILES)
	$(CC) $(CFLAGS) -o $(NAME) $(SERVER_FILES)

$(NAMEC): $(CLIENT_FILES)
	$(CC) $(CFLAGS) -o $(NAMEC) $(CLIENT_FILES)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(SERVER_OBJS) $(SERVERB_OBJS) $(CLIENT_OBJS) $(CLIENTB_OBJS)

fclean: clean
	$(RM) $(NAME) $(NAMEC)

re: fclean all

bonus: 
	make WITH_BONUS=1 all

.PHONY: all clean fclean re bonus