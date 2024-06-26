/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:12:54 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:37:00 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# define BUFFER_SIZE 1
# define WALL_IMG "mandatory/textures/wall1.xpm"
# define COIN_IMG "mandatory/textures/coin1.xpm"
# define OPENED_DOOR_IMG "mandatory/textures/opened_door_1.xpm"
# define CLOSED_DOOR_IMG "mandatory/textures/closed_door_1.xpm"
# define PLAYER_IMG "mandatory/textures/player3.xpm"
# define PASSAGE_IMG "mandatory/textures/passage.xpm"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_map
{
	int		rows;
	int		cols;
	int		is_rectangular;
	int		surrounded_by_walls;
	int		count_collectibles;
	int		count_map_exit;
	int		count_starting_position;
	int		player_row;
	int		player_col;
	int		exit_row;
	int		exit_col;
	int		have_another_char;
	int		can_player_eat_all_collectibles;
	int		can_player_exit;
	int		count_player_moves;
	char	**map;
	int		rpxl;
	int		cpxl;
	void	*mlx;
	void	*mlx_win;
	void	*passage_img;
	void	*wall_img;
	void	*coin_img;
	void	*opened_door_img;
	void	*closed_door_img;
	void	*player_img;
}	t_map;

// get_next_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	shift_buff_or_clean_it(char *buff, size_t right);
int		has_the_end(char *buff, char **line);

// linked_list.c
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);

// so_long_utils1.c
void	ft_line_scanner(t_map *map_details, char *line, int r, int *c);
void	ft_scanne_last_line(char *line, t_map *map_info);
int		ft_read_file(int fd, t_map *map_details, t_list **map_list);
void	ft_clear_map_n(char **str, int size);
void	ft_clear_map(char **str);

// so_long_utils2.c
char	**ft_create_map(t_list **head, t_map map_details);
void	ft_flood_fill(char **map, t_map map_details, int r, int c);
void	ft_can_eat_and_exit_help(t_map *map_details, char **map_copy);
int		ft_can_eat_and_exit(t_map *map_details);
int		ft_check_map_is_valid(t_map *map_info, int fd);

// so_long_utils3.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(unsigned int u);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);

// so_long_utils4.c
int		ft_is_valid_map_name(char *map_name);
void	ft_initialize_map_info(t_map *map_info);
int		ft_is_valid_map_part1(t_map map_details);
int		ft_is_valid_map_part2(t_map map_details);
int		ft_is_valid_map_part3(t_map map_details);

// play.c
int		ft_get_pressed_key(int key, t_map *map_info);
int		ft_check_if_the_game_end(t_map *map_info);
void	ft_move_player(t_map *map_info, int dr, int dc);
void	ft_move(t_map *map_info, int dr, int dc);

// graphical_part_1.c
void	ft_set_pieces_in_win(t_map *map_info);
void	ft_check_if_valid_mlx_info_1(t_map *map_info, int *is_something_wrong);
void	ft_check_if_valid_mlx_info_2(t_map *map_info, int *is_something_wrong);
int		ft_fill_mlx_map_info(t_map *map_info);
int		ft_free_mlx_business(t_map *map_info);

// graphical_part_2.c
void	ft_put_passage_in_win(t_map *map_info, int r, int c);
void	ft_put_wall_in_win(t_map *map_info, int r, int c);
void	ft_put_collectible_in_win(t_map *map_info, int r, int c);
void	ft_put_door_in_win(t_map *map_info, int r, int c, int opened);
void	ft_put_player_in_win(t_map *map_info, int r, int c);

#endif
