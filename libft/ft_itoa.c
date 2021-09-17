/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 20:46:25 by bshawnee          #+#    #+#             */
/*   Updated: 2020/11/08 17:33:11 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	len_str(int n)
{
	int		i;
	size_t	count;

	count = 0;
	i = 10;
	if (!n)
		return (0);
	while (n)
	{
		n -= n % 10;
		n /= 10;
		i *= 10;
		count++;
	}
	return (count);
}

static size_t	checker(int n, int *neg)
{
	size_t i;

	i = 1;
	if (n < 0)
	{
		*neg = 1;
		i = len_str(n) + 1;
	}
	else if (n > 0)
		i = len_str(n);
	return (i);
}

static char		*is_zero(void)
{
	char *str;

	str = (char*)ft_calloc(2, sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char		*n_is_min(void)
{
	char *str;

	str = (char*)ft_calloc(12, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, "-2147483648", 12);
	str[ft_strlen(str)] = '\0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	int		neg;

	neg = 0;
	i = checker(n, &neg);
	if (n == 0)
		return (is_zero());
	if (n == __INT_MIN)
		return (n_is_min());
	if (neg)
		n = -n;
	if (!(str = (char*)ft_calloc(i + 1, sizeof(char))))
		return (NULL);
	while (i-- && n)
	{
		if (neg && i == 0)
			break ;
		str[i] = ('0' + n % 10);
		n /= 10;
	}
	if (neg)
		str[i] = '-';
	str[ft_strlen(str)] = '\0';
	return (str);
}
