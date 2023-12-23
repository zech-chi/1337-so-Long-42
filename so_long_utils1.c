/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:05:42 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/23 10:39:34 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

int	ft_is_valid_map_part1(t_map map_details)
{
	int	is_something_worng;

	is_something_worng = 0;
	if (map_details.cols == map_details.rows || (!map_details.is_rectangular))
	{
		ft_putstr_fd("The map must be rectangular!", 2);
		is_something_worng = 1;
	}
	if (!map_details.surrounded_by_walls)
	{
		ft_putstr_fd("The map must be closed/surrounded by walls!", 2);
		is_something_worng = 1;
	}
	if (!map_details.count_collectibles)
	{
		ft_putstr_fd("The map must contain at least 1 collectible!", 2);
		is_something_worng = 1;
	}
	if (map_details.count_map_exit != 1)
	{
		ft_putstr_fd("The map must contain 1 exit!", 2);
		is_something_worng = 1;
	}
	return (is_something_worng == 0);
}

int	ft_is_valid_map_part2(t_map map_details, int check_path)
{
	int	is_something_worng;

	is_something_worng = 0;
	if (!check_path && map_details.count_starting_position != 1)
	{
		ft_putstr_fd("The map must contain 1 starting position!", 2);
		is_something_worng = 1;
	}
	if (!check_path && map_details.have_another_char)
	{
		ft_putstr_fd("The map must contain 0, 1, C, E and P!", 2);
		is_something_worng = 1;
	}
	if (check_path && !map_details.can_player_eat_all_collectibles)
	{
		ft_putstr_fd("the player can't eat all collectibles!", 2);
		is_something_worng = 1;
	}
	if (check_path && !map_details.can_player_exit)
	{
		ft_putstr_fd("the player can't exit", 2);
		is_something_worng = 1;
	}
	return (is_something_worng == 0);
}

void	ft_line_scanner(t_map *map_details, char *line, int r, int *c)
{
	*c = 0;
	while (line[*c] && line[*c] != '\n')
	{
		if ((r == 0 || *c == 0) && line[*c] != '1')
			(*map_details).surrounded_by_walls = 0;
		if (line[*c] == 'C')
			(*map_details).count_collectibles += 1;
		else if (line[*c] == 'E' && ++(*map_details).count_map_exit)
		{
			(*map_details).exit_row = r;
			(*map_details).exit_col = *c;
		}
		else if (line[*c] == 'P' && ++(*map_details).count_starting_position)
		{
			(*map_details).player_row = r;
			(*map_details).player_col = *c;
		}
		else if (line[*c] != '0' && line[*c] != '1')
			(*map_details).have_another_char = 1;
		(*c)++;
	}
	if ((*map_details).cols == -1)
		(*map_details).cols = *c;
	else if ((*map_details).cols != *c)
		(*map_details).is_rectangular = 0;
}

t_list	*ft_read_file(int fd, t_map *map_details)
{
	t_list	*head;
	char	*line;
	int		r;
	int		c;

	r = 0;
	head = NULL;
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		ft_line_scanner(map_details, line, r++, &c);
		if (line[c - 1] != '1')
			(*map_details).surrounded_by_walls = 0;
		line = get_next_line(fd);
	}
	line = (ft_lstlast(head))->content;
	c = -1;
	while (line && line[++c])
	{
		if (line[c] != '1')
			(*map_details).surrounded_by_walls = 0;
	}
	(*map_details).rows = r;
	return (head);
}
