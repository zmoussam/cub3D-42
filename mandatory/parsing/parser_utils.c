/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:15:36 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/28 21:29:58 by zmoussam         ###   ########.fr       */
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

	len_prefix = strlen(prefix);
	substring = malloc(sizeof(char) * (ft_strlen(line) - len_prefix + 1));
	if (!substring)
		return (NULL);
	if (strncmp(line, prefix, len_prefix) == 0)
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
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			close(fd);
			break ;
		}
		tmp = remove_caract(line, " \n");
		if (ft_strlen(tmp))
			count++;
		free(tmp);
		free(line);
	}
	return (count);
}

void findmaxline(t_map_info *game)
{
	int i;
	size_t len;

	i = 0;
	game->maxlenmap = 0;
	while (game->map[i])
	{
		char* ligne = get_str_without_spaces(game->map[i]);
        len = strlen(ligne);
		//len = ft_strlen(game->map[i]) - 1;
		if (len > game->maxlenmap)
			game->maxlenmap = len;
		i++;
		free(ligne);
	}
}

char *fillwithspace(char *line, t_map_info *game)
{
	int i;
	char *tab;
	char *strspaces;

	tab = NULL;
	i = 0;
	if(ft_strlen(line) < game->maxlenmap)
	{
		int diff = game->maxlenmap - ft_strlen(line);
		strspaces = onlyspaces(diff);
		tab = ft_strjoin(line, strspaces);
	}
	else if(ft_strlen(line) == game->maxlenmap)
		return(line);
	return(tab);
}

char *onlyspaces(int diff)
{
	char *str;
	int i;

	i = 0;
	str = (char *)malloc(sizeof(char *) * diff + 1);
	if(!str)
		return (NULL);
	while(i < diff)
	{
		str[i] = ' ';
		i++;
	}
	return(str);
}