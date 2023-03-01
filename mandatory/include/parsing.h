/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:01:19 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/01 03:31:39 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARSING_H
# define __PARSING_H

# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_index
{
	size_t i;
	size_t j;
}t_index;

typedef struct s_map_info
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			**map;
	int				has_no;
	int				has_so;
	int				has_we;
	int				has_ea;
	int				maplines;
	int				lenghtlines;
	int				has_f;
	int				has_c;
	int				c_floor;
	int				c_ceilling;
	int				lineindex;
	size_t				maxlenmap;

}					t_map_info;

char				*remove_caract(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				extention(char *filename);
int					countline(char *file);
int					ft_reading_maps(t_map_info *jeu, char *file);
char				**remplir_tableau(void);
void				init_map_data(t_map_info *game);
void				free_tab(char **tab, int size);
int					check_intern_map(char *clean_ptr, t_map_info *game);
void				parse_direction(t_map_info *game, char *line);
void				ea_direct(t_map_info *game, char *line);
void				no_direct(t_map_info *game, char *line);
void				we_direct(t_map_info *game, char *line);
void				so_direct(t_map_info *game, char *line);
char				*ft_strcpy(char *dest, char *src);
char				*remove_prefix(char *line, char *prefix);
void				memory_error(void);
void				parse_color(t_map_info *game, char *cleanline);
int					receive_rgb_color(char *color);
int					isalldigits(const char *s);
int					rgb_converter(char **rgbclr);
int					parse_map(t_map_info *game, char *first_line, int fd);
int					valid_n(char **map, size_t i, size_t j);
int					valid_e(char **map, size_t i, size_t j);
int					valid_s(char **map, size_t i, size_t j, t_map_info *game);
int					valid_w(char **map, size_t i, size_t j);
int					check_valid_map(t_index index, char **map, t_map_info *game, int *counter);
int					checkmap(t_map_info *game);
int					check_path(t_map_info *game, char *cleanline);
void				check_retvalue(int retvalue, char *clean_ptr, t_map_info *game);
int 				base_parsing(char *file, t_map_info *game);
void 				findmaxline(t_map_info *game);
char 				*fillwithspace(char *line, t_map_info *game);
char 				*onlyspaces(int diff);
int 				numberofgamma(char *pathcolor);
int 				checkgamma(char *pathcolor);
int 				ft_isspace(int c);
size_t 				delet_espaces_at_the_end(char* chaine);
char    			*get_str_without_spaces(char* chaine);
void				ft_error(char *error_name);
#endif