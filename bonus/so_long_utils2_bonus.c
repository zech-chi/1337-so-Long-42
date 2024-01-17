/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:24:25 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:24:45 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		map[r] = ft_strdup(cur_node->content);
		if (!map[r])
		{
			ft_clear_map_n(map, r);
			ft_lstclear(head);
			exit(0);
		}
		cur_node = cur_node->next;
		r++;
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
		&& (map[nr][nc] != '1') && (map[nr][nc] != 'v') && (map[nr][nc] != 'X'))
			ft_flood_fill(map, map_details, nr, nc);
	}
}

void	ft_can_eat_and_exit_help(t_map *map_details, char **map_copy)
{
	int	r;
	int	c;

	r = -1;
	while (++r < map_details->rows)
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
}

int	ft_can_eat_and_exit(t_map *map_details)
{
	char	**map_copy;
	int		r;

	map_copy = (char **)malloc(sizeof(char *) * (map_details->rows + 1));
	if (!map_copy)
		return (0);
	r = -1;
	while (++r < map_details->rows)
	{
		map_copy[r] = ft_strdup(map_details->map[r]);
		if (!map_copy[r])
		{
			ft_clear_map(map_details->map);
			ft_clear_map_n(map_copy, r);
			exit(0);
		}
	}
	map_copy[r] = NULL;
	ft_flood_fill(map_copy, *map_details, map_details->player_row, \
	map_details->player_col);
	ft_can_eat_and_exit_help(map_details, map_copy);
	return (ft_clear_map(map_copy), 1);
}
