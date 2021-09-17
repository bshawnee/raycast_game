/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 20:37:24 by bshawnee          #+#    #+#             */
/*   Updated: 2021/02/27 16:55:19 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include <math.h>
# include "../minilibx-mac/mlx.h"
# include "../global_var.h"
# include "../defines.h"
# include "../parser/parser.h"
# include "../player/player.h"

double				perp_wall_dist(int *step, int *map);
void				raycaster(int *map, int *step);
void				side_distance(int *step, double *sidedist, double \
					*deltadist, int *map);
void				render_background(void);
void				init_sprite_mem(void);
void				update_frame(t_plr *plr);
int					init_texture(t_picture *texture, const char *filename);
int					init_textures(void);
void				my_mlx_pixel_put(t_img *data, int x, int y, int color);
void				sort_sprite(t_sprite **s, double pos_x, double pos_y);
void				init_sprites(t_sprite *s, t_plr *plr, double *zbuffer);

#endif
