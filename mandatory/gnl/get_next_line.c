/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:27:05 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/20 01:10:37 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *rest)
{
	int		len;
	char	*str;

	len = 0;
	while (rest[len] && rest[len] != '\n')
		len++;
	str = ft_substr2(rest, 0, len + 1);
	return (str);
}

char	*rest_line(char *rest)
{
	char	*ptr;
	int		len;

	len = 0;
	while (rest[len] && rest[len] != '\n')
		len++;
	ptr = ft_substr2(rest, len + 1, ft_strlen2(rest) - len + 1);
	free(rest);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		buffer[BUFFER_SIZE + 1];
	int			rd;
	char		*newline;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	rd = 1;
	while (rd != 0 && !ft_strchr2(rest, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		buffer[rd] = '\0';
		if (rd < 0)
			return (NULL);
		rest = ft_strjoin2(rest, buffer);
	}
	if (!rest[0])
	{
		free (rest);
		rest = NULL;
		return (NULL);
	}
	newline = get_line(rest);
	rest = rest_line(rest);
	return (newline);
}
