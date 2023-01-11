# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokang <seokang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 17:06:51 by seokang           #+#    #+#              #
#    Updated: 2023/01/11 15:38:22 by seokang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 			= cc
CFLAGS 		= -Wall -Wextra -Werror
NAME 		= push_swap
BONUS_NAME	= checker
HEADER 		= push_swap.h

OBJS 		=	hard_code.c \
				init_new.c \
				operations_push.c \
				operations_R_rotate.c \
				operations_rotate.c \
				operations_swap.c \
				push_pop.c \
				push_swap.c \
				ready_sort.c \
				rotate.c \
				sort.c \
				utils_find.c \
				utils_libft.c \
				utils_sort.c \
				utils_split.c \
				validate.c
				

SRCS = $(addprefix ./mandatory/, $(OBJS))
SRCS_BONUS = $(addprefix ./bonus/, $(OBJS_CHECKER))
SRCS_FILES = $(SRCS:c=o)
SRCS_BONUS_FILES = $(SRCS_BONUS:c=o)

MAND_DIR = mandatory
BONUS_DIR = bonus

RM = rm -rf

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(SRCS_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS) : $(SRCS_BONUS_FILES)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

bonus : $(BONUS)

clean :
	$(RM) $(SRCS_FILES)
	$(RM) $(SRCS_BONUS_FILES)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re :
	make fclean
	make all

.PHONY: all bonus clean fclean re