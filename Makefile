MANSRCS = 	get_next_line.c get_next_line_utils.c \
			linked_list.c \
			so_long.c so_long_utils1.c so_long_utils2.c\
			help_function_must_removed.c

MANOBJS = $(MANSRCS:.c=.o)

NAME = so_long.a

$(NAME): $(MANOBJS)
	ar -rcs $(NAME) $^

%.o: %.c so_long.h
	cc -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

clean:
	rm -f $(MANOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
