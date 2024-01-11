/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_part_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 17:09:58 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/11 17:12:05 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_put_passage_in_win(t_map *map_info, int r, int c)
{
	mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
		map_info->passage_img, map_info->cpxl * c, map_info->rpxl * r);
}

void	ft_put_wall_in_win(t_map *map_info, int r, int c)
{
	ft_put_passage_in_win(map_info, r, c);
	mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
		map_info->wall_img, map_info->cpxl * c, map_info->rpxl * r);
}

void	ft_put_collectible_in_win(t_map *map_info, int r, int c)
{
	ft_put_passage_in_win(map_info, r, c);
	mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
		map_info->coin_img, map_info->cpxl * c, map_info->rpxl * r);
}

void	ft_put_door_in_win(t_map *map_info, int r, int c, int opened)
{
	ft_put_passage_in_win(map_info, r, c);
	if (opened)
	{
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->opened_door_img, map_info->cpxl * c, map_info->rpxl * r);
	}
	else
	{
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->closed_door_img, map_info->cpxl * c, map_info->rpxl * r);
	}
}

void	ft_put_player_in_win(t_map *map_info, int r, int c)
{
	mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
		map_info->player_img, map_info->cpxl * c, map_info->rpxl * r);
}
