/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:15:49 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/21 10:28:38 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_map
{
	int	rows;
	int	cols;
	int	is_rectangular;
	int	surrounded_by_walls;
	int	count_collectibles;
	int	count_map_exit;
	int	count_starting_position;
	int	player_row;
	int	player_col;
	int	exit_row;
	int	exit_col;
	int	have_another_char;
	int	can_player_eat_all_collectibles;
	int	can_player_exit;
	char **map;
}	t_map;



int	ft_is_valid_map(t_map map_details)
{
	if (map_details.cols == map_details.rows || (!map_details.is_rectangular))
		return (ft_putstr_fd("The map must be rectangular!", 2), 0);
	if (!map_details.surrounded_by_walls)
		return (ft_putstr_fd("The map must be closed/surrounded by walls!", 2), 0);
	if (!map_details.count_collectibles)
		return (ft_putstr_fd("The map must contain at least 1 collectible!", 2), 0);
	if (map_details.count_map_exit != 1)
		return (ft_putstr_fd("The map must contain 1 exit!", 2), 0);
	if (map_details.count_starting_position != 1)
		return (ft_putstr_fd("The map must contain 1 starting position!", 2), 0);
	if (map_details.have_another_char)
		return (ft_putstr_fd("The map must contain 0, 1, C, E or P!", 2), 0);
	if (!map_details.can_player_eat_all_collectibles)
		return (ft_putstr_fd("the player can't eat all collectibkes!", 2), 0);
	if (!map_details.can_player_exit)
		return (ft_putstr_fd("the player can't exit", 2), 0);
	return (0);
}

t_list	*ft_read_file(int fd, t_map *map_details)
{
	t_list	*head;
	char	*line;
	int	r;
	int	c;

	r = 0;
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		c = 0;
		while (line[c] && line[c] != '\n')
		{
			if ((r == 0 || c == 0) && line[c] != '1')
				(*map_details).surrounded_by_walls = 0;
			if (line[c] == 'C')
				(*map_details).count_collectibles += 1;
			else if (line[c] == 'E')
			{
				(*map_details).count_map_exit += 1;
				(*map_details).exit_row = r;
				(*map_details).exit_col = c;
			}
			else if (line[c] == 'P')
			{
				(*map_details).count_starting_position += 1;
				(*map_details).player_row = r;
				(*map_details).player_col = c;
			}
			else if (line[c] != '0' && line[c] != '1')
				(*map_details).have_another_char = 1;
			c++;
		}
		if (line[c - 1] != '1')
			(*map_details).surrounded_by_walls = 0;
		if ((*map_details).cols == -1)
			(*map_details).cols = c;
		else if ((*map_details).cols != c)
			(*map_details).is_rectangular = 0;
		line = get_next_line(fd);
		r++;
	}
	line = ft_lstlast(head)->content;
	c = 0;
	while (line && line[c])
	{
		if (line[c] != '1')
			(*map_details).surrounded_by_walls = 0;
		c++;
	}
	(*map_details).rows = r;
	return (head);
}


int	main()
{
	t_map	map_details;
	int						fd;
	
	map_details = (t_map){-1, -1, 1, 1, 0, 1, 0, -1, -1, -1, -1, 0, 1, 1, NULL};
	fd = open("map.ber", O_RDONLY);
	ft_is_valid_map(fd, &map_details);
	ft_is_valid_map(map_details);
	return (0);
}
