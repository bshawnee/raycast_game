/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 15:33:23 by bshawnee          #+#    #+#             */
/*   Updated: 2020/11/08 00:24:15 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t n)
{
	size_t i;

	i = 0;
	if (!destination && !source)
		return (NULL);
	while (i < n)
	{
		((unsigned char*)destination)[i] = ((unsigned char*)source)[i];
		i++;
	}
	return (destination);
}
