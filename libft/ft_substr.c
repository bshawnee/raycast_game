/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 22:16:23 by bshawnee          #+#    #+#             */
/*   Updated: 2020/11/07 20:30:54 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)ft_calloc(len + 1, 1);
	if (!str || !s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (str);
	while (s[start] && i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	if (i)
		str[i] = '\0';
	return (str);
}
