/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_color_resol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:07:44 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/11 23:15:41 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int		take_rgb(char **line, int *color)
{
	int tmp;

	if (**line == '+')
		*line += 1;
	if (ft_isdigit(**line))
	{
		if ((tmp = ft_atoi(*line)) > 255 || tmp < 0)
		{
			ft_putendl_fd(*line, 1);
			return (EXIT_FAILURE);
		}
		*color = tmp;
		while (ft_isdigit(**line))
			*line += 1;
	}
	else
		return (EXIT_FAILURE);
	return (0);
}

static char		*skip_space_color(char *line)
{
	if (*line == ' ' || *line == '\t')
	{
		line = skip_space(line);
		if (*line == ',')
		{
			line += 1;
			line = skip_space(line);
		}
		else if (!ft_isdigit(*line))
			return (NULL);
	}
	return (line);
}

void			take_color(char *line, t_rgb *rgb)
{
	if (*line == ' ')
		line = skip_space(line);
	else
		error("Incorrect color parametrs1");
	if (rgb->red == -1 && take_rgb(&line, &rgb->red) == 1)
		error("Incorrect color parametrs2");
	if (*line == ',')
		line = skip_space(line + 1);
	else if ((line = skip_space_color(line)) == NULL)
		error("Incorrect color parametrs3");
	if (rgb->green == -1 && take_rgb(&line, &rgb->green) == 1)
		error("Incorrect color parametrs4");
	if (*line == ',')
		line = skip_space(line + 1);
	else if ((line = skip_space_color(line)) == NULL)
		error("Incorrect color parametrs5");
	if (rgb->blue == -1 && take_rgb(&line, &rgb->blue) == 1)
		error("Incorrect color parametrs6");
	line = skip_space(line);
	if (*line != '\0')
		error("Incorrect color parametrs7");
}

static int		take_num_from_str(char **line)
{
	int num;

	*line = skip_space(*line);
	if (**line == '+')
		*line += 1;
	if (ft_isdigit(**line))
	{
		num = ft_atoi(*line);
		if (num < 0)
			num = 10000;
		while (ft_isdigit(**line))
			*line += 1;
	}
	else
		return (-1);
	return (num);
}

void			take_resolution(char *line, t_config *conf)
{
	line += 1;
	if (*line == ' ')
		line = skip_space(line);
	else
		error("Cant found resolution1");
	if (!conf->resolution[0] && (conf->resolution[0] = \
	take_num_from_str(&line)) <= 0)
		error("Incorrect reosulion2");
	if (!conf->resolution[1] && (conf->resolution[1] = \
	take_num_from_str(&line)) <= 0)
		error("Incorrect resolution3");
	line = skip_space(line);
	if (*line != '\0')
		error("Incorrect resolution");
}
