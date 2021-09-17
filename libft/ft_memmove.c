/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 19:06:31 by bshawnee          #+#    #+#             */
/*   Updated: 2020/11/03 14:30:52 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *destination, const void *source, size_t n)
{
	unsigned char		*dest;
	const unsigned char	*src;
	size_t				i;

	i = 0;
	dest = (unsigned char*)destination;
	src = (const unsigned char*)source;
	if (!dest && !src)
		return (NULL);
	if (dest > src)
		while (++i <= n)
			dest[n - i] = src[n - i];
	else
		while (n--)
			*dest++ = *src++;
	return (destination);
}
