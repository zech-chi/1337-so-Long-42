/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_part_5_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:18:38 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:18:55 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_collectible_in_win_continue(t_map *map_info, int r, int c)
{
	if (map_info->cur_coin_img == 6)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->coin7_img, map_info->cpxl * c, map_info->rpxl * r);
	if (map_info->cur_coin_img == 7)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->coin8_img, map_info->cpxl * c, map_info->rpxl * r);
	if (map_info->cur_coin_img == 8)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->coin9_img, map_info->cpxl * c, map_info->rpxl * r);
}

void	ft_put_collectible_in_win(t_map *map_info, int r, int c)
{
	ft_put_passage_in_win(map_info, r, c);
	if (map_info->cur_coin_img == 0)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->coin1_img, map_info->cpxl * c, map_info->rpxl * r);
	if (map_info->cur_coin_img == 1)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->coin2_img, map_info->cpxl * c, map_info->rpxl * r);
	if (map_info->cur_coin_img == 2)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->coin3_img, map_info->cpxl * c, map_info->rpxl * r);
	if (map_info->cur_coin_img == 3)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->coin4_img, map_info->cpxl * c, map_info->rpxl * r);
	if (map_info->cur_coin_img == 4)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->coin5_img, map_info->cpxl * c, map_info->rpxl * r);
	if (map_info->cur_coin_img == 5)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->coin6_img, map_info->cpxl * c, map_info->rpxl * r);
	ft_put_collectible_in_win_continue(map_info, r, c);
}

void	ft_put_enemy_in_win_continue(t_map *map_info, int r, int c)
{
	if (map_info->cur_enemy_img == 5)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->enemy6_img, map_info->cpxl * c, map_info->rpxl * r);
	if (map_info->cur_enemy_img == 6)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->enemy7_img, map_info->cpxl * c, map_info->rpxl * r);
	if (map_info->cur_enemy_img == 7)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->enemy8_img, map_info->cpxl * c, map_info->rpxl * r);
	map_info->cur_enemy_img = (map_info->cur_enemy_img + 1) % 8;
}

void	ft_put_enemy_in_win(t_map *map_info, int r, int c)
{
	ft_put_passage_in_win(map_info, map_info->enemy_row, map_info->enemy_col);
	if (map_info->cur_enemy_img == 0)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->enemy1_img, map_info->cpxl * c, map_info->rpxl * r);
	if (map_info->cur_enemy_img == 1)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->enemy2_img, map_info->cpxl * c, map_info->rpxl * r);
	if (map_info->cur_enemy_img == 2)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->enemy3_img, map_info->cpxl * c, map_info->rpxl * r);
	if (map_info->cur_enemy_img == 3)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->enemy4_img, map_info->cpxl * c, map_info->rpxl * r);
	if (map_info->cur_enemy_img == 4)
		mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
			map_info->enemy5_img, map_info->cpxl * c, map_info->rpxl * r);
	ft_put_enemy_in_win_continue(map_info, r, c);
}
