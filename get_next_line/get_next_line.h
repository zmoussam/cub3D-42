/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:16:34 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/20 00:35:20 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# define BUFFER_SIZE 1

char	*ft_strchr2(const char *s, int c);
size_t	ft_strlen2(const char *str);
char	*ft_substr2(char const *s, unsigned int start, size_t len);
char	*ft_strjoin2(char *s1, const char *s2);
char	*get_line(char *rest);
char	*rest_line(char *rest);
char	*get_next_line(int fd);
char	*ft_strdup2(const char *s1);
#endif
