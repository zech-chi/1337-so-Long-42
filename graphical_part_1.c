/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphical_part_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 00:22:51 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/10 00:30:50 by zech-chi         ###   ########.fr       */
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
				mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
					map_info->wall_img, map_info->cpxl * c, map_info->rpxl * r);
			else if (map_info->map[r][c] == 'C')
				mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
					map_info->coin_img, map_info->cpxl * c, map_info->rpxl * r);
			else if (map_info->map[r][c] == 'E')
				mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
					map_info->exit_img, map_info->cpxl * c, map_info->rpxl * r);
			else if (map_info->map[r][c] == 'P')
				mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
					map_info->player_img, map_info->cpxl * c, map_info->rpxl * r);
			else
				mlx_put_image_to_window(map_info->mlx, map_info->mlx_win,
					map_info->passage_img, map_info->cpxl * c, map_info->rpxl * r);
		}
	}
}

void	ft_fill_mlx_map_info(t_map *map_info)
{
	map_info->mlx = mlx_init();
	map_info->mlx_win = mlx_new_window(map_info->mlx,
			60 * map_info->cols, 60 * map_info->rows, "so_long");
	map_info->wall_img = mlx_xpm_file_to_image(map_info->mlx,
			"textures/wall2.xpm", &(map_info->cpxl), &(map_info->rpxl));
	map_info->coin_img = mlx_xpm_file_to_image(map_info->mlx,
			"textures/coin1.xpm", &(map_info->cpxl), &(map_info->rpxl));
	map_info->exit_img = mlx_xpm_file_to_image(map_info->mlx,
			"textures/exit1.xpm", &(map_info->cpxl), &(map_info->rpxl));
	map_info->player_img = mlx_xpm_file_to_image(map_info->mlx,
			"textures/player.xpm", &(map_info->cpxl), &(map_info->rpxl));
	map_info->passage_img = mlx_xpm_file_to_image(map_info->mlx,
			"textures/passage.xpm", &(map_info->cpxl), &(map_info->rpxl));
}
