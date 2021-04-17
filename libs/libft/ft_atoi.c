/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 23:25:57 by bshawnee          #+#    #+#             */
/*   Updated: 2020/11/08 17:32:51 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	skip_ch(char *str, int *neg)
{
	size_t i;

	i = 0;
	while ((str[i] == '\t' || str[i] == '\n' || str[i] == ' ' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r') && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*neg = -1;
		i++;
	}
	return (i);
}

int				ft_atoi(const char *str)
{
	size_t	i;
	long	nbr;
	int		neg;

	neg = 1;
	i = skip_ch((char*)str, &neg);
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		nbr = nbr * 10 + (str[i++] - '0');
		if (nbr * neg > __INT_MAX || nbr * neg < __INT_MIN)
		{
			if (nbr * neg > __INT_MIN)
				return (-1);
			return (0);
		}
	}
	if (neg == -1 && nbr != 0)
		nbr = -nbr;
	return (nbr);
}
