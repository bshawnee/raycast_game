/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:02:04 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/15 18:38:22 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			correct_fl_line(char *line)
{
	size_t i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(" 1", line[i]))
			return (0);
		i++;
	}
	return (1);
}

int			find_last_line(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		if (!ft_strncmp(map[i], "SKIP", 4))
			return (i - 1);
		else if (empty_line(map[i]) && i)
			return (i - 1);
		i++;
	}
	return (i - 1);
}

int			correct_ch(char **map)
{
	size_t i;
	size_t j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strncmp("SKIP", map[i], 5) ||
			ft_strchr("120 NSWE", map[i][j]))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int			check_border(char **map, size_t y, size_t x)
{
	if (map[y][x] == ' ')
	{
		if (!ft_strchr("1 ", map[y - 1][x]) ||
		!ft_strchr("1 ", map[y + 1][x]) ||
		!ft_strchr("1 ", map[y][x - 1]) ||
		!ft_strchr("1 ", map[y][x + 1]))
			return (1);
		if (!ft_strchr("1 ", map[y][x - 1]) ||
		!ft_strchr("1 ", map[y][x + 1]))
			return (1);
	}
	return (0);
}

int			correct_whitespace(char **map)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (map[i])
	{
		j = 1;
		while (map[i][j])
		{
			if (ft_strchr("02NSWE", map[i][j]))
			{
				if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' ||
				map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
					return (0);
				else if (j >= ft_strlen(map[i + 1]))
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
