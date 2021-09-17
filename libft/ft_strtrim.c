/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:44:36 by bshawnee          #+#    #+#             */
/*   Updated: 2020/11/08 15:48:08 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	int		end;
	size_t	j;
	char	*str;

	start = 0;
	j = 0;
	if (!s1)
		return (NULL);
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) && start < ft_strlen(s1))
		start++;
	while (ft_strrchr(set, s1[end]) && end > (int)start)
		end--;
	if ((int)start > end)
		return (ft_calloc(1, 1));
	str = (char*)ft_calloc(end - start + 2, sizeof(char));
	if (!str)
		return (NULL);
	while ((int)start <= end)
		str[j++] = s1[start++];
	str[j] = '\0';
	return (str);
}
