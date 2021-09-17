/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 16:34:30 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/15 17:11:40 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_rgb
{
	int				red;
	int				green;
	int				blue;
}					t_rgb;

typedef struct		s_keys
{
	unsigned		m_up:1;
	unsigned		m_down:1;
	unsigned		m_r:1;
	unsigned		m_l:1;
	unsigned		pov_r:1;
	unsigned		pov_l:1;
	unsigned		esc:1;
}					t_keys;

typedef struct		s_plr
{
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			dir_x;
	double			dir_y;
	double			pos_x;
	double			pos_y;
	t_keys			keys;
}					t_plr;

typedef struct		s_config
{
	struct s_rgb	floor_color;
	struct s_rgb	skybox_color;
	void			*north_texture;
	void			*south_texture;
	void			*west_texture;
	void			*east_texture;
	void			*sprite_texture;
	int				resolution[2];
}					t_config;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct		s_img
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct		s_picture
{
	struct s_img	img;
	int				width;
	int				height;
}					t_picture;

typedef struct		s_sprite
{
	double			x;
	double			y;
	struct s_sprite	*next;
}					t_sprite;

typedef struct		s_bmp
{
	unsigned		reserved;
	unsigned		offset_h;
	unsigned		size_h;
	short			plane;
	short			colors;
	unsigned		compression;
	unsigned		raw_size;
	int				h_res;
	int				w_res;
	unsigned		color_entries;
	unsigned		main_color;
}					t_bmp;

#endif
