/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:01:19 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/28 19:47:48 by zmoussam         ###   ########.fr       */
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

typedef struct s_cordinates
{
	double			x;
	double			y;
}					t_cordinates;

typedef struct s_abtmap
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
	int				floor;
	int				ceilling;
	int				lineindex;
	size_t				maxlenmap;

}					t_abtmap;

char				*remove_caract(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
void				ft_check_cub(char *filename);
int					countline(char *file);
int					ft_reading_maps(t_abtmap *jeu, char *file);
char				**remplir_tableau(void);
void				initializer(t_abtmap *game);
void				free_tab(char **tab, int size);
int					check_intern_map(char *clean_ptr, t_abtmap *game);
void				parse_direction(t_abtmap *game, char *line);
void				ea_direct(t_abtmap *game, char *line);
void				no_direct(t_abtmap *game, char *line);
void				we_direct(t_abtmap *game, char *line);
void				so_direct(t_abtmap *game, char *line);
char				*ft_strcpy(char *dest, char *src);
char				*remove_prefix(char *line, char *prefix);
void				memory_error(void);
void				parse_color(t_abtmap *game, char *cleanline);
int					receive_rgb_color(char *color);
int					isalldigits(const char *s);
int					rgb_converter(char **rgbclr);
int					parse_map(t_abtmap *game, char *first_line, int fd);
int					valid_n(char **map, size_t i, size_t j);
int					valid_e(char **map, size_t i, size_t j);
int					valid_s(char **map, size_t i, size_t j, t_abtmap *game);
int					valid_w(char **map, size_t i, size_t j);
int					check_valid_map(t_index index, char **map, t_abtmap *game, int *counter);
int					checkmap(t_abtmap *game);
int					check_path(t_abtmap *game, char *cleanline);
void				check_retvalue(int retvalue, char *clean_ptr, t_abtmap *game);
int 				base_parsing(char *file, t_abtmap *game);
void 				findmaxline(t_abtmap *game);
char 				*fillwithspace(char *line, t_abtmap *game);
char 				*onlyspaces(int diff);
int 				numberofgamma(char *pathcolor);
int 				checkgamma(char *pathcolor);
int 				ft_isspace(int c);
void 				delet_espaces_at_the_end(char* chaine);
char    			*get_str_without_spaces(char* chaine);
#endif