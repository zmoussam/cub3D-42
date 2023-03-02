/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 21:27:05 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/02 18:30:48 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char	*read_filles(int rd, char *rest, int fd, char *buffer)
{
	while (rd != 0 && !ft_strchr(rest, '\n'))
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd < 0)
		{	
			free(buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		rest = ft_strjoin2(rest, buffer);
	}
	return (rest);
}

char	*get_new_line(char *rest)
{
	int		len;
	char	*str;

	len = 0;
	while (rest[len] && rest[len] != '\n')
		len++;
	str = ft_substr(rest, 0, len + 1);
	return (str);
}

char	*get_new_rest(char *rest)
{
	size_t	len;
	char	*str;

	len = 0;
	while (rest[len] && rest[len] != '\n')
		len++;
	str = ft_substr(rest, len + 1, ft_strlen(rest) - len + 1);
	free(rest);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*new_line;
	static char	*rest;
	int			rd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		exit(0);
	rd = 1;
	rest = read_filles(rd, rest, fd, buffer);
	if (!rest)
		return (NULL);
	if (!rest[0])
	{
		free(rest);
		free(buffer);
		rest = NULL;
		return (NULL);
	}
	new_line = get_new_line(rest);
	rest = get_new_rest(rest);
	free(buffer);
	return (new_line);
}