/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 16:57:29 by bshawnee          #+#    #+#             */
/*   Updated: 2020/11/03 20:37:43 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t s_len;
	size_t d_len;
	size_t i_s;
	size_t res;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (d_len > size)
		res = s_len + size;
	else
		res = d_len + s_len;
	if (d_len < size)
	{
		i_s = 0;
		while (d_len < size && i_s < s_len)
			dest[d_len++] = src[i_s++];
		if (d_len < size)
			dest[d_len] = '\0';
		else
			dest[d_len - 1] = '\0';
	}
	return (res);
}
