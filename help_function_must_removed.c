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
