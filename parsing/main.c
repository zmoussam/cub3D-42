/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:06:29 by zmoussam          #+#    #+#             */
/*   Updated: 2022/11/19 03:40:33 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	_error(char *error_name)
{
	perror(error_name);
	exit(1);
}
void	check_extention(char *file_name)
{
	int		start;
	char	*extention;

	start = ft_strlen(file_name) - 4;
	extention = ft_substr(file_name, start, 4);
	if (ft_strcmp(".cub", extention) != 0)
	{
		free(extention);
		_error("extention must be .cub\n");
	}
	free(extention);
}

char	*get_texture_path(char *line)
{
	char *texture;
	
	texture = ft_strtrim(line, " \n");
	if (!texture)
		_error("Error: memory was not allocated!!\n");
	return (texture);
}

void	get_direction(t_info *infos, char *line, int *count)
{
	*count += 1;
	
	if (line[0] == 'N' && line[1] == 'O' && !infos->no)
		infos->no = get_texture_path(&line[2]);
	else if (line[0] == 'S' && line[1] == 'O' && !infos->so)
		infos->so = get_texture_path(&line[2]);
	else if (line[0] == 'W' && line[1] == 'E' && !infos->we)	
		infos->we = get_texture_path(&line[2]);
	else if (line[0] == 'E' && line[1] == 'A' && !infos->ea)
		infos->ea = get_texture_path(&line[2]);
}

int check_if_empty(char *color)
{
	int i;

	i = 0;
	if (color[0] == '\0')
		return (1);
	while (color[i])
	{
		if (color[i] != ' ' && ft_isdigit(color[i]))
			return (0);
		i++;
	}
	return (1);
}

int is_valid_rgb(int color)
{
	return (color >= 0 && color <= 255);
}

int	parse_color(char **colors)
{
	int i;
	int j;
	
	i = 0;
	while (colors[i])
	{
		j = 0;
		if (check_if_empty(colors[i]))
			return (0);
		while (colors[i][j])
		{
			if ((!ft_isdigit(colors[i][j]) && colors[i][j] != 32))
				return (0);
			j++;	
		}
		if(!is_valid_rgb(ft_atoi(colors[i])))
			return (0);
		i++;
	}
	if (i != 3)
		return (0);
	return (1);
}
void free_colors(char **colors)
{
	int i;
	i = 0;

	while(colors[i])
		free(colors[i++]);
	free(colors);
}

int	callcul_color(char *rgb_color)
{
	char	**colors;
	
	if (!rgb_color)
		return (_error("Error: memory was not allocated\n"), -1);
	colors = ft_split(rgb_color, ',');
	if (!colors)
		return (free(rgb_color), _error("Error: memory was not alocated\n"), -1);
	if (!parse_color(colors))
		return (free(rgb_color), free_colors(colors), _error("Error: invalide rgb color\n"), -1);
	return (ft_atoi(colors[0]) << 16 | ft_atoi(colors[1]) << 8 | ft_atoi(colors[2]));
}

void	get_color(t_info *infos, char *line, int *count)
{	
	*count += 1;
	if (line[0] == 'F' && infos->floor == -1)
		infos->floor = callcul_color(ft_strtrim(&line[1], " \n"));
	else if (line[0] == 'C' && infos->ceilling == -1)
		infos->ceilling = callcul_color(ft_strtrim(&line[1], " \n"));
		
}

int get_map_token(char *line)
{
	int size;
	
	size = ft_strlen(line);
	if ((line[0] == 'F' || line[0] == 'C') && line[1] == ' ')
		return (RGB_COLOR);
	else if (line[0] == '1')
		return (MAP);
	else if (line[0] == '\0')
		return (EMPTY_LINE);
	else if (size > 3 && \
		((line[0] == 'N' && line[1] == 'O' && line[2] == ' ') \
		|| (line[0] == 'S' && line[1] == 'O' && line[2] == ' ') \
		|| (line[0] == 'E' && line[1] == 'A' && line[2] == ' ') \
		|| (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')))
		return (DIRECTION);
	else 
		return (INVALIDE_LINE);
	
}

int check_wals(char *border, int index)
{
	int i;

	i = 0;
	if (index == 0)
	{
		while (border[i])
		{
			if (border[i] != '1' && border[i] != 32 && border[i] != '\n')
				return (0);
			i++;
		}	
	}
	else if (border[0] != '1' || border[ft_strlen(border) - 2] != '1')
		return (0);
	return (1);
}

int	get_map_height(int fd)
{
	int map_height;
	char	*line;

	map_height = 1;
	line = get_next_line(fd);
	while (line)
	{
		map_height++;
		free(line);
		line = get_next_line(fd);
	}
	return (map_height);
}

int	get_map(int fd, t_info *infos, char *first_line)
{
	int		map_height;

	
	(void)infos;
	if (!first_line)
		return (printf("Error: map not found"), 0);
	if (!check_wals(first_line, 0))
		return (printf("Error: invalide map's walls!!\n"), free(first_line), 0);
	free (first_line);
	map_height = get_map_height(fd);
	close(fd);
	infos->map = (char **)malloc(sizeof(char *) * (map_height + 1));
	if (!infos->map)
		return (printf("Error: memory was not allocated!!\n"), 0);
	
	return (1);
	
}

int	get_info(t_info *infos, int fd)
{
	char		*tmp_line;
	char		*line;
	int			count;
	int			token;

	count = 0;
	tmp_line = get_next_line(fd);
	if (!tmp_line)
		return (printf("Error: empty map's file!!\n"), 0);
	while (tmp_line)
	{
		line = ft_strtrim(tmp_line, " \n");
		if (!line)
			return (printf("Error: memory was not allocated!!\n"), 0);
		token = get_map_token(line);
		if (token == MAP)
			break ;
		else if (token == EMPTY_LINE)
		{
			free(line);
			tmp_line = get_next_line(fd);
			continue;
		}
		else if (token == RGB_COLOR)
			get_color(infos, line, &count);
		else if (token == DIRECTION)
			get_direction(infos, line, &count);
		else if (token == INVALIDE_LINE)
			return (printf("Error: invalid map's informations!!\n"), free(tmp_line), free(line), 0);
		free(tmp_line);
		tmp_line = get_next_line(fd);
	}
	if (count != 6 || infos->ceilling == -1 || infos->floor == -1 \
		|| !infos->ea || !infos->no || !infos->we || !infos->so)
		return (printf("Error: invalid map's informations!!\n"), 0);
	if (!get_map(fd, infos, tmp_line))
		return (0);
	return (1);
}

int parsing(t_info *infos, char *file_name)
{
	int		fd;
	
	check_extention(file_name);
	fd = open(file_name, O_RDWR);
	if (fd == -1)
		return (printf("Error: %s\n", strerror(errno)), 0);
	if (!get_info(infos, fd))
		return (0);
	return (1);
}
#include<stdio.h>
int main(int ac, char **argv)
{
	t_info info;
	
	info.ea = NULL;
	info.no = NULL;
	info.so = NULL;
	info.we = NULL;
	info.floor = -1;
	info.ceilling = -1;
    if (ac != 2)
		_error("cub3d: error: invalid argument!!\n");
	if (!parsing(&info, argv[1]))
		exit(1);
	// map_height = get_map
	printf("NO = %s\n", info.no);
	printf("SO = %s\n", info.so);
	printf("EA = %s\n", info.ea);
	printf("we = %s\n", info.we);
	printf("floor = %d\n", info.floor);
	printf("ceilling = %d\n", info.ceilling);

	// printf("trim = %s\n", ft_strtrim("\n", " \n"));
	
}