/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:04:36 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/11 23:19:16 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void			*take_path(char *line)
{
	if (ft_strchr(" \t", *line))
		line = skip_space(line);
	else
		return (NULL);
	if (*line)
		return (ft_strdup(line));
	return (NULL);
}

void			add_pars_path(char *line, t_config *conf)
{
	if (*line == 'E' && *(line + 1) == 'A' && !conf->east_texture)
	{
		if (!(conf->east_texture = take_path(line + 2)))
			error("Cant found EA texture");
	}
	else if (*line == 'E' && *(line + 1) == 'A' && conf->east_texture)
		error("Reused EA texture");
	if (*line == 'S' && !conf->sprite_texture)
	{
		if (!(conf->sprite_texture = take_path(line + 1)))
			error("Cant found S texture");
	}
	else if (*line == 'S' && conf->sprite_texture)
		error("Reused S texture");
	if (*line == 'W' && *(line + 1) == 'E' && !conf->west_texture)
	{
		if (!(conf->west_texture = take_path(line + 2)))
			error("Cant found WE texture");
	}
	else if (*line == 'W' && *(line + 1) == 'E' && conf->west_texture)
		error("Reused WE texture");
}

int				pars_path(char *line, t_config *conf)
{
	if (*line == 'N' && *(line + 1) == 'O' && !conf->north_texture)
	{
		if (!(conf->north_texture = take_path(line + 2)))
			error("Cant found NO texture");
	}
	else if (*line == 'N' && *(line + 1) == 'O' && conf->north_texture)
		error("Reused NO texture");
	if (*line == 'S' && *(line + 1) == 'O' && !conf->south_texture)
	{
		if (!(conf->south_texture = take_path(line + 2)))
			error("Cant found SO texture");
	}
	else if (*line == 'S' && *(line + 1) == 'O' && conf->south_texture)
		error("Reused SO texture");
	else
		add_pars_path(line, conf);
	if (!*line && !empty_line(line))
		error("Cant found texture");
	return (0);
}

char			**pars_params(t_config *conf, char **data)
{
	size_t i;
	size_t j;

	i = 0;
	while (data[i])
	{
		j = 0;
		while (data[i][j] == ' ' || data[i][j] == '\t')
			j++;
		if (is_map(data[i]))
			return (swap_map(data, i));
		else if (ft_strchr("NSWE", data[i][j]) &&
		ft_strncmp("SKIP", data[i], 5))
			pars_path(&data[i][j], conf);
		else if (data[i][j] == 'R')
			take_resolution(&data[i][j], conf);
		else if (data[i][j] == 'F')
			take_color(&data[i][j + 1], &conf->floor_color);
		else if (data[i][j] == 'C')
			take_color(&data[i][j + 1], &conf->skybox_color);
		i++;
	}
	return (NULL);
}

void			init_conf(t_config *conf)
{
	conf->east_texture = NULL;
	conf->north_texture = NULL;
	conf->west_texture = NULL;
	conf->sprite_texture = NULL;
	conf->south_texture = NULL;
	conf->skybox_color.blue = -1;
	conf->skybox_color.green = -1;
	conf->skybox_color.red = -1;
	conf->floor_color.red = -1;
	conf->floor_color.green = -1;
	conf->floor_color.blue = -1;
	conf->resolution[0] = 0;
	conf->resolution[1] = 0;
}
