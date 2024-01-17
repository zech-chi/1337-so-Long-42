/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_part_4_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:18:09 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:18:26 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_destroy_enemy_imgs(t_map *map_info)
{
	if (map_info->enemy1_img)
		mlx_destroy_image(map_info->mlx, map_info->enemy1_img);
	if (map_info->enemy2_img)
		mlx_destroy_image(map_info->mlx, map_info->enemy2_img);
	if (map_info->enemy3_img)
		mlx_destroy_image(map_info->mlx, map_info->enemy3_img);
	if (map_info->enemy4_img)
		mlx_destroy_image(map_info->mlx, map_info->enemy4_img);
	if (map_info->enemy5_img)
		mlx_destroy_image(map_info->mlx, map_info->enemy5_img);
	if (map_info->enemy6_img)
		mlx_destroy_image(map_info->mlx, map_info->enemy6_img);
	if (map_info->enemy7_img)
		mlx_destroy_image(map_info->mlx, map_info->enemy7_img);
	if (map_info->enemy8_img)
		mlx_destroy_image(map_info->mlx, map_info->enemy8_img);
}

void	ft_destroy_coin_imgs(t_map *map_info)
{
	if (map_info->coin1_img)
		mlx_destroy_image(map_info->mlx, map_info->coin1_img);
	if (map_info->coin2_img)
		mlx_destroy_image(map_info->mlx, map_info->coin2_img);
	if (map_info->coin3_img)
		mlx_destroy_image(map_info->mlx, map_info->coin3_img);
	if (map_info->coin4_img)
		mlx_destroy_image(map_info->mlx, map_info->coin4_img);
	if (map_info->coin5_img)
		mlx_destroy_image(map_info->mlx, map_info->coin5_img);
	if (map_info->coin6_img)
		mlx_destroy_image(map_info->mlx, map_info->coin6_img);
	if (map_info->coin7_img)
		mlx_destroy_image(map_info->mlx, map_info->coin7_img);
	if (map_info->coin8_img)
		mlx_destroy_image(map_info->mlx, map_info->coin8_img);
	if (map_info->coin9_img)
		mlx_destroy_image(map_info->mlx, map_info->coin9_img);
}

int	ft_free_mlx_business(t_map *map_info)
{
	if (map_info->mlx)
	{
		if (map_info->wall_img)
			mlx_destroy_image(map_info->mlx, map_info->wall_img);
		if (map_info->opened_door_img)
			mlx_destroy_image(map_info->mlx, map_info->opened_door_img);
		if (map_info->closed_door_img)
			mlx_destroy_image(map_info->mlx, map_info->closed_door_img);
		if (map_info->player_img)
			mlx_destroy_image(map_info->mlx, map_info->player_img);
		if (map_info->passage_img)
			mlx_destroy_image(map_info->mlx, map_info->passage_img);
		if (map_info->mlx_win)
			mlx_destroy_window(map_info->mlx, map_info->mlx_win);
		ft_destroy_enemy_imgs(map_info);
		ft_destroy_coin_imgs(map_info);
	}
	ft_clear_map(map_info->map);
	return (exit(5), 0);
}
