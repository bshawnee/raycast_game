/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:59:41 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/11 23:13:53 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char			*comp_str(char *s1, char *s2)
{
	if (*s2 == '\0')
	{
		s1 = ft_strjoint(s1, "SKIP");
		s1 = ft_strjoint(s1, "\n");
	}
	else
	{
		s1 = ft_strjoint(s1, s2);
		s1 = ft_strjoint(s1, "\n");
	}
	free(s2);
	return (s1);
}

int				is_map(char *str)
{
	size_t	i;
	int		map_started;

	i = 0;
	map_started = 0;
	while (str[i] == ' ' || str[i] == '1')
	{
		if (str[i] == '1')
			map_started++;
		i++;
	}
	if (map_started)
		return (1);
	return (0);
}

char			**swap_map(char **data, int map_start)
{
	int		i;
	char	**map;

	i = map_start;
	while (data[i])
		i++;
	if (!(map = (char**)malloc(sizeof(char*) * (i - map_start) + 1)))
		return (NULL);
	i = 0;
	while (i < map_start)
	{
		free(data[i]);
		i++;
	}
	i = 0;
	while (data[map_start])
	{
		map[i] = ft_strdup(data[map_start]);
		i++;
		free(data[map_start]);
		map_start++;
	}
	map[i] = NULL;
	free(data);
	return (map);
}

unsigned int	convert_rgb_to_hex(t_rgb *rgb)
{
	return (((rgb->red & 0xff) << 16) + ((rgb->green & 0xff) << 8) +
	((rgb->blue & 0xff)));
}

void			check_config(t_config *config)
{
	if ((open(config->east_texture, O_RDONLY) <= 0) ||
		open(config->west_texture, O_RDONLY) <= 0 ||
		open(config->south_texture, O_RDONLY) <= 0 ||
		open(config->north_texture, O_RDONLY) <= 0 ||
		open(config->sprite_texture, O_RDONLY) <= 0)
		error("Can't open textures");
	if (config->resolution[0] == 0 || config->resolution[1] == 0)
		error("Can't found resolution");
	if (config->floor_color.red == -1 || config->floor_color.green == -1 ||
	config->floor_color.blue == -1 || config->skybox_color.red == -1 ||
	config->skybox_color.green == -1 || config->skybox_color.blue == -1)
		error("Can't found colors parameters");
}
