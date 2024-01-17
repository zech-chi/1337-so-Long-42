/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_part_1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:15:54 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:16:12 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_set_pieces_in_win(t_map *map_info)
{
	int	r;
	int	c;

	r = -1;
	while (++r < map_info->rows)
	{
		c = -1;
		while (++c < map_info->cols)
		{
			if (map_info->map[r][c] == '1')
				ft_put_wall_in_win(map_info, r, c);
			else if (map_info->map[r][c] == 'C')
				ft_put_collectible_in_win(map_info, r, c);
			else if (map_info->map[r][c] == 'E')
				ft_put_door_in_win(map_info, r, c, 0);
			else if (map_info->map[r][c] == 'P')
				ft_put_player_in_win(map_info, r, c);
			else if (map_info->map[r][c] == 'X')
				ft_put_enemy_in_win(map_info, map_info->enemy_row,
					map_info->enemy_col);
			else
				ft_put_passage_in_win(map_info, r, c);
		}
	}
}

void	ft_check_if_valid_mlx_info_1(t_map *map_info, int *is_something_wrong)
{
	if (!map_info->wall_img)
	{
		ft_putstr_fd("Error\nsomething wrong with wall_img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->opened_door_img)
	{
		ft_putstr_fd("Error\nsomething wrong with opened_door img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->closed_door_img)
	{
		ft_putstr_fd("Error\nsomething wrong with closed_door img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->player_img)
	{
		ft_putstr_fd("Error\nsomething wrong with wall img path", 2);
		*is_something_wrong = 1;
	}
	ft_check_if_valid_mlx_info_2(map_info, is_something_wrong);
}

void	ft_check_if_valid_mlx_info_2(t_map *map_info, int *is_something_wrong)
{
	if (!map_info->passage_img)
	{
		ft_putstr_fd("Error\nsomething wrong with player img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->enemy1_img)
	{
		ft_putstr_fd("Error\nsomething wrong with enemy 1 img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->enemy2_img)
	{
		ft_putstr_fd("Error\nsomething wrong with enemy 2 img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->enemy3_img)
	{
		ft_putstr_fd("Error\nsomething wrong with enemy 3 img path", 2);
		*is_something_wrong = 1;
	}
	ft_check_if_valid_mlx_info_3(map_info, is_something_wrong);
}

void	ft_check_if_valid_mlx_info_3(t_map *map_info, int *is_something_wrong)
{
	if (!map_info->enemy4_img)
	{
		ft_putstr_fd("Error\nsomething wrong with enemy 4 img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->enemy5_img)
	{
		ft_putstr_fd("Error\nsomething wrong with enemy 5 img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->enemy6_img)
	{
		ft_putstr_fd("Error\nsomething wrong with enemy 6 img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->enemy7_img)
	{
		ft_putstr_fd("Error\nsomething wrong with enemy 7 img path", 2);
		*is_something_wrong = 1;
	}
	ft_check_if_valid_mlx_info_4(map_info, is_something_wrong);
}

void	ft_check_if_valid_mlx_info_4(t_map *map_info, int *is_something_wrong)
{
	if (!map_info->enemy8_img)
	{
		ft_putstr_fd("Error\nsomething wrong with enemy 8 img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->coin1_img)
	{
		ft_putstr_fd("Error\nsomething wrong with coin 1 img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->coin2_img)
	{
		ft_putstr_fd("Error\nsomething wrong with coin 2 img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->coin3_img)
	{
		ft_putstr_fd("Error\nsomething wrong with coin 3 img path", 2);
		*is_something_wrong = 1;
	}
	ft_check_if_valid_mlx_info_5(map_info, is_something_wrong);
}
