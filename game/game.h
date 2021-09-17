/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 22:31:36 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/15 17:30:39 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H
# include <math.h>
# include "../minilibx-mac/mlx.h"
# include "../global_var.h"
# include "../defines.h"
# include "../render/render.h"

int				update_game(t_plr *plr);
int				key_press(int keycode, t_plr *plr);

#endif
