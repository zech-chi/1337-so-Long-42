/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:55:03 by zech-chi          #+#    #+#             */
/*   Updated: 2023/12/22 13:55:39 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_create_map(t_list **head, t_map map_details)
{
	char	**map;
	t_list	*cur_node;
	int		r;

	if (!head || !(*head))
		return (NULL);
	map = (char **)malloc(sizeof(char *) * (map_details.rows + 1));
	if (!map)
		return (NULL);
	r = 0;
	cur_node = *head;
	while (cur_node)
	{
		map[r++] = cur_node->content;
		cur_node = cur_node->next;
	}
	map[r] = NULL;
	return (map);
}

void	ft_clear_map(char **str)
{
	int	r;

	if (!str)
		return ;
	r = 0;
	while (str[r])
	{
		free(str[r]);
		r++;
	}
	free(str);
}
