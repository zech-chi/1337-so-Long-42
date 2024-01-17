/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:07:22 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:28:50 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# define BUFFER_SIZE 1
# define WALL_IMG "bonus/textures/wall.xpm"
# define OPENED_DOOR_IMG "bonus/textures/opened_door.xpm"
# define CLOSED_DOOR_IMG "bonus/textures/closed_door.xpm"
# define PLAYER_IMG "bonus/textures/player.xpm"
# define PASSAGE_IMG "bonus/textures/passage.xpm"
# define COIN1_IMG "bonus/textures/coin_1.xpm"
# define COIN2_IMG "bonus/textures/coin_2.xpm"
# define COIN3_IMG "bonus/textures/coin_3.xpm"
# define COIN4_IMG "bonus/textures/coin_4.xpm"
# define COIN5_IMG "bonus/textures/coin_5.xpm"
# define COIN6_IMG "bonus/textures/coin_6.xpm"
# define COIN7_IMG "bonus/textures/coin_7.xpm"
# define COIN8_IMG "bonus/textures/coin_8.xpm"
# define COIN9_IMG "bonus/textures/coin_9.xpm"
# define ENEMY1_IMG "bonus/textures/enemy_1.xpm"
# define ENEMY2_IMG "bonus/textures/enemy_2.xpm"
# define ENEMY3_IMG "bonus/textures/enemy_3.xpm"
# define ENEMY4_IMG "bonus/textures/enemy_4.xpm"
# define ENEMY5_IMG "bonus/textures/enemy_5.xpm"
# define ENEMY6_IMG "bonus/textures/enemy_6.xpm"
# define ENEMY7_IMG "bonus/textures/enemy_7.xpm"
# define ENEMY8_IMG "bonus/textures/enemy_8.xpm"

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
	void	*opened_door_img;
	void	*closed_door_img;
	void	*player_img;
	int		cur_coin_img;
	int		reset_coin;
	int		reset_door;
	void	*coin1_img;
	void	*coin2_img;
	void	*coin3_img;
	void	*coin4_img;
	void	*coin5_img;
	void	*coin6_img;
	void	*coin7_img;
	void	*coin8_img;
	void	*coin9_img;
	void	*enemy1_img;
	void	*enemy2_img;
	void	*enemy3_img;
	void	*enemy4_img;
	void	*enemy5_img;
	void	*enemy6_img;
	void	*enemy7_img;
	void	*enemy8_img;
	int		count_enemy;
	int		enemy_row;
	int		enemy_col;
	int		cur_enemy_img;
	int		cur_frame;
}	t_map;

// bfs_2.c
void	ft_check_neighbors_help(t_list **q, char *path,
			t_map *map_info, char c);
void	ft_check_neighbors(t_map *map_info, char *path, char **map, t_list **q);
char	*ft_bfs(t_map *map_info, char **map);

// bfs.c
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_del_first_elem(t_list **queue);
void	ft_fill_r_and_c(t_map map_info, char *str, int *r, int *c);
void	ft_clear_map_n(char **str, int size);
char	*ft_enemy_path_to_player(t_map *map_info);

// get_next_line_utils.c
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	shift_buff_or_clean_it(char *buff, size_t right);
int		has_the_end(char *buff, char **line);

// get_next_line.c
char	*get_next_line(int fd);

// graphical_part_1.c
void	ft_set_pieces_in_win(t_map *map_info);
void	ft_check_if_valid_mlx_info_1(t_map *map_info, int *is_something_wrong);
void	ft_check_if_valid_mlx_info_2(t_map *map_info, int *is_something_wrong);
void	ft_check_if_valid_mlx_info_3(t_map *map_info, int *is_something_wrong);
void	ft_check_if_valid_mlx_info_4(t_map *map_info, int *is_something_wrong);

// graphical_part_2.c
void	ft_put_passage_in_win(t_map *map_info, int r, int c);
void	ft_put_wall_in_win(t_map *map_info, int r, int c);
void	ft_put_door_in_win(t_map *map_info, int r, int c, int opened);
void	ft_put_player_in_win(t_map *map_info, int r, int c);

// graphical_part_3.c
void	ft_check_if_valid_mlx_info_5(t_map *map_info, int *is_something_wrong);
void	ft_check_if_valid_mlx_info_6(t_map *map_info, int *is_something_wrong);
void	ft_fill_mlx_map_info_2(t_map *map_info);
void	ft_fill_mlx_map_info_3(t_map *map_info);
int		ft_fill_mlx_map_info(t_map *map_info);

// graphical_part_4.c
void	ft_destroy_enemy_imgs(t_map *map_info);
void	ft_destroy_coin_imgs(t_map *map_info);
int		ft_free_mlx_business(t_map *map_info);

// graphical_part_5.c
void	ft_put_collectible_in_win_continue(t_map *map_info, int r, int c);
void	ft_put_collectible_in_win(t_map *map_info, int r, int c);
void	ft_put_enemy_in_win_continue(t_map *map_info, int r, int c);
void	ft_put_enemy_in_win(t_map *map_info, int r, int c);

// linked_list.c
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);

// play.c
int		ft_get_pressed_key(int key, t_map *map_info);
void	ft_check_if_the_game_end(t_map *map_info);
void	ft_move_player(t_map *map_info, int dr, int dc);
void	ft_move2(t_map *map_info, int dr, int dc, char **str);
void	ft_move(t_map *map_info, int dr, int dc);

// so_long_utils1.c
int		ft_is_valid_map_part1(t_map map_details);
int		ft_is_valid_map_part2(t_map map_details);
int		ft_is_valid_map_part3(t_map *map_details);
void	ft_help_line_scanner(t_map *map_details, int r, int *c, char k);
void	ft_line_scanner(t_map *map_details, char *line, int r, int *c);

// so_long_utils2.c
char	**ft_create_map(t_list **head, t_map map_details);
void	ft_clear_map(char **str);
void	ft_flood_fill(char **map, t_map map_details, int r, int c);
void	ft_can_eat_and_exit_help(t_map *map_details, char **map_copy);
int		ft_can_eat_and_exit(t_map *map_details);

// so_long_utils3.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
int		ft_is_valid_map_name(char *map_name);

// so_long_utils4.c
void	ft_initialize_map_info_2(t_map *map_info);
void	ft_initialize_map_info(t_map *map_info);
int		len_of_number(long long n);
char	*fill(char *ptr, long long ln, int size);
char	*ft_itoa(int n);

// so_long_utils5.c
void	ft_scanne_last_line(char *line, t_map *map_info);
int		ft_read_file(int fd, t_map *map_details, t_list **map_list);
int		ft_check_map_is_valid(t_map *map_info, int fd);

// so_long.c
void	ft_animate_enemy_coin(t_map *map_info);
void	ft_check_reset_coin_door(t_map *map_info);
void	ft_update_enemy_coordinates(char *path, t_map *map_info);
int		ft_render_next_frame(t_map *map_info);

#endif