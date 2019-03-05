/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 10:37:15 by tkelest           #+#    #+#             */
/*   Updated: 2018/05/25 09:57:18 by tkelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*udst;
	unsigned char	*usrc;
	size_t			i;

	udst = (unsigned char *)dst;
	usrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		udst[i] = usrc[i];
		i++;
	}
	return (dst);
}
