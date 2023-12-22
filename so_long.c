/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:15:49 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/22 11:52:17 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"



int	main(void)
{
	t_map	map_details;
	int		fd;

	map_details = (t_map){-1, -1, 1, 1, 0, 0, 0, -1, -1, -1, -1, 0, 1, 1, NULL};
	fd = open("map.ber", O_RDONLY);
	ft_print_map_info(map_details);
	ft_read_file(fd, &map_details);
	ft_print_map_info(map_details);
	ft_is_valid_map_part1(map_details);
	ft_is_valid_map_part2(map_details, 0);
	return (0);
}
