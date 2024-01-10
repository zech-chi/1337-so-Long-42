/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:12:54 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/10 01:10:52 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h> ////////////////////
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# define BUFFER_SIZE 1

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
void	shift_buff_or_clean_it(char *buff, size_t j);
int		has_the_end(char *buff, char **line);

// linked_list.c
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstclear(t_list **lst);

// so_long_utils1.c
void	ft_putstr_fd(char *s, int fd);
int		ft_is_valid_map_part1(t_map map_details);
int		ft_is_valid_map_part2(t_map map_details, int check_path);
void	ft_line_scanner(t_map *map_details, char *line, int r, int *c);
t_list	*ft_read_file(int fd, t_map *map_details);

// so_long_utils2.c
char	**ft_create_map(t_list **head, t_map map_details);
void	ft_clear_map(char **str);
void	ft_flood_fill(char **map, t_map map_details, int r, int c);
int		ft_can_eat_and_exit(t_map *map_details);
int		ft_check_map_is_valid(t_map *map_info, int fd);

// so_long_utils3.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(unsigned int u);
int		ft_strcmp(char *s1, char *s2);
int		ft_is_valid_map_name(char *map_name);
void	ft_initialize_map_info(t_map *map_info);

// moves.c
int		ft_get_pressed_key(int key, t_map *map_info);
void	ft_move_up(t_map *map_info);
void	ft_move_right(t_map *map_info);
void	ft_move_down(t_map *map_info);
void	ft_move_left(t_map *map_info);

// graphical_part_1.c
void	ft_set_pieces_in_win(t_map *map_info);
void	ft_fill_mlx_map_info(t_map *map_info);

void	ft_print_map_info(t_map map_details); //////////////////

#endif