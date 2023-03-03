/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:16:34 by mmakboub          #+#    #+#             */
/*   Updated: 2023/03/03 20:33:44 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 1
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h> 
# include <unistd.h>

char	*read_filles(int rd, char *rest, int fd, char *buffer);
char	*get_new_line(char *rest);
char	*get_new_rest(char *rest);
char	*get_next_line(int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin2(char *s1, char *s2);
#endif
