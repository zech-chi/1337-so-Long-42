/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:09:41 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:10:13 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	size_t	size;
	char	*ptr;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	if (size > 0)
	{
		j = 0;
		while (s1[j])
			ptr[i++] = s1[j++];
		j = 0;
		while (s2[j])
			ptr[i++] = s2[j++];
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_del_first_elem(t_list **queue)
{
	t_list	*tmp;

	if (!queue || !(*queue))
		return (NULL);
	tmp = *queue;
	*queue = (*queue)->next;
	free(tmp);
	return (tmp->content);
}

void	ft_fill_r_and_c(t_map map_info, char *str, int *r, int *c)
{
	int	i;

	*r = map_info.enemy_row;
	*c = map_info.enemy_col;
	i = 0;
	while (str[i])
	{
		if (str[i] == 'u')
			(*r)--;
		else if (str[i] == 'r')
			(*c)++;
		else if (str[i] == 'd')
			(*r)++;
		else if (str[i] == 'l')
			(*c)--;
		i++;
	}
}

void	ft_clear_map_n(char **str, int size)
{
	int	r;

	if (size == 0)
		return ;
	r = 0;
	while (r < size)
	{
		free(str[r]);
		r++;
	}
	free(str);
}

char	*ft_enemy_path_to_player(t_map *map_info)
{
	char	**map_copy;
	char	*path;
	int		r;

	map_copy = (char **)malloc(sizeof(char *) * (map_info->rows + 1));
	if (!map_copy)
		return (NULL);
	r = -1;
	while (++r < map_info->rows)
	{
		map_copy[r] = ft_strdup(map_info->map[r]);
		if (!map_copy[r])
		{
			ft_clear_map_n(map_copy, r);
			ft_free_mlx_business(map_info);
		}
	}
	map_copy[r] = NULL;
	path = ft_bfs(map_info, map_copy);
	ft_clear_map(map_copy);
	return (path);
}
