/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:21:11 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:21:40 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	ft_check_if_the_game_end(t_map *map_info)
{
	if (map_info->player_row == map_info->enemy_row
		&& map_info->player_col == map_info->enemy_col)
	{
		ft_putstr("you lose :(\n");
		ft_free_mlx_business(map_info);
	}
	if (map_info->player_row == map_info->exit_row
		&& map_info->player_col == map_info->exit_col)
	{
		if (map_info->count_collectibles == 0)
		{
			ft_putstr("\nyou win 🎉🏆🥇\n");
			ft_free_mlx_business(map_info);
		}
	}
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

void	ft_move2(t_map *map_info, int dr, int dc, char **str)
{
	ft_put_wall_in_win(map_info, 0, 0);
	mlx_string_put(map_info->mlx, map_info->mlx_win, 0, 0, 16777215, *str);
	free(*str);
	ft_move_player(map_info, dr, dc);
}

void	ft_move(t_map *map_info, int dr, int dc)
{
	int		r;
	int		c;
	char	*str;

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
				ft_put_door_in_win(map_info, map_info->exit_row,
					map_info->exit_col, 1);
		}
		map_info->count_player_moves += 1;
		str = ft_itoa(map_info->count_player_moves);
		if (!str)
			ft_free_mlx_business(map_info);
		ft_move2(map_info, dr, dc, &str);
	}
}
