/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:16:03 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/10 00:19:38 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_pressed_key(int key, t_map *map_info)
{
	map_info->rows = map_info->rows;
	if (key == 126 || key == 13)
		ft_move_up(map_info);
	else if (key == 124 || key == 2)
		ft_move_right(map_info);
	else if (key == 125 || key == 1)
		ft_move_down(map_info);
	else if (key == 123 || key == 0)
		ft_move_left(map_info);
	else if (key == 53)
		exit(0);
	return (0);
}

void	ft_move_up(t_map *map_info)
{
	int	r;
	int	c;

	r = map_info->player_row;
	c = map_info->player_col;
	if (map_info->map[r - 1][c] == 'C' || map_info->map[r - 1][c] == '0')
	{
		if (map_info->map[r - 1][c] == 'C')
			map_info->count_collectibles -= 1;
		map_info->map[r - 1][c] = '0';
		ft_set_pieces_in_win(map_info);
		map_info->map[r - 1][c] = 'P';
		map_info->map[r][c] = '0';
		map_info->count_player_moves += 1;
		map_info->player_row -= 1;
		ft_set_pieces_in_win(map_info);
	}
}

void	ft_move_right(t_map *map_info)
{
	int	r;
	int	c;

	r = map_info->player_row;
	c = map_info->player_col;
	if (map_info->map[r][c + 1] == 'C' || map_info->map[r][c + 1] == '0')
	{
		if (map_info->map[r][c + 1] == 'C')
			map_info->count_collectibles -= 1;
		map_info->map[r][c + 1] = '0';
		ft_set_pieces_in_win(map_info);
		map_info->map[r][c + 1] = 'P';
		map_info->map[r][c] = '0';
		map_info->count_player_moves += 1;
		map_info->player_col += 1;
		ft_set_pieces_in_win(map_info);
	}
}

void	ft_move_down(t_map *map_info)
{
	int	r;
	int	c;

	r = map_info->player_row;
	c = map_info->player_col;
	if (map_info->map[r + 1][c] == 'C' || map_info->map[r + 1][c] == '0')
	{
		if (map_info->map[r + 1][c] == 'C')
			map_info->count_collectibles -= 1;
		map_info->map[r + 1][c] = '0';
		ft_set_pieces_in_win(map_info);
		map_info->map[r + 1][c] = 'P';
		map_info->map[r][c] = '0';
		map_info->count_player_moves += 1;
		map_info->player_row += 1;
		ft_set_pieces_in_win(map_info);
	}
}

void	ft_move_left(t_map *map_info)
{
	int	r;
	int	c;

	r = map_info->player_row;
	c = map_info->player_col;
	if (map_info->map[r][c - 1] == 'C' || map_info->map[r][c - 1] == '0')
	{
		if (map_info->map[r][c - 1] == 'C')
			map_info->count_collectibles -= 1;
		map_info->map[r][c - 1] = '0';
		ft_set_pieces_in_win(map_info);
		map_info->map[r][c - 1] = 'P';
		map_info->map[r][c] = '0';
		map_info->count_player_moves += 1;
		map_info->player_col -= 1;
		ft_set_pieces_in_win(map_info);
	}
}
