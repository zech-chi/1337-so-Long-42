/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:15:49 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/08 20:42:52 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map_info(t_map map_details);
void	ft_print_map(char **map, int rows);

void	ft_leaks(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_map	map_info;
	int		fd;

	atexit(ft_leaks);
	if (ac != 2 || !ft_is_valid_map_name(av[1]))
		return (0);
	map_info = (t_map){-1, -1, 1, 1, 0, 0, 0, -1, -1, -1, -1, 0, 1, 1, NULL};
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || !ft_check_map_is_valid(&map_info, fd))
		return (ft_clear_map(map_info.map), 0);
	ft_print_map_info(map_info);
	ft_clear_map(map_info.map);
	return (0);
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
