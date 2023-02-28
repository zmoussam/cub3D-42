/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 17:44:30 by zmoussam          #+#    #+#             */
/*   Updated: 2021/11/30 15:34:12 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chr_first_index(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	chr_last_index(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;
	int		new_size;

	if (!s1 || !set)
		return (NULL);
	start = chr_first_index(s1, set);
	end = chr_last_index(s1, set);
	new_size = end - start;
	if (set == NULL)
		return (ft_strdup((char *)s1));
	if (start >= end)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (new_size + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1 + start, new_size + 1);
	return (str);
}
