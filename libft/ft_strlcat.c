/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 23:36:58 by ebouabba          #+#    #+#             */
/*   Updated: 2021/11/25 09:34:02 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_src;
	size_t	len_dst;
	size_t	reste;

	len_src = ft_strlen(src);
	len_dst = ft_strlen(dst);
	i = 0;
	reste = 0;
	if (dstsize == 0)
		return (len_src);
	if (len_dst < dstsize)
		reste = len_dst + len_src;
	else
		reste = dstsize + len_src;
	while (src[i] != '\0' && (len_dst + 1) < dstsize)
	{
		dst[len_dst] = src[i];
		i++;
		len_dst++;
	}
	dst[len_dst] = '\0';
	return (reste);
}
