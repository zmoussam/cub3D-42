/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:36:47 by zmoussam          #+#    #+#             */
/*   Updated: 2021/11/30 15:40:20 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strnstr(const char *haystack, const char *needle, size_t len )
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *)(haystack));
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] == haystack[i + j])
		{
			if (i + j == len)
				return (NULL);
			if (needle[j + 1] == '\0')
			{
				return ((char *)(&haystack[i]));
			}
			j++;
		}
		i++;
	}
	return (0);
}
