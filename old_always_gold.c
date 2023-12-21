/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_always_gold.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:22:45 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/21 13:22:46 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_valid_map(t_map map_details)
{
	if (map_details.cols == map_details.rows || (!map_details.is_rectangular))
		return (ft_putstr_fd("The map must be rectangular!", 2), 0);
	if (!map_details.surrounded_by_walls)
		return (ft_putstr_fd("The map must be closed/surrounded by walls!", 2), 0);
	if (!map_details.count_collectibles)
		return (ft_putstr_fd("The map must contain at least 1 collectible!", 2), 0);
	if (map_details.count_map_exit != 1)
		return (ft_putstr_fd("The map must contain 1 exit!", 2), 0);
	if (map_details.count_starting_position != 1)
		return (ft_putstr_fd("The map must contain 1 starting position!", 2), 0);
	if (map_details.have_another_char)
		return (ft_putstr_fd("The map must contain 0, 1, C, E or P!", 2), 0);
	if (!map_details.can_player_eat_all_collectibles)
		return (ft_putstr_fd("the player can't eat all collectibkes!", 2), 0);
	if (!map_details.can_player_exit)
		return (ft_putstr_fd("the player can't exit", 2), 0);
	return (0);
}
