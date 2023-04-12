# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokang <seokang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 21:51:26 by seokang           #+#    #+#              #
#    Updated: 2023/04/12 17:09:37 by seokang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# compile options
NAME		= philo
HEADER 		= philo.h
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -fsanitize=thread
RM			= rm -rf

# source files
SRCS 		= parsing.c		\
			  init.c		\
	   		  philo_utils.c	\
	   		  routine.c		\
	   		  print.c		\
			  main.c

OBJS		= $(SRCS:.c=.o)

RESET		= \033[0m
GREEN 		= \033[1;32m
YELLOW		= \033[1;33m

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -lpthread -o $@
	@echo "$(GREEN)╔════════════════════════════════════════╗$(RESET)"
	@echo "$(GREEN)║           philo make success.          ║$(RESET)"
	@echo "$(GREEN)╠════════════════════════════════════════╣$(RESET)"
	@echo "$(GREEN)║                      🍝 🍴 💤 🛌 📘 🖌  ║$(RESET)"
	@echo "$(GREEN)╚════════════════════════════════════════╝$(RESET)"

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@echo "$(YELLOW)╔════════════════════════════════════════╗$(RESET)"
	@echo "$(YELLOW)║           🗑 clean finish. 🗑            ║$(RESET)"
	@echo "$(YELLOW)╚════════════════════════════════════════╝$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(YELLOW)╔════════════════════════════════════════╗$(RESET)"
	@echo "$(YELLOW)║           📦 fclean finish. 📦         ║$(RESET)"
	@echo "$(YELLOW)╚════════════════════════════════════════╝$(RESET)"

re:
	@make fclean
	@make all

.PHONY: all clean fclean re

