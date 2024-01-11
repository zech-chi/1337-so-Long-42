/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:15:49 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/11 18:30:23 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_leaks(void)
{
	system("leaks so_long");
}

int	main(int ac, char **av)
{
	t_map	map_info;
	int		fd;

	if (ac != 2 || !ft_is_valid_map_name(av[1]))
		return (0);
	ft_initialize_map_info(&map_info);
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || !ft_check_map_is_valid(&map_info, fd))
		return (close(fd), ft_clear_map(map_info.map), 0);
	close(fd);
	if (ft_fill_mlx_map_info(&map_info))
		return (ft_clear_map(map_info.map), 0);
	ft_set_pieces_in_win(&map_info);
	mlx_hook(map_info.mlx_win, 2, 0, &ft_get_pressed_key, &map_info);
	mlx_loop(map_info.mlx);
	ft_clear_map(map_info.map);
	return (0);
}
