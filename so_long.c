/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:15:49 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/23 10:46:35 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_leaks(void)
{
	system("leaks a.out");
}

void	ft_print_map(char **map, int rows)
{
	int	r;

	r = -1;
	while (++r < rows)
		printf("%s", map[r]);
	printf("\n---------------------------------------\n");
}

void	ft_flood_fill(char **map, t_map map_details, int r, int c)
{
	int	directions[4][2];
	int	nr;
	int	nc;
	int	i;

	directions[0][0] = 1;
	directions[0][1] = 0;
	directions[1][0] = 0;
	directions[1][1] = 1;
	directions[2][0] = -1;
	directions[2][1] = 0;
	directions[3][0] = 0;
	directions[3][1] = -1;
	map[r][c] = 'v';
	i = -1;
	while (++i < 4)
	{
		nr = r + directions[i][0];
		nc = c + directions[i][1];
		if ((0 <= nr && nr < map_details.rows) \
		&& (0 <= nc && nc < map_details.cols) \
		&& (map[nr][nc] != '1') && (map[nr][nc] != 'v'))
			ft_flood_fill(map, map_details, nr, nc);
	}
}

int	ft_can_eat_and_exit(t_map *map_details)
{
	char	**map_copy;
	int		r;
	int		c;

	map_copy = (char **)malloc(sizeof(char *) * (map_details->rows + 1));
	if (!map_copy)
		return (0);
	r = -1;
	while (++r < map_details->rows)
		map_copy[r] = ft_strdup(map_details->map[r]);
	map_copy[r] = NULL;
	ft_flood_fill(map_copy, *map_details, map_details->player_row, \
	map_details->player_col);
	while (--r >= 0)
	{
		c = -1;
		while (++c < map_details->cols)
		{
			if (map_copy[r][c] == 'C')
				map_details->can_player_eat_all_collectibles = 0;
			else if (map_copy[r][c] == 'E')
				map_details->can_player_exit = 0;
		}
	}
	return (ft_clear_map(map_copy), 1);
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
