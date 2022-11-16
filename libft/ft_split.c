/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:10:12 by ebouabba          #+#    #+#             */
/*   Updated: 2021/11/25 16:00:31 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbr_tab(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			if ((s[i - 1] == c || i == 0))
				count++;
			i++;
		}
	}
	return (count);
}

static char	**ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s)
		return (0);
	tab = (char **)malloc((ft_nbr_tab(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (tab);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		len = 0;
		while (s[len] != '\0' && s[len] != c)
			len++;
		if (len != 0)
			tab[i++] = ft_substr(s, 0, len);
		if (!tab[i - 1] && len != 0)
			return (ft_free(tab));
		s = s + len;
	}
	tab[i] = NULL;
	return (tab);
}
