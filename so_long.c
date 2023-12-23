/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:15:49 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/23 10:52:04 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_leaks(void)
{
	system("leaks a.out");
}

int	main(void)
{
	t_map	map_details;
	int		fd;
	t_list	*head;

	atexit(ft_leaks);
	map_details = (t_map){-1, -1, 1, 1, 0, 0, 0, -1, -1, -1, -1, 0, 1, 1, NULL};
	fd = open("map.ber", O_RDONLY);
	head = ft_read_file(fd, &map_details);
	map_details.map = ft_create_map(&head, map_details);
	ft_lstclear(&head);
	if (!map_details.map)
		return (0);
	ft_print_map_info(map_details);
	if (!ft_is_valid_map_part1(map_details) || !ft_is_valid_map_part2(map_details, 0))
		return (ft_clear_map(map_details.map), 0);
	if (!ft_can_eat_and_exit(&map_details))
		return (ft_clear_map(map_details.map), 0);
	ft_is_valid_map_part2(map_details, 1);
	ft_clear_map(map_details.map);
	return (0);
}
