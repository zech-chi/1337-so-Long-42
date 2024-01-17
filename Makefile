NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -f

SRCS =  get_next_line.c\
		get_next_line_utils.c\
		graphical_part_1.c\
		graphical_part_2.c\
		linked_list.c\
		play.c\
		so_long.c\
		so_long_utils1.c\
		so_long_utils2.c\
		so_long_utils3.c\
		so_long_utils4.c\

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $^ -o $@

#$(BONNAME): $(BONOBJS)
#	$(CC) $(CFLAGS) $(MLXFLAGS) $^ -o $@

#%_bonus.o: %_bonus.c so_long_bonus.h
#	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
