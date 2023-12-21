/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:15:49 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/21 13:19:39 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_map_info(t_map map_details)
{
	printf("------------------------------\n");
	printf("cols : %d\n", map_details.cols);
	printf("rows : %d\n", map_details.rows);
	printf("is_rectangular : %d\n", map_details.is_rectangular);
	printf("surrounded_by_walls : %d\n", map_details.surrounded_by_walls);
	printf("count_collectibles : %d\n", map_details.count_collectibles);
	printf("count_map_exit : %d\n", map_details.count_map_exit);
	printf("count_starting_position : %d\n", map_details.count_starting_position);
	printf("player_row : %d\n", map_details.player_row);
	printf("player_col : %d\n", map_details.player_col);
	printf("exit_row : %d\n", map_details.exit_row);
	printf("exit_col : %d\n", map_details.exit_col);
	printf("have_another_char : %d\n", map_details.have_another_char);
	printf("can_player_eat_all_collectibles : %d\n", map_details.can_player_eat_all_collectibles);
	printf("can_player_exit : %d\n", map_details.can_player_exit);
	printf("map : coming soon!!\n");
	printf("------------------------------\n");
	//char **map;
}


int	ft_is_valid_map_part2(t_map map_details, int check_path)
{
	int	is_something_worng;

	is_something_worng = 0;
	if (!check_path && map_details.count_starting_position != 1)
	{
		ft_putstr_fd("The map must contain 1 starting position!", 2);
		is_something_worng = 1;
	}
	if (!check_path && map_details.have_another_char)
	{
		ft_putstr_fd("The map must contain 0, 1, C, E and P!", 2);
		is_something_worng = 1;
	}
	if (check_path && !map_details.can_player_eat_all_collectibles)
	{
		ft_putstr_fd("the player can't eat all collectibkes!", 2);
		is_something_worng = 1;
	}
	if (check_path && !map_details.can_player_exit)
	{
		ft_putstr_fd("the player can't exit", 2);
		is_something_worng = 1;
	}
	return (is_something_worng);
}

int	ft_is_valid_map_part1(t_map map_details)
{
	int	is_something_worng;

	is_something_worng = 0;
	if (map_details.cols == map_details.rows || (!map_details.is_rectangular))
	{
		ft_putstr_fd("The map must be rectangular!", 2);
		is_something_worng = 1;
	}
	if (!map_details.surrounded_by_walls)
	{
		ft_putstr_fd("The map must be closed/surrounded by walls!", 2);
		is_something_worng = 1;
	}
	if (!map_details.count_collectibles)
	{
		ft_putstr_fd("The map must contain at least 1 collectible!", 2);
		is_something_worng = 1;
	}
	if (map_details.count_map_exit != 1)
	{
		ft_putstr_fd("The map must contain 1 exit!", 2);
		is_something_worng = 1;
	}
	return (is_something_worng);
}

t_list	*ft_read_file(int fd, t_map *map_details)
{
	t_list	*head;
	char	*line;
	int	r;
	int	c;

	r = 0;
	line = get_next_line(fd);
	head = NULL;
	while (line)
	{
		ft_lstadd_back(&head, ft_lstnew(line));
		c = 0;
		while (line[c] && line[c] != '\n')
		{
			if ((r == 0 || c == 0) && line[c] != '1')
				(*map_details).surrounded_by_walls = 0;
			if (line[c] == 'C')
				(*map_details).count_collectibles += 1;
			else if (line[c] == 'E')
			{
				(*map_details).count_map_exit += 1;
				(*map_details).exit_row = r;
				(*map_details).exit_col = c;
			}
			else if (line[c] == 'P')
			{
				(*map_details).count_starting_position += 1;
				(*map_details).player_row = r;
				(*map_details).player_col = c;
			}
			else if (line[c] != '0' && line[c] != '1')
				(*map_details).have_another_char = 1;
			c++;
		}
		if (line[c - 1] != '1')
			(*map_details).surrounded_by_walls = 0;
		if ((*map_details).cols == -1)
			(*map_details).cols = c;
		else if ((*map_details).cols != c)
			(*map_details).is_rectangular = 0;
		line = get_next_line(fd);
		r++;
	}
	line = (ft_lstlast(head))->content;
	c = 0;
	while (line && line[c])
	{
		if (line[c] != '1')
			(*map_details).surrounded_by_walls = 0;
		c++;
	}
	(*map_details).rows = r;
	return (NULL);
}

int	main()
{
	t_map	map_details;
	int						fd;
	
	map_details = (t_map){-1, -1, 1, 1, 0, 0, 0, -1, -1, -1, -1, 0, 1, 1, NULL};
	fd = open("map.ber", O_RDONLY);
	ft_print_map_info(map_details);	
	ft_read_file(fd, &map_details);
	ft_print_map_info(map_details);
	ft_is_valid_map_part1(map_details);
	ft_is_valid_map_part2(map_details, 0);
	return (0);
}


//#include <string.h>
//int main()
//{
//	t_list	*head = NULL;
//	char	*line;
//	int	fd;

//	fd = open("map.ber", O_RDONLY);
//	line = get_next_line(fd);
//	while (line)
//	{
//		printf("%s", line);
//		ft_lstadd_back(&head, ft_lstnew(line));
//		line = get_next_line(fd);
//	}

//	printf("\nhead --> ");
//	while (head)
//	{
//		printf("%s --> ", head->content);
//		head = head->next;
//	}
//	printf("NULL\n");
//	return (0);
//}