/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:15:36 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 01:18:09 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

char	*remove_caract(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	trimmed_str = ft_substr(s1, start, end - start);
	if (!trimmed_str)
		return (NULL);
	return (trimmed_str);
}

char	*remove_prefix(char *line, char *prefix)
{
	char	*substring;
	size_t	len_prefix;

	len_prefix = ft_strlen(prefix);
	substring = malloc(sizeof(char) * (ft_strlen(line) - len_prefix + 1));
	if (!substring)
		return (NULL);
	if (ft_strncmp(line, prefix, len_prefix) == 0)
		return (ft_strcpy(substring, line + len_prefix));
	else
		return (ft_strcpy(substring, line));
}

int	countline(char *file)
{
	char	*line;
	int		fd;
	int		count;
	char	*tmp;

	count = 0;
	fd = open(file, O_RDWR);
	if (fd < 0)
		return (ft_error("can't open file!"), exit(1), 0);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strtrim(line, " \n");
		if (ft_strlen(tmp) != 0)
			count++;
		free(tmp);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

void	findmaxline(t_map_info *game)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	game->maxlenmap = 0;
	while (game->map[i])
	{
		len = delet_espaces_at_the_end(game->map[i]);
		if (len > game->maxlenmap)
			game->maxlenmap = len;
		i++;
	}
	game->maxlenmap += 1;
}
