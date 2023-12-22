/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:05:42 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/22 10:35:28 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

int	ft_is_valid_map_part1(t_map map_details)
{
	int	is_something_worng;

	is_something_worng = 0;
	if (map_details.cols == map_details.rows || (!map_details.is_rectangular))
	{
		ft_putstr_fd("The map must be rectangular!", 2);
		is_something_worng = 1;
	}
	if (!map_details.surrounded_by_walls)
	{
		ft_putstr_fd("The map must be closed/surrounded by walls!", 2);
		is_something_worng = 1;
	}
	if (!map_details.count_collectibles)
	{
		ft_putstr_fd("The map must contain at least 1 collectible!", 2);
		is_something_worng = 1;
	}
	if (map_details.count_map_exit != 1)
	{
		ft_putstr_fd("The map must contain 1 exit!", 2);
		is_something_worng = 1;
	}
	return (is_something_worng);
}

int	ft_is_valid_map_part2(t_map map_details, int check_path)
{
	int	is_something_worng;

	is_something_worng = 0;
	if (!check_path && map_details.count_starting_position != 1)
	{
		ft_putstr_fd("The map must contain 1 starting position!", 2);
		is_something_worng = 1;
	}
	if (!check_path && map_details.have_another_char)
	{
		ft_putstr_fd("The map must contain 0, 1, C, E and P!", 2);
		is_something_worng = 1;
	}
	if (check_path && !map_details.can_player_eat_all_collectibles)
	{
		ft_putstr_fd("the player can't eat all collectibkes!", 2);
		is_something_worng = 1;
	}
	if (check_path && !map_details.can_player_exit)
	{
		ft_putstr_fd("the player can't exit", 2);
		is_something_worng = 1;
	}
	return (is_something_worng);
}
