CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS = 	push_swap.c utils.c ft_split.c push.c swap.c rotate.c reverse_rotate.c \
		linked_list_utils.c parsing_utils.c sorting_utils1.c sorting_utils2.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean rel