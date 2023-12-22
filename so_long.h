/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:12:54 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/22 11:07:20 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h> ////////////////////
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
void	shift_buff_or_clean_it(char *buff, size_t j);
int		has_the_end(char *buff, char **line);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **lst, void (*del)(void*));
t_list	*ft_lstlast(t_list *lst);

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
	char	**map;
}	t_map;

void	ft_putstr_fd(char *s, int fd);
int		ft_is_valid_map_part1(t_map map_details);
int		ft_is_valid_map_part2(t_map map_details, int check_path);

void	ft_print_map_info(t_map map_details); //////////////////
#endif