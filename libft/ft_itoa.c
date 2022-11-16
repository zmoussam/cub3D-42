/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 09:52:41 by ebouabba          #+#    #+#             */
/*   Updated: 2021/11/24 01:03:19 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_nbr(int nbr)
{
	int	len_nbr;

	len_nbr = 0;
	if (nbr <= 0)
		len_nbr++;
	while (nbr)
	{
		nbr /= 10;
		len_nbr++;
	}
	return (len_nbr);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		len_n;

	len_n = ft_len_nbr(n);
	string = malloc(sizeof(char) * len_n + 1);
	if (!string)
		return (NULL);
	string[len_n--] = '\0';
	if (n == -2147483648)
		ft_strlcpy(string, "-2147483648", ft_len_nbr(n) + 1);
	if (n == 0)
		string[0] = '0';
	if (n < 0)
	{
		string[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		string[len_n] = n % 10 + '0';
		n = n / 10;
		len_n--;
	}
	return (string);
}
