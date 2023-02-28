/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 23:54:00 by zmoussam          #+#    #+#             */
/*   Updated: 2021/11/27 16:08:44 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*surc;
	size_t			i;

	if (!(dst || src))
		return ((void *)(0));
	i = 0;
	dest = (unsigned char *)dst;
	surc = (unsigned char *)src;
	if (dest > surc)
	{
		while (len > 0)
		{
			dest[len -1] = surc[len -1];
			len--;
		}
	}
	else if (surc >= dest)
	{
		ft_memcpy(dest, surc, len);
	}
	return ((void *)(dst));
}
