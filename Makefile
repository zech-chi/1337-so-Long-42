NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS =  get_next_line.c\
		get_next_line_utils.c\
		linked_list.c\
		so_long.c\
		so_long_utils1.c\
		so_long_utils2.c\
		so_long_utils3.c\
		moves.c\
		graphical_part_1.c

OBJS = $(SRCS:.c=.o)

#$(NAME): $(OBJS)
#	$(CC) $(CFLAGS) $^ -o $@
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -lmlx -framework OpenGL -framework AppKit -o $@

#%.o: %.c so_long.h
#	$(CC) $(CFLAGS) -c $< -o $@
%.o: %.c so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
