/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 17:48:17 by bshawnee          #+#    #+#             */
/*   Updated: 2020/11/08 16:50:21 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_strs(const char *s, char c)
{
	size_t	i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1]) || (s[0] != c && !i))
			count++;
		i++;
	}
	return (count);
}

static char	*get_str(const char *s, char c, size_t start)
{
	char	*str;
	size_t	end;
	size_t	i;

	i = 0;
	end = start;
	while (s[end] != c && s[end])
		++end;
	if (!(str = ft_calloc((end - start) + 1, sizeof(char))))
		return (NULL);
	while (start < end)
	{
		str[i] = s[start];
		++i;
		++start;
	}
	return (str);
}

static void	*free_map(char **map, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		free(map[i]);
		++i;
	}
	free(map);
	return (NULL);
}

char		**ft_split(const char *s, char c)
{
	char	**map;
	size_t	str;
	size_t	i;

	str = 0;
	i = 0;
	if ((!s || !(map = (char**)malloc((count_strs(s, c) + 1) * sizeof(char*)))))
		return ((char**)ft_calloc(1, 1));
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c && s[i + 1]) || (s[0] != c && !i))
		{
			if (s[0] != c && !i)
				map[str] = get_str(s, c, i);
			else
				map[str] = get_str(s, c, i + 1);
			if (!map[str])
				return (free_map(map, str));
			++str;
		}
		i++;
	}
	map[str] = NULL;
	return (map);
}
