#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct		s_data {
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct		s_rgb
{
	int				red;
	int				green;
	int				blue;
}					t_rgb;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

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

#endif
