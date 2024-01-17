/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils4_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:25:33 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:25:56 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_initialize_map_info_2(t_map *map_info)
{
	map_info->coin1_img = NULL;
	map_info->coin2_img = NULL;
	map_info->coin3_img = NULL;
	map_info->coin4_img = NULL;
	map_info->coin5_img = NULL;
	map_info->coin6_img = NULL;
	map_info->coin7_img = NULL;
	map_info->coin8_img = NULL;
	map_info->coin9_img = NULL;
	map_info->player_img = NULL;
	map_info->enemy1_img = NULL;
	map_info->enemy2_img = NULL;
	map_info->enemy3_img = NULL;
	map_info->enemy4_img = NULL;
	map_info->enemy5_img = NULL;
	map_info->enemy6_img = NULL;
	map_info->enemy7_img = NULL;
	map_info->enemy8_img = NULL;
	map_info->count_enemy = 0;
	map_info->enemy_row = -1;
	map_info->enemy_col = -1;
	map_info->cur_enemy_img = 0;
	map_info->cur_frame = 0;
	map_info->reset_coin = 0;
	map_info->reset_door = 0;
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
	map_info->rpxl = 60;
	map_info->cpxl = 60;
	map_info->mlx = NULL;
	map_info->mlx_win = NULL;
	map_info->passage_img = NULL;
	map_info->wall_img = NULL;
	map_info->opened_door_img = NULL;
	map_info->closed_door_img = NULL;
	map_info->cur_coin_img = 0;
	ft_initialize_map_info_2(map_info);
}

int	len_of_number(long long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len += 1;
	}
	while (n)
	{
		len += 1;
		n /= 10;
	}
	return (len);
}

char	*fill(char *ptr, long long ln, int size)
{
	int	i;

	if (ln == 0)
	{
		ptr[0] = '0';
		ptr[1] = 0;
		return (ptr);
	}
	if (ln < 0)
	{
		ptr[0] = '-';
		ln *= -1;
	}
	i = size - 1;
	while (ln)
	{
		ptr[i] = '0' + ln % 10;
		ln /= 10;
		i--;
	}
	ptr[size] = 0;
	return (ptr);
}

char	*ft_itoa(int n)
{
	int			size;
	long long	ln;
	char		*ptr;

	ln = (long long)n;
	size = len_of_number(ln);
	ptr = malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	fill(ptr, ln, size);
	return (ptr);
}
