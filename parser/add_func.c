/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 19:54:27 by bshawnee          #+#    #+#             */
/*   Updated: 2021/03/11 23:13:04 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int					empty_line(char *str)
{
	size_t i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (!str[i])
		return (1);
	return (0);
}

static char			*check(char const *s1, char const *s2)
{
	if (!s1)
	{
		if (!s2)
			return (NULL);
		return (ft_strdup(s2));
	}
	if (!s2)
	{
		if (!s1)
			return (NULL);
		return (ft_strdup(s1));
	}
	return (NULL);
}

char				*ft_strjoint(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (check(s1, s2));
	str = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	free((char*)s1);
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char				*skip_space(char *str)
{
	while (*str == ' ' || *str == '\t')
		str += 1;
	return (str);
}
