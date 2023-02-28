/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utis2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 20:16:13 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/28 20:15:53 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int numberofgamma(char *pathcolor)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while(pathcolor[i])
    {
        if(pathcolor[i] == ',')
            j++;
        i++;
    }
    return(j);
}

int checkgamma(char *pathcolor)
{
    int nbrofgamma;
    nbrofgamma = numberofgamma(pathcolor);
    if(nbrofgamma == 2)
        return(1);
    return(0);
}

int ft_isspace(int c) 
{
    return (c == ' ' || c == '\t');
}
void delet_espaces_at_the_end(char* chaine) 
{
    size_t longueur;
    int i;

    longueur = ft_strlen(chaine);
    i = longueur - 1;
    while ( i >= 0 && ft_isspace(chaine[i])) 
    {
        chaine[i] = '\0';
        i--;
    }
}
char    *get_str_without_spaces(char* chaine)
{
    delet_espaces_at_the_end(chaine);
    char* nouvelle_chaine = (char*)malloc((strlen(chaine) + 1) * sizeof(char));
    ft_strcpy(nouvelle_chaine, chaine);
    return (nouvelle_chaine);
}