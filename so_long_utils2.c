/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:55:03 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/08 20:40:18 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_create_map(t_list **head, t_map map_details)
{
	char	**map;
	t_list	*cur_node;
	int		r;

	if (!head || !(*head))
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (map_details.rows + 1));
	if (!map)
		return (NULL);
	r = 0;
	cur_node = *head;
	while (cur_node)
	{
		map[r++] = cur_node->content;
		cur_node = cur_node->next;
	}
	map[r] = NULL;
	return (map);
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

void	ft_flood_fill(char **map, t_map map_details, int r, int c)
{
	int	directions[4][2];
	int	nr;
	int	nc;
	int	i;

	directions[0][0] = 1;
	directions[0][1] = 0;
	directions[1][0] = 0;
	directions[1][1] = 1;
	directions[2][0] = -1;
	directions[2][1] = 0;
	directions[3][0] = 0;
	directions[3][1] = -1;
	map[r][c] = 'v';
	i = -1;
	while (++i < 4)
	{
		nr = r + directions[i][0];
		nc = c + directions[i][1];
		if ((0 <= nr && nr < map_details.rows) \
		&& (0 <= nc && nc < map_details.cols) \
		&& (map[nr][nc] != '1') && (map[nr][nc] != 'v'))
			ft_flood_fill(map, map_details, nr, nc);
	}
}

int	ft_can_eat_and_exit(t_map *map_details)
{
	char	**map_copy;
	int		r;
	int		c;

	map_copy = (char **)malloc(sizeof(char *) * (map_details->rows + 1));
	if (!map_copy)
		return (0);
	r = -1;
	while (++r < map_details->rows)
		map_copy[r] = ft_strdup(map_details->map[r]);
	map_copy[r] = NULL;
	ft_flood_fill(map_copy, *map_details, map_details->player_row, \
	map_details->player_col);
	while (--r >= 0)
	{
		c = -1;
		while (++c < map_details->cols)
		{
			if (map_copy[r][c] == 'C')
				map_details->can_player_eat_all_collectibles = 0;
			else if (map_copy[r][c] == 'E')
				map_details->can_player_exit = 0;
		}
	}
	return (ft_clear_map(map_copy), 1);
}

int	ft_check_map_is_valid(t_map *map_info, int fd)
{
	t_list	*map_list;

	map_list = ft_read_file(fd, map_info);
	map_info->map = ft_create_map(&map_list, *map_info);
	ft_lstclear(&map_list);
	if (!map_info->map)
		return (0);
	if (!ft_is_valid_map_part1(*map_info)
		|| !ft_is_valid_map_part2(*map_info, 0))
		return (0);
	if (!ft_can_eat_and_exit(map_info) || !ft_is_valid_map_part2(*map_info, 1))
		return (0);
	return (1);
}
