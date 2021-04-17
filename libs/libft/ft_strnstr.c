/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 20:35:58 by bshawnee          #+#    #+#             */
/*   Updated: 2020/11/23 18:40:52 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*b;
	size_t	i;

	i = 0;
	b = (char*)big;
	if (!*little)
		return ((char*)big);
	if (!ft_strlen(little) && ft_strlen(big))
		return ((char*)big);
	if (!len || ft_strlen(little) > ft_strlen(big))
		return (NULL);
	while (b[i] && ft_strncmp(&b[i], little, ft_strlen(little)) != 0
			&& i < len)
		++i;
	if (!b || i + ft_strlen(little) > len)
		return (NULL);
	return (&b[i]);
}
