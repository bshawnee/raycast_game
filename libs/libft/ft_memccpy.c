/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:53:17 by bshawnee          #+#    #+#             */
/*   Updated: 2020/11/06 23:57:07 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *destination, const void *source, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*dest;

	i = 0;
	dest = (unsigned char*)destination;
	src = (unsigned char*)source;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == (unsigned char)c)
			break ;
		i++;
	}
	if (dest[i] == (unsigned char)c)
		return (&dest[i + 1]);
	return (NULL);
}
