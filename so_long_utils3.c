/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:49:47 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/08 20:10:36 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_is_valid_map_name(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len < 5)
		return (0);
	if (!ft_strcmp(map_name + len - 4, ".ber") && map_name[len - 5] != '/')
		return (1);
	return (0);
}

int	ft_check_map_is_valid(t_map *map_info, int fd)
{
	t_list	*map_list;

	map_list = ft_read_file(fd, map_info);
	map_info->map = ft_create_map(&map_list, *map_info);
	ft_lstclear(&map_list);
	if (!map_info->map)
		return (0);
	if (!ft_is_valid_map_part1(*map_info)
		|| !ft_is_valid_map_part2(*map_info, 0))
		return (ft_clear_map(map_info->map), 0);
	if (!ft_can_eat_and_exit(map_info))
		return (ft_clear_map(map_info->map), 0);
	ft_is_valid_map_part2(*map_info, 1);
	return (1);
}
