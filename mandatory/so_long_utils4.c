/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:48:14 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 18:07:35 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_is_valid_map_name(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 4)
		return (0);
	if (!ft_strcmp(map_name + len - 4, ".ber"))
		return (1);
	return (0);
}

void	ft_initialize_map_info(t_map *map_info)
{
	map_info->rows = -1;
	map_info->cols = -1;
	map_info->is_rectangular = 1;
	map_info->surrounded_by_walls = 1;
	map_info->count_collectibles = 0;
	map_info->count_map_exit = 0;
	map_info->count_starting_position = 0;
	map_info->player_row = -1;
	map_info->player_col = -1;
	map_info->exit_row = -1;
	map_info->exit_col = -1;
	map_info->have_another_char = 0;
	map_info->can_player_eat_all_collectibles = 1;
	map_info->can_player_exit = 1;
	map_info->count_player_moves = 0;
	map_info->rpxl = 60;
	map_info->cpxl = 60;
	map_info->mlx = NULL;
	map_info->mlx_win = NULL;
	map_info->passage_img = NULL;
	map_info->wall_img = NULL;
	map_info->coin_img = NULL;
	map_info->opened_door_img = NULL;
	map_info->closed_door_img = NULL;
	map_info->player_img = NULL;
}

int	ft_is_valid_map_part1(t_map map_details)
{
	int	is_something_worng;

	is_something_worng = 0;
	if (map_details.cols == map_details.rows || (!map_details.is_rectangular))
	{
		ft_putstr_fd("Error\nThe map must be rectangular!", 2);
		is_something_worng = 1;
	}
	if (!map_details.surrounded_by_walls)
	{
		ft_putstr_fd("Error\nThe map must be closed/surrounded by walls!", 2);
		is_something_worng = 1;
	}
	if (!map_details.count_collectibles)
	{
		ft_putstr_fd("Error\nThe map must contain at least 1 collectible!", 2);
		is_something_worng = 1;
	}
	if (map_details.count_map_exit != 1)
	{
		ft_putstr_fd("Error\nThe map must contain 1 exit!", 2);
		is_something_worng = 1;
	}
	return (is_something_worng == 0);
}

int	ft_is_valid_map_part2(t_map map_details)
{
	int	is_something_worng;

	is_something_worng = 0;
	if (map_details.count_starting_position != 1)
	{
		ft_putstr_fd("Error\nThe map must contain 1 starting position!", 2);
		is_something_worng = 1;
	}
	if (map_details.have_another_char)
	{
		ft_putstr_fd("Error\nThe map must contain 0, 1, C, E and P!", 2);
		is_something_worng = 1;
	}
	if (map_details.rows > 23 || map_details.cols > 42)
	{
		ft_putstr_fd("Error\nbe kind! and give a small map y<=23 and x<=42", 2);
		is_something_worng = 1;
	}
	return (is_something_worng == 0);
}

int	ft_is_valid_map_part3(t_map map_details)
{
	int	is_something_worng;

	is_something_worng = 0;
	if (!map_details.can_player_eat_all_collectibles)
	{
		ft_putstr_fd("Error\nthe player can't eat all collectibles!", 2);
		is_something_worng = 1;
	}
	if (!map_details.can_player_exit)
	{
		ft_putstr_fd("Error\nthe player can't exit", 2);
		is_something_worng = 1;
	}
	return (is_something_worng == 0);
}
