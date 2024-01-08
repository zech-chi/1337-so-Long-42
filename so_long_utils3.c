/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 17:49:47 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/08 20:23:47 by zech-chi         ###   ########.fr       */
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
