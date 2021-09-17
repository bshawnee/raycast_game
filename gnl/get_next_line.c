/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:38:29 by bshawnee          #+#    #+#             */
/*   Updated: 2021/02/25 00:00:14 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

static char			*ft_strjoins(char const *s1, char const *s2)
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
	free((void*)s1);
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char				*check_buf(char *buf, char **line)
{
	char *new_buf;

	if (buf)
	{
		if ((ft_strchr(buf, '\n')))
		{
			new_buf = ft_strdup(ft_strchr(buf, '\n') + 1);
			*(ft_strchr(buf, '\n')) = '\0';
			free(*line);
			*line = ft_strdup(buf);
			free(buf);
			buf = NULL;
			return (new_buf);
		}
		else
		{
			free(*line);
			*line = ft_strdup(buf);
			free(buf);
			buf = NULL;
		}
	}
	return (NULL);
}

int					get_next_line(int fd, char **line)
{
	int			return_value;
	char		buf[BUFFER_SIZE + 1];
	static char	*remain;
	char		*tmp;

	if ((return_value = read(fd, buf, 0)) < 0 || BUFFER_SIZE < 1)
		return (-1);
	*line = ft_strdup("");
	remain = check_buf(remain, line);
	while (!remain && (return_value = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[return_value] = '\0';
		if ((tmp = ft_strchr(buf, '\n')))
		{
			remain = ft_strdup(tmp + 1);
			*tmp = '\0';
		}
		if (!(*line = ft_strjoins(*line, buf)))
			return (-1);
	}
	if (remain)
		return (1);
	if (return_value <= 0)
		return (0);
	return (1);
}
