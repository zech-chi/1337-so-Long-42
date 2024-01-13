/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 19:26:39 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/12 22:23:38 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_mlx_business(t_map *map_info)
{
	if (map_info->mlx && map_info->mlx_win)
	{
		if (map_info->wall_img)
			mlx_destroy_image(map_info->mlx, map_info->wall_img);
		if (map_info->coin_img)
			mlx_destroy_image(map_info->mlx, map_info->coin_img);
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
		free(map_info->mlx);
	}
	if (map_info->mlx_win)
		mlx_destroy_window(map_info->mlx, map_info->mlx_win);
	exit(4);
}
