/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 23:14:08 by bshawnee          #+#    #+#             */
/*   Updated: 2021/04/17 17:27:12 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "structs.h"
# include "../libs/libft/libft.h"
# include "../srcs/gnl/get_next_line.h"

void			error(const char *msg);
void			check_config(t_config *config);
unsigned int	convert_rgb_to_hex(t_rgb *rgb);
void			init_conf(t_config *conf);
int				empty_line(char *str);
char			*skip_space(char *str);
int				is_map(char *str);
char			**swap_map(char **data, int map_start);
char			*ft_strjoint(char const *s1, char const *s2);
char			*comp_str(char *s1, char *s2);
char			**pars_file(char *file, t_config *conf);
int				correct_whitespace(char **map);
int				check_border(char **map, size_t y, size_t x);
int				correct_ch(char **map);
int				find_last_line(char **map);
int				correct_fl_line(char *line);
void			*take_path(char *line);
void			add_pars_path(char *line, t_config *conf);
int				pars_path(char *line, t_config *conf);
void			take_color(char *line, t_rgb *rgb);
void			take_resolution(char *line, t_config *conf);
char			**pars_params(t_config *conf, char **data);

#endif
