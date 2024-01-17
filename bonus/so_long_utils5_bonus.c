/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils5_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:26:06 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:26:29 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	ft_check_map_is_valid(t_map *map_info, int fd)
{
	t_list	*map_list;
	int		check_1;
	int		check_2;

	map_list = NULL;
	if (!ft_read_file(fd, map_info, &map_list))
		return (ft_putstr_fd("Error\ncan't read file or maybe empty", 2), 0);
	map_info->map = ft_create_map(&map_list, *map_info);
	ft_lstclear(&map_list);
	if (!map_info->map)
		return (ft_putstr_fd("Error\nmap creation was failed", 2), 0);
	check_1 = ft_is_valid_map_part1(*map_info);
	check_2 = ft_is_valid_map_part2(*map_info);
	if (!check_1 || !check_2)
		return (ft_clear_map(map_info->map), 0);
	if (!ft_can_eat_and_exit(map_info) || !ft_is_valid_map_part3(map_info))
		return (ft_clear_map(map_info->map), 0);
	return (1);
}
