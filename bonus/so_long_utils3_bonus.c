/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils3_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zech-chi <zech-chi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:25:01 by zech-chi          #+#    #+#             */
/*   Updated: 2024/01/17 19:25:27 by zech-chi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

int	ft_is_valid_map_name(char *map_name)
{
	int	len;

	if (!map_name)
		return (0);
	len = ft_strlen(map_name);
	if (len < 4)
		return (0);
	if (!ft_strcmp(map_name + len - 4, ".ber"))
		return (1);
	return (0);
}
