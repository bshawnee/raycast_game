/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 23:15:55 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/15 18:39:45 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			check_row(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i] && !empty_line(map[i]) && ft_strncmp(map[i], "SKIP", 5))
	{
		j = 0;
		while (map[i][j] && map[i][j] == ' ')
			j++;
		if (map[i][j] == '1')
		{
			j = ft_strlen(map[i]) - 1;
			while (j >= 0 && map[i][j] == ' ')
				j--;
			if (map[i][j] != '1')
				return (1);
		}
		else
		{
			ft_putchar_fd('-', 1);
			return (1);
		}
		i++;
	}
	return (0);
}

int			check_len(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && i)
		{
			if (map[i][j] == '0' && j > (int)ft_strlen(map[i - 1]) - 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			check_skips(char **map)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (map[i])
		i++;
	i--;
	while (i != 0 && (!map[i] || !ft_strncmp(map[i], "SKIP", 5) ||
	empty_line(map[i])))
		i--;
	while (i != 0)
	{
		if (!ft_strncmp(map[i], "SKIP", 5) || empty_line(map[i]))
			error("Empty lines in map");
		i--;
	}
	return (0);
}

void		check_map(char **map)
{
	if (!map)
		error("Map not found");
	if (!correct_fl_line(map[0]) || !correct_fl_line(map[find_last_line(map)]))
		error("Incorrect last/first line");
	if (!correct_ch(map))
		error("Unknown character");
	if (check_skips(map))
		error("Empty lines in map");
	if (!correct_whitespace(map) || check_row(map) || check_len(map))
		error("Incorrect border");
}

char		**pars_file(char *file, t_config *conf)
{
	int		fd;
	char	*tmp;
	char	*str;
	char	**map;

	str = NULL;
	init_conf(conf);
	if ((fd = open(file, O_RDONLY)) <= 0)
		error("Cant open file");
	while (get_next_line(fd, &tmp) > 0)
	{
		if (!ft_strncmp("SKIP", tmp, 5))
			error("Unknown parametrs");
		str = comp_str(str, tmp);
	}
	str = comp_str(str, tmp);
	map = ft_split(str, '\n');
	free(str);
	map = pars_params(conf, map);
	check_map(map);
	check_config(conf);
	return (map);
}
