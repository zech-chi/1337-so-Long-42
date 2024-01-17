/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:16:03 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 17:39:43 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_pressed_key(int key, t_map *map_info)
{
	map_info->rows = map_info->rows;
	if (key == 126 || key == 13)
		ft_move(map_info, -1, 0);
	else if (key == 124 || key == 2)
		ft_move(map_info, 0, 1);
	else if (key == 125 || key == 1)
		ft_move(map_info, 1, 0);
	else if (key == 123 || key == 0)
		ft_move(map_info, 0, -1);
	else if (key == 53)
		ft_free_mlx_business(map_info);
	return (0);
}

int	ft_check_if_the_game_end(t_map *map_info)
{
	if (map_info->player_row == map_info->exit_row
		&& map_info->player_col == map_info->exit_col)
	{
		if (map_info->count_collectibles == 0)
		{
			ft_putstr("\nyou win 🎉🏆🥇\n");
			ft_free_mlx_business(map_info);
		}
	}
	return (0);
}

void	ft_move_player(t_map *map_info, int dr, int dc)
{
	int	r;
	int	c;

	r = map_info->player_row;
	c = map_info->player_col;
	if (map_info->exit_row == r && map_info->exit_col == c)
	{
		ft_put_door_in_win(map_info, r, c, map_info->count_collectibles == 0);
		map_info->map[r][c] = 'E';
	}
	else
	{
		ft_put_passage_in_win(map_info, r, c);
		map_info->map[r][c] = '0';
	}
	map_info->map[r + dr][c + dc] = 'P';
	ft_put_player_in_win(map_info, r + dr, c + dc);
	map_info->player_row += dr;
	map_info->player_col += dc;
}

void	ft_move(t_map *map_info, int dr, int dc)
{
	int	r;
	int	c;

	r = map_info->player_row;
	c = map_info->player_col;
	if (map_info->map[r + dr][c + dc] != '1')
	{
		if (map_info->map[r + dr][c + dc] == 'C')
		{
			map_info->count_collectibles -= 1;
			map_info->map[r + dr][c + dc] = '0';
			ft_put_passage_in_win(map_info, r + dr, c + dc);
			if (map_info->count_collectibles == 0)
			{
				ft_put_door_in_win(map_info, map_info->exit_row,
					map_info->exit_col, 1);
			}
		}
		map_info->count_player_moves += 1;
		ft_putstr("\nmoves --> ");
		ft_putnbr(map_info->count_player_moves);
		ft_move_player(map_info, dr, dc);
	}
}
