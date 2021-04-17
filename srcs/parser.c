#include "../headers/parser.h"

int					empty_line(char *str)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

static char			*check(char const *s1, char const *s2)
{
	if (!s1)
	{
		if (!s2)
			return (NULL);
		return (ft_strdup(s2));
	}
	if (!s2)
	{
		if (!s1)
			return (NULL);
		return (ft_strdup(s1));
	}
	return (NULL);
}

char				*ft_strjoint(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (check(s1, s2));
	str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free((char*)s1);
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char				*skip_space(char *str)
{
	while (*str == ' ' || *str == '\t')
		str += 1;
	return (str);
}

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

static int		check_row(char **map)
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

static int		check_len(char **map)
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

static int		check_skips(char **map)
{
	int i;

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

static void		check_map(char **map)
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

char			**pars_file(char *file, t_config *conf)
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
