/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 15:09:46 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/15 18:14:35 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../global_var.h"
#include <unistd.h>
#include <printf.h>
#include <fcntl.h>
#include "../cube3d.h"
#include "../structs.h"
#include "../defines.h"

static int		bmp_header(int fd, unsigned filesize, t_bmp *bmp)
{
	int h_resol;
	int count;

	h_resol = g_config.resolution[Y] * -1;
	count = 0;
	count += write(fd, "BM", 2);
	count += write(fd, &filesize, 4);
	count += write(fd, &bmp->reserved, 4);
	count += write(fd, &bmp->offset_h, 4);
	count += write(fd, &bmp->size_h, 4);
	count += write(fd, &(g_config.resolution[X]), 4);
	count += write(fd, &h_resol, 4);
	count += write(fd, &bmp->plane, 2);
	count += write(fd, &bmp->colors, 2);
	count += write(fd, &bmp->compression, 4);
	count += write(fd, &bmp->raw_size, 4);
	count += write(fd, &bmp->h_res, 4);
	count += write(fd, &bmp->w_res, 4);
	count += write(fd, &bmp->color_entries, 4);
	count += write(fd, &bmp->main_color, 4);
	return (count);
}

static int		bmp_data(int fd, t_img *img)
{
	char	*color;
	int		i;
	int		j;

	i = 0;
	while (i < g_config.resolution[Y])
	{
		j = 0;
		while (j < g_config.resolution[X])
		{
			color = img->addr + (i * img->line_length + j *
			(img->bits_per_pixel / 8));
			write(fd, (unsigned*)color, BIT_COLOR / 8);
			j++;
		}
		i++;
	}
	return (0);
}

static void		init_bmp(t_bmp *bmp)
{
	bmp->offset_h = 54;
	bmp->size_h = 40;
	bmp->plane = 1;
	bmp->colors = BIT_COLOR;
	bmp->h_res = 3780;
	bmp->w_res = 3780;
}

int				save_image_bmp(t_img *img)
{
	int			fd;
	unsigned	file_size;
	t_bmp		bmp;

	ft_memset(&bmp, 0, sizeof(bmp) + 1);
	init_bmp(&bmp);
	fd = open("screenshot.bmp", O_CREAT | O_RDWR, S_IRWXU);
	if (fd < 0)
		return (-1);
	file_size = 54 + (BIT_COLOR / 8) * (g_config.resolution[X] *
	g_config.resolution[Y]);
	if (bmp_header(fd, file_size, &bmp) != 54)
		return (1);
	bmp_data(fd, img);
	exit(EXIT_SUCCESS);
	return (0);
}
