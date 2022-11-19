/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:09:38 by ebouabba          #+#    #+#             */
/*   Updated: 2021/11/25 15:34:35 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	first;
	int	len;
	int	last;
	int	i;

	len = 0;
	first = 0;
	if (!s1)
		return (NULL);
	last = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[first]) && s1[first] != '\0')
		first++;
	while (ft_strchr(set, s1[last]) && last >= first)
	{
		last--;
		len++;
	}
	i = ft_strlen(s1) - first - len;
	return (ft_substr(s1, first, i));
}
