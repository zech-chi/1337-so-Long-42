MANSRCS = get_next_line.c get_next_line_utils.c \
		so_long.c so_long_utils.c

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
