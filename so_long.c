/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:15:49 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/22 11:41:55 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	main(void)
{
	t_map	map_details;
	int		fd;

	map_details = (t_map){-1, -1, 1, 1, 0, 0, 0, -1, -1, -1, -1, 0, 1, 1, NULL};
	fd = open("map.ber", O_RDONLY);
	ft_print_map_info(map_details);
	ft_read_file(fd, &map_details);
	ft_print_map_info(map_details);
	ft_is_valid_map_part1(map_details);
	ft_is_valid_map_part2(map_details, 0);
	return (0);
}
