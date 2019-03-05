/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 08:36:38 by tkelest           #+#    #+#             */
/*   Updated: 2018/05/25 09:57:45 by tkelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *ub;

	ub = (unsigned char *)b;
	while (len--)
	{
		*ub++ = (unsigned char)c;
	}
	return (b);
}
