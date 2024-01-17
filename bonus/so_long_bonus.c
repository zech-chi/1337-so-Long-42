/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:22:02 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:22:25 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_animate_enemy_coin(t_map *map_info)
{
	int	r;
	int	c;

	ft_put_enemy_in_win(map_info, map_info->enemy_row, map_info->enemy_col);
	r = -1;
	while (++r < map_info->rows)
	{
		c = -1;
		while (++c < map_info->cols)
		{
			if (map_info->map[r][c] == 'C')
				ft_put_collectible_in_win(map_info, r, c);
		}
	}
}

void	ft_check_reset_coin_door(t_map *map_info)
{
	if (map_info->reset_coin)
	{
		ft_put_collectible_in_win(map_info, map_info->enemy_row,
			map_info->enemy_col);
		map_info->map[map_info->enemy_row][map_info->enemy_col] = 'C';
		map_info->reset_coin = 0;
	}
	else if (map_info->reset_door)
	{
		ft_put_door_in_win(map_info, map_info->enemy_row, map_info->enemy_col,
			map_info->count_collectibles == 0);
		map_info->map[map_info->enemy_row][map_info->enemy_col] = 'E';
		map_info->reset_door = 0;
	}
	else
	{
		ft_put_passage_in_win(map_info, map_info->enemy_row,
			map_info->enemy_col);
		map_info->map[map_info->enemy_row][map_info->enemy_col] = '0';
	}
}

void	ft_update_enemy_coordinates(char *path, t_map *map_info)
{
	if (path[0] == 'u')
		map_info->enemy_row--;
	else if (path[0] == 'r')
		map_info->enemy_col++;
	else if (path[0] == 'd')
		map_info->enemy_row++;
	else if (path[0] == 'l')
		map_info->enemy_col--;
}

int	ft_render_next_frame(t_map *map_info)
{
	char	*path;

	ft_check_if_the_game_end(map_info);
	if (map_info->cur_frame % 1000 == 0)
		ft_animate_enemy_coin(map_info);
	if (map_info->cur_frame % (180000 / (map_info->cols + map_info->rows)) == 0)
	{
		path = ft_enemy_path_to_player(map_info);
		if (!path)
			ft_free_mlx_business(map_info);
		ft_check_reset_coin_door(map_info);
		ft_update_enemy_coordinates(path, map_info);
		ft_put_enemy_in_win(map_info, map_info->enemy_row, map_info->enemy_col);
		if (map_info->map[map_info->enemy_row][map_info->enemy_col] == 'C')
			map_info->reset_coin = 1;
		if (map_info->map[map_info->enemy_row][map_info->enemy_col] == 'E')
			map_info->reset_door = 1;
		map_info->map[map_info->enemy_row][map_info->enemy_col] = 'X';
		free(path);
	}
	map_info->cur_coin_img = (map_info->cur_coin_img + 1) % 9;
	map_info->cur_frame++;
	if (map_info->cur_frame == 2147483647)
		map_info->cur_frame = 0;
	return (0);
}

int	main(int ac, char **av)
{
	t_map	map_info;
	int		fd;

	if (ac != 2)
		return (ft_putstr_fd("Error\nenter a path of map", 2), 0);
	if (!ft_is_valid_map_name(av[1]))
		return (ft_putstr_fd("Error\ninvalid file name", 2), 0);
	ft_initialize_map_info(&map_info);
	map_info.map = NULL;
	map_info.player_img = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error\nsomething wrong with you're file", 2), 0);
	if (!ft_check_map_is_valid(&map_info, fd))
		return (close(fd), 0);
	close(fd);
	if (!ft_fill_mlx_map_info(&map_info))
		ft_free_mlx_business(&map_info);
	ft_set_pieces_in_win(&map_info);
	mlx_hook(map_info.mlx_win, 2, 0, &ft_get_pressed_key, &map_info);
	mlx_hook(map_info.mlx_win, 17, 0, &ft_free_mlx_business, &map_info);
	mlx_loop_hook(map_info.mlx, &ft_render_next_frame, &map_info);
	mlx_loop(map_info.mlx);
	return (ft_free_mlx_business(&map_info), 0);
}
