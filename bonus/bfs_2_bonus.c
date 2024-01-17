/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:06:29 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:08:55 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

#include "so_long.h"

void	ft_check_neighbors_help(t_list **q, char *path, t_map *map_info, char c)
{
	if (c == 'u')
	{
		ft_lstadd_back(q, ft_lstnew(ft_strjoin2(path, "u")));
		if (!q)
			ft_free_mlx_business(map_info);
	}
	else if (c == 'd')
	{
		ft_lstadd_back(q, ft_lstnew(ft_strjoin2(path, "d")));
		if (!q)
			ft_free_mlx_business(map_info);
	}
	else if (c == 'l')
	{
		ft_lstadd_back(q, ft_lstnew(ft_strjoin2(path, "l")));
		if (!q)
			ft_free_mlx_business(map_info);
	}
	else if (c == 'r')
	{
		ft_lstadd_back(q, ft_lstnew(ft_strjoin2(path, "r")));
		if (!q)
			ft_free_mlx_business(map_info);
	}
}

void	ft_check_neighbors(t_map *map_info, char *path, char **map, t_list **q)
{
	int	r;
	int	c;

	ft_fill_r_and_c(*map_info, path, &r, &c);
	if (r - 1 >= 0 && map[r - 1][c] != '1' && map[r - 1][c] != 'v')
	{
		ft_check_neighbors_help(q, path, map_info, 'u');
		map[r - 1][c] = 'v';
	}
	if (r + 1 < map_info->rows && map[r + 1][c] != '1' && map[r + 1][c] != 'v')
	{
		ft_check_neighbors_help(q, path, map_info, 'd');
		map[r + 1][c] = 'v';
	}
	if (c - 1 >= 0 && map[r][c - 1] != '1' && map[r][c - 1] != 'v')
	{
		ft_check_neighbors_help(q, path, map_info, 'l');
		map[r][c - 1] = 'v';
	}
	if (c + 1 < map_info->cols && map[r][c + 1] != '1' && map[r][c + 1] != 'v')
	{
		ft_check_neighbors_help(q, path, map_info, 'r');
		map[r][c + 1] = 'v';
	}
}

char	*ft_bfs(t_map *map_info, char **map)
{
	t_list	*queue;
	char	*cur_path;
	int		r;
	int		c;

	queue = NULL;
	ft_lstadd_back(&queue, ft_lstnew(ft_strdup("")));
	while (queue)
	{
		cur_path = ft_del_first_elem(&queue);
		ft_fill_r_and_c(*map_info, cur_path, &r, &c);
		if (r == map_info->player_row && c == map_info->player_col)
			return (ft_lstclear(&queue), cur_path);
		map[r][c] = 'v';
		ft_check_neighbors(map_info, cur_path, map, &queue);
		free(cur_path);
	}
	ft_lstclear(&queue);
	return (NULL);
}
