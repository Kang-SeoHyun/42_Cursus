# compile options
NAME		= philo
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -fsanitize=thread
RM			= rm -f

# source files
SRCS      	= 
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
