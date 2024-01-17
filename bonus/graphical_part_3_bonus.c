/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_part_3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:17:32 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:17:54 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_if_valid_mlx_info_5(t_map *map_info, int *is_something_wrong)
{
	if (!map_info->coin4_img)
	{
		ft_putstr_fd("Error\nsomething wrong with coin 4 img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->coin5_img)
	{
		ft_putstr_fd("Error\nsomething wrong with coin 5 img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->coin6_img)
	{
		ft_putstr_fd("Error\nsomething wrong with coin 6 img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->coin7_img)
	{
		ft_putstr_fd("Error\nsomething wrong with coin 7 img path", 2);
		*is_something_wrong = 1;
	}
	ft_check_if_valid_mlx_info_6(map_info, is_something_wrong);
}

void	ft_check_if_valid_mlx_info_6(t_map *map_info, int *is_something_wrong)
{
	if (!map_info->coin8_img)
	{
		ft_putstr_fd("Error\nsomething wrong with coin 8 img path", 2);
		*is_something_wrong = 1;
	}
	if (!map_info->coin9_img)
	{
		ft_putstr_fd("Error\nsomething wrong with coin 9 img path", 2);
		*is_something_wrong = 1;
	}
}

void	ft_fill_mlx_map_info_2(t_map *map_info)
{
	map_info->enemy1_img = mlx_xpm_file_to_image(map_info->mlx,
			ENEMY1_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->enemy2_img = mlx_xpm_file_to_image(map_info->mlx,
			ENEMY2_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->enemy3_img = mlx_xpm_file_to_image(map_info->mlx,
			ENEMY3_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->enemy4_img = mlx_xpm_file_to_image(map_info->mlx,
			ENEMY4_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->enemy5_img = mlx_xpm_file_to_image(map_info->mlx,
			ENEMY5_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->enemy6_img = mlx_xpm_file_to_image(map_info->mlx,
			ENEMY6_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->enemy7_img = mlx_xpm_file_to_image(map_info->mlx,
			ENEMY7_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->enemy8_img = mlx_xpm_file_to_image(map_info->mlx,
			ENEMY8_IMG, &(map_info->cpxl), &(map_info->rpxl));
}

void	ft_fill_mlx_map_info_3(t_map *map_info)
{
	map_info->coin1_img = mlx_xpm_file_to_image(map_info->mlx,
			COIN1_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->coin2_img = mlx_xpm_file_to_image(map_info->mlx,
			COIN2_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->coin3_img = mlx_xpm_file_to_image(map_info->mlx,
			COIN3_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->coin4_img = mlx_xpm_file_to_image(map_info->mlx,
			COIN4_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->coin5_img = mlx_xpm_file_to_image(map_info->mlx,
			COIN5_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->coin6_img = mlx_xpm_file_to_image(map_info->mlx,
			COIN6_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->coin7_img = mlx_xpm_file_to_image(map_info->mlx,
			COIN7_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->coin8_img = mlx_xpm_file_to_image(map_info->mlx,
			COIN8_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->coin9_img = mlx_xpm_file_to_image(map_info->mlx,
			COIN9_IMG, &(map_info->cpxl), &(map_info->rpxl));
}

int	ft_fill_mlx_map_info(t_map *map_info)
{
	int	is_something_wrong;

	is_something_wrong = 0;
	map_info->mlx = mlx_init();
	if (!map_info->mlx)
		return (ft_putstr_fd("Error\ncan't initialize mlx", 2), 0);
	map_info->mlx_win = mlx_new_window(map_info->mlx,
			60 * map_info->cols, 60 * map_info->rows, "so_long");
	if (!map_info->mlx_win)
		return (ft_putstr_fd("Error\nsomething wrong with mlx_win", 2), 0);
	map_info->wall_img = mlx_xpm_file_to_image(map_info->mlx,
			WALL_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->opened_door_img = mlx_xpm_file_to_image(map_info->mlx,
			OPENED_DOOR_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->closed_door_img = mlx_xpm_file_to_image(map_info->mlx,
			CLOSED_DOOR_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->player_img = mlx_xpm_file_to_image(map_info->mlx,
			PLAYER_IMG, &(map_info->cpxl), &(map_info->rpxl));
	map_info->passage_img = mlx_xpm_file_to_image(map_info->mlx,
			PASSAGE_IMG, &(map_info->cpxl), &(map_info->rpxl));
	ft_fill_mlx_map_info_2(map_info);
	ft_fill_mlx_map_info_3(map_info);
	ft_check_if_valid_mlx_info_1(map_info, &is_something_wrong);
	return (!is_something_wrong);
}
