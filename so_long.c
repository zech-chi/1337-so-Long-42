/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:15:49 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/09 19:24:47 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <mlx.h>
void	ft_print_map_info(t_map map_details);
void	ft_print_map(char **map, int rows);

void	ft_leaks(void)
{
	system("leaks so_long");
}

void	ft_set_pieces_in_win(void *mlx, void *mlx_win, t_map map_info)
{
	int	rpxl;
	int	cpxl;
	int	r;
	int	c;
	void	*wall;
	void	*coin;
	void	*exit_e;
	void	*player;

	rpxl = 60;
	cpxl = 60;
	r = -1;
	wall = mlx_xpm_file_to_image(mlx, "textures/wall2.xpm", &cpxl, &rpxl);
	coin = mlx_xpm_file_to_image(mlx, "textures/coin1.xpm", &cpxl, &rpxl);
	exit_e = mlx_xpm_file_to_image(mlx, "textures/exit1.xpm", &cpxl, &rpxl);
	player = mlx_xpm_file_to_image(mlx, "textures/player.xpm", &cpxl, &rpxl);

	while (++r < map_info.rows)
	{
		c = -1;
		
		while (++c < map_info.cols)
		{
			if (map_info.map[r][c] == '1')
				mlx_put_image_to_window(mlx, mlx_win, wall, cpxl * c, rpxl * r);
			else if (map_info.map[r][c] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, coin, cpxl * c, rpxl * r);
			else if (map_info.map[r][c] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, exit_e, cpxl * c, rpxl * r);
			else if (map_info.map[r][c] == 'P')
				mlx_put_image_to_window(mlx, mlx_win, player, cpxl * c, rpxl * r);

		}
	}
}

int	main(int ac, char **av)
{
	t_map	map_info;
	int		fd;

	//atexit(ft_leaks);
	if (ac != 2 || !ft_is_valid_map_name(av[1]))
		return (0);
	map_info = (t_map){-1, -1, 1, 1, 0, 0, 0, -1, -1, -1, -1, 0, 1, 1, NULL};
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || !ft_check_map_is_valid(&map_info, fd))
		return (ft_clear_map(map_info.map), 0);
	/// graphical part
	void	*mlx;
	void	*mlx_win;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 60 * map_info.cols, 60 * map_info.rows, "so+_+long");
	ft_set_pieces_in_win(mlx, mlx_win, map_info);
	mlx_loop(mlx);
	//ft_print_map_info(map_info);
	ft_clear_map(map_info.map);
	return (close(fd), 0);
}


void	ft_print_map_info(t_map map_details)
{
	printf("------------------------------------------------------------\n");
	printf("cols : %d\n", map_details.cols);
	printf("rows : %d\n", map_details.rows);
	printf("is_rectangular : %d\n", map_details.is_rectangular);
	printf("surrounded_by_walls : %d\n", map_details.surrounded_by_walls);
	printf("count_collectibles : %d\n", map_details.count_collectibles);
	printf("count_map_exit : %d\n", map_details.count_map_exit);
	printf("count_starting_position : %d\n",
	map_details.count_starting_position);
	printf("player_row : %d\n", map_details.player_row);
	printf("player_col : %d\n", map_details.player_col);
	printf("exit_row : %d\n", map_details.exit_row);
	printf("exit_col : %d\n", map_details.exit_col);
	printf("have_another_char : %d\n", map_details.have_another_char);
	printf("can_player_eat_all_collectibles : %d\n",
	map_details.can_player_eat_all_collectibles);
	printf("can_player_exit : %d\n", map_details.can_player_exit);
	printf("map: \n");
	int r = -1;
	while (++r < map_details.rows)
	{
		printf("%s", map_details.map[r]);
	}
	printf("\n-------------------------------------------------------------\n");
}

void	ft_print_map(char **map, int rows)
{
	int	r;

	r = -1;
	while (++r < rows)
		printf("%s", map[r]);
	printf("\n---------------------------------------\n");
}



/*
mlx_init
mlx_loop
*/