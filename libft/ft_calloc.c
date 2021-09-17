/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshawnee <bshawnee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:08:04 by bshawnee          #+#    #+#             */
/*   Updated: 2020/11/08 14:48:55 by bshawnee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned numelems, size_t sizelem)
{
	void *ptr;

	ptr = (void*)malloc(sizelem * numelems);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, sizelem * numelems);
	return (ptr);
}
