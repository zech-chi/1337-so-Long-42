NAME = so_long

BONNAME = so_long_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

RM = rm -f

SRCS =  mandatory/get_next_line.c\
		mandatory/get_next_line_utils.c\
		mandatory/graphical_part_1.c\
		mandatory/graphical_part_2.c\
		mandatory/linked_list.c\
		mandatory/play.c\
		mandatory/so_long.c\
		mandatory/so_long_utils1.c\
		mandatory/so_long_utils2.c\
		mandatory/so_long_utils3.c\
		mandatory/so_long_utils4.c\

BONSRCS =  bonus/get_next_line.c\
		bonus/get_next_line_utils.c\
		bonus/graphical_part_1.c\
		bonus/graphical_part_2.c\
		bonus/graphical_part_3.c\
		bonus/graphical_part_4.c\
		bonus/graphical_part_5.c\
		bonus/linked_list.c\
		bonus/play.c\
		bonus/so_long.c\
		bonus/so_long_utils1.c\
		bonus/so_long_utils2.c\
		bonus/so_long_utils3.c\
		bonus/so_long_utils4.c\
		bonus/so_long_utils5.c\
		bonus/bfs.c\
		bonus/bfs_2.c

OBJS = $(SRCS:.c=.o)

BONOBJS = $(BONSRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $^ -o $@

$(BONNAME): $(BONOBJS)
	$(CC) $(CFLAGS) $(MLXFLAGS) $^ -o $@

%_bonus.o: %_bonus.c bonus/so_long_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c mandatory/so_long.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONOBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONNAME)

re: fclean all

.PHONY: all clean fclean re
