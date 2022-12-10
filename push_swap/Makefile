# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokang <seokang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 17:06:51 by seokang           #+#    #+#              #
#    Updated: 2022/12/10 21:58:25 by seokang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
NAME 		= push_swap
BONUS_NAME	= checker
HEADER 		= push_swap.h

SRCS 		=

SRCS_W		= $(addprefix ./mandatory/, $(SRC))

BONUS 		= 

BONUS_W		= $(addprefix ./bonus/, $(BONUS))

SRCS_OBJS 	= $(SRCS_W:.c=.o)
BONUS_OBJS 	= $(BONUS_W:.c=.o)

all: $(NAME)

$(NAME): all_check

all_check: $(OBJS)
	touch $@
	$(CC) $(CFLAGS) $(SRCS_OBJS) -o $(NAME)

bonus: bonus_check

bonus_check: $(B_OBJS)
	touch $@
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -rf $(SRCS_OBJS)
	rm -rf $(BONUS_OBJS)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS_NAME)

re:
		make fclean
		make all

.PHONY: all bonus clean fclean re