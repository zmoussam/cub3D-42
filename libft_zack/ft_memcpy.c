/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:38:56 by zmoussam          #+#    #+#             */
/*   Updated: 2021/11/30 15:29:25 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*surc;
	size_t	i;

	dest = (char *)dst;
	surc = (char *)src;
	if (!(src || dst))
		return ((void *)(0));
	i = 0;
	while (i < n)
	{
		dest[i] = surc[i];
		i++;
	}
	return (dst);
}
