/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:49:47 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/10 01:10:40 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnbr(unsigned int u)
{
	if (u < 10)
		ft_putchar('0' + u);
	else
	{
		ft_putnbr(u / 10);
		ft_putnbr(u % 10);
	}
}

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
	if (len < 4)
		return (0);
	if (!ft_strcmp(map_name + len - 4, ".ber"))
		return (1);
	return (0);
}

void	ft_initialize_map_info(t_map *map_info)
{
	map_info->rows = -1;
	map_info->cols = -1;
	map_info->is_rectangular = 1;
	map_info->surrounded_by_walls = 1;
	map_info->count_collectibles = 0;
	map_info->count_map_exit = 0;
	map_info->count_starting_position = 0;
	map_info->player_row = -1;
	map_info->player_col = -1;
	map_info->exit_row = -1;
	map_info->exit_col = -1;
	map_info->have_another_char = 0;
	map_info->can_player_eat_all_collectibles = 1;
	map_info->can_player_exit = 1;
	map_info->count_player_moves = 0;
	map_info->map = NULL;
	map_info->rpxl = 60;
	map_info->cpxl = 60;
}
