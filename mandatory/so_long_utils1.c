/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:05:42 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 18:08:42 by zech-chi         ###   ########.fr       */
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

void	ft_scanne_last_line(char *line, t_map *map_info)
{
	int	c;

	c = -1;
	while (line && line[++c])
	{
		if (line[c] != '1')
			map_info->surrounded_by_walls = 0;
	}
}

int	ft_read_file(int fd, t_map *map_details, t_list **map_list)
{
	char	*line;
	int		r;
	int		c;

	r = 0;
	line = get_next_line(fd);
	while (line)
	{
		ft_lstadd_back(map_list, ft_lstnew(line));
		if (!map_list)
			exit(0);
		ft_line_scanner(map_details, line, r++, &c);
		if (line[c - 1] != '1')
			(*map_details).surrounded_by_walls = 0;
		line = get_next_line(fd);
	}
	if (*map_list == NULL)
		return (0);
	line = (ft_lstlast(*map_list))->content;
	ft_scanne_last_line(line, map_details);
	(*map_details).rows = r;
	return (1);
}

void	ft_clear_map_n(char **str, int size)
{
	int	r;

	if (size == 0)
		return ;
	r = 0;
	while (r < size)
	{
		free(str[r]);
		r++;
	}
	free(str);
}

void	ft_clear_map(char **str)
{
	int	r;

	if (!str)
		return ;
	r = 0;
	while (str[r])
	{
		free(str[r]);
		r++;
	}
	free(str);
}
