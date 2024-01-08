/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:15:49 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/08 20:10:59 by zech-chi         ###   ########.fr       */
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
	t_list	*gc;

	atexit(ft_leaks);
	if (ac != 2 || !ft_is_valid_map_name(av[1]))
		return (0);
	map_info = (t_map){-1, -1, 1, 1, 0, 0, 0, -1, -1, -1, -1, 0, 1, 1, NULL};
	fd = open(av[1], O_RDONLY);
	if (fd == -1 || !ft_check_map_is_valid(&map_info, fd))
		return (0);
	ft_clear_map(map_info.map);
	ft_print_map_info(map_info);
	return (0);
}
