/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_part_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:22:51 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/11 17:42:59 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			{
				ft_put_passage_in_win(map_info, r, c);
				ft_put_player_in_win(map_info, r, c);
			}
			else
				ft_put_passage_in_win(map_info, r, c);
		}
	}
}

void	ft_check_if_valid_mlx_info_1(t_map *map_info, int *is_something_wrong)
{
	if (!map_info->wall_img)
	{
		ft_putstr_fd("ERROR: something wrong with wall_img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->coin_img)
	{
		ft_putstr_fd("ERROR: something wrong with coin_img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->opened_door_img)
	{
		ft_putstr_fd("ERROR: something wrong with opened_door img path", 2);
		*is_something_wrong = 1;
	}
}

void	ft_check_if_valid_mlx_info_2(t_map *map_info, int *is_something_wrong)
{
	if (!map_info->closed_door_img)
	{
		ft_putstr_fd("ERROR: something wrong with closed_door img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->player_img)
	{
		ft_putstr_fd("ERROR: something wrong with wall img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->passage_img)
	{
		ft_putstr_fd("ERROR: something wrong with player img path", 2);
		*is_something_wrong = 1;
	}
}

int	ft_fill_mlx_map_info(t_map *map_info)
{
	int	is_something_wrong;

	is_something_wrong = 0;
	map_info->mlx = mlx_init();
	if (!map_info->mlx)
		return (ft_putstr_fd("ERROR: can't initialize mlx", 2), 0);
	map_info->mlx_win = mlx_new_window(map_info->mlx,
			60 * map_info->cols, 60 * map_info->rows, "so_long");
	if (!map_info->mlx_win)
		return (ft_putstr_fd("ERROR: something wrong with mlx_win", 2), 0);
	map_info->wall_img = mlx_xpm_file_to_image(map_info->mlx,
			"textures/wall1.xpm", &(map_info->cpxl), &(map_info->rpxl));
	map_info->coin_img = mlx_xpm_file_to_image(map_info->mlx,
			"textures/coin1.xpm", &(map_info->cpxl), &(map_info->rpxl));
	map_info->opened_door_img = mlx_xpm_file_to_image(map_info->mlx,
			"textures/opened_door_1.xpm", &(map_info->cpxl), &(map_info->rpxl));
	map_info->closed_door_img = mlx_xpm_file_to_image(map_info->mlx,
			"textures/closed_door_1.xpm", &(map_info->cpxl), &(map_info->rpxl));
	map_info->player_img = mlx_xpm_file_to_image(map_info->mlx,
			"textures/player3.xpm", &(map_info->cpxl), &(map_info->rpxl));
	map_info->passage_img = mlx_xpm_file_to_image(map_info->mlx,
			"textures/passage.xpm", &(map_info->cpxl), &(map_info->rpxl));
	ft_check_if_valid_mlx_info_1(map_info, &is_something_wrong);
	ft_check_if_valid_mlx_info_2(map_info, &is_something_wrong);
	return (is_something_wrong);
}
