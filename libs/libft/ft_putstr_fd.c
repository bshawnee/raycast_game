/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:59:10 by bshawnee          #+#    #+#             */
/*   Updated: 2020/11/04 15:10:38 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	if (!str || fd == -1)
		return ;
	if (*str)
	{
		ft_putchar_fd(*str, fd);
		ft_putstr_fd(str + 1, fd);
	}
}
