/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:23:23 by zmoussam          #+#    #+#             */
/*   Updated: 2021/11/30 15:28:44 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(int nbr)
{
	int	size;
	int	n;

	size = 0;
	n = nbr;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		size++;
	}
	size = size + (n <= 0);
	return (size);
}

char	*ft_itoa(int l)
{
	char	*str;
	long	n;
	int		p;
	int		len_nbr;

	n = l;
	len_nbr = nbr_len(n);
	str = (char *)malloc((len_nbr + 1) * sizeof(char));
	if (!str)
		return (str);
	p = 0;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
		p = 1;
	}
	str[len_nbr] = '\0';
	while (--len_nbr >= p)
	{
		str[len_nbr] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
