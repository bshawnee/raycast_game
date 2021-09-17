/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 23:13:33 by bshawnee          #+#    #+#             */
/*   Updated: 2020/12/25 17:56:15 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_f(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_f(n * (-1), fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_f(n / 10, fd);
		ft_putnbr_f(n % 10, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd);
}
