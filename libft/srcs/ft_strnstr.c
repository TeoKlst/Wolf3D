/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkelest <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:10:26 by tkelest           #+#    #+#             */
/*   Updated: 2018/06/01 14:32:15 by tkelest          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t i;

	if (*small == '\0')
		return ((char*)big);
	i = 0;
	while (*big && len)
	{
		if (*big == small[i])
			i++;
		else
			i = 0;
		if (small[i] == '\0')
			return ((char*)(big - i + 1));
		big++;
		len--;
	}
	return (NULL);
}
