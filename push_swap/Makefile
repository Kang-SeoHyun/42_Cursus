# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seokang <seokang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 17:06:51 by seokang           #+#    #+#              #
#    Updated: 2023/01/15 06:02:43 by seokang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
RM 		= rm -rf
NAME 	= push_swap
BONUS	= checker
HEADER 	= push_swap.h

SRCS_M 		=	hard_code.c \
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

SRCS_B		=
				

OBJS_M = $(addprefix ./mandatory/, $(SRCS_M))
OBJS_B = $(addprefix ./bonus/, $(SRCS_B))

SRCS_M_FILES = $(OBJS_M:c=o)
SRCS_B_FILES = $(OBJS_B:c=o)

MANDa_DIR = mandatory
BONUS_DIR = bonus

%.o : %c
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(SRCS_M_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(BONUS) : $(SRCS_B_FILES)
	$(CC) $(CFLAGS) -o $@ $^

all : $(NAME)

bonus : $(BONUS)

clean :
	$(RM) $(SRCS_M_FILES)
	$(RM) $(SRCS_B_FILES)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS)

re :
	make fclean
	make all

.PHONY: all clean fclean re bonus