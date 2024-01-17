/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils1_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:23:46 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:24:03 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		ft_putstr_fd("Error\nThe map must contain 0, 1, C, E, P and X!", 2);
		is_something_worng = 1;
	}
	if (map_details.rows > 23 || map_details.cols > 42)
	{
		ft_putstr_fd("Error\nbe kind! and give a small map y<=23 and x<=42", 2);
		is_something_worng = 1;
	}
	if (map_details.count_enemy != 1)
	{
		ft_putstr_fd("Error\nThe map must contain 1 enemy", 2);
		is_something_worng = 1;
	}
	return (is_something_worng == 0);
}

int	ft_is_valid_map_part3(t_map *map_details)
{
	int		is_something_worng;
	char	*path;

	is_something_worng = 0;
	if (!map_details->can_player_eat_all_collectibles)
	{
		ft_putstr_fd("Error\nthe player can't eat all collectibles!", 2);
		is_something_worng = 1;
	}
	if (!map_details->can_player_exit)
	{
		ft_putstr_fd("Error\nthe player can't exit", 2);
		is_something_worng = 1;
	}
	path = ft_enemy_path_to_player(map_details);
	if (!path)
	{
		ft_putstr_fd("Error\nthe enemy can't get the player", 2);
		is_something_worng = 1;
	}
	else
		free(path);
	return (is_something_worng == 0);
}

void	ft_help_line_scanner(t_map *map_details, int r, int *c, char k)
{
	if (k == 'e')
	{
		(*map_details).exit_row = r;
		(*map_details).exit_col = *c;
	}
	else if (k == 'p')
	{
		(*map_details).player_row = r;
		(*map_details).player_col = *c;
	}
	else if (k == 'x')
	{
		(*map_details).enemy_row = r;
		(*map_details).enemy_col = *c;
	}
}

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
			ft_help_line_scanner(map_details, r, c, 'e');
		else if (line[*c] == 'P' && ++(*map_details).count_starting_position)
			ft_help_line_scanner(map_details, r, c, 'p');
		else if (line[*c] == 'X' && ++(*map_details).count_enemy)
			ft_help_line_scanner(map_details, r, c, 'x');
		else if (line[*c] != '0' && line[*c] != '1')
			(*map_details).have_another_char = 1;
		(*c)++;
	}
	if ((*map_details).cols == -1)
		(*map_details).cols = *c;
	else if ((*map_details).cols != *c)
		(*map_details).is_rectangular = 0;
}
