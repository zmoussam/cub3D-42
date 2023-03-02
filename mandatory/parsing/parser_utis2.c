/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utis2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:16:13 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/02 05:45:27 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int numberofgamma(char *pathcolor)
{
	int	i;
    int	j;

	i = 0;
	j = 0;
	while (pathcolor[i])
	{
		if (pathcolor[i] == ',')
			j++;
		i++;
	}
	return(j);
}

int	checkgamma(char *pathcolor)
{
	int	nbrofgamma;

	nbrofgamma = numberofgamma(pathcolor);
	if (nbrofgamma == 2)
		return(1);
	return(0);
}

size_t	delet_espaces_at_the_end(char* chaine)
{
	size_t	i;

	i = ft_strlen(chaine) - 1;
	while (i >= 0 && chaine[i] != '1')
		i--;
	return (i);
}
