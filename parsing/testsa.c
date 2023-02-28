/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsa.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmakboub <mmakboub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:00:52 by mmakboub          #+#    #+#             */
/*   Updated: 2023/02/21 23:35:31 by mmakboub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
char	*ft_substr(char const *s, unsigned int start, size_t len)

{
	size_t	firstc;
	char	*newstr;

	firstc = 0;
	if (!s)
		return (NULL);
	if (start > strlen(s))
	{
		newstr = malloc(1);
		if (!newstr)
			return (NULL);
		newstr[0] = '\0';
		return (newstr);
	}
	if (len > strlen(s))
		len = strlen(s);
	newstr = (char *)malloc(sizeof(char) * (len + 1));
	if (!newstr)
		return (NULL);
	while (firstc < len && start < strlen(s))
	{
		newstr[firstc++] = s[start++];
	}
	newstr[firstc] = '\0';
	return (newstr);
}
char	*remove_caract(char const *s1, char const *set)
{
	char	*trimmed_str;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);

	start = 0;
	while (s1[start] && strchr(set, s1[start]))
		start++;

	end = strlen(s1);
	while (end > start && strchr(set, s1[end - 1]))
		end--;

	trimmed_str = ft_substr(s1, start, end - start);
	if (!trimmed_str)
		return (NULL);

	return (trimmed_str);

}
int main(void)
{
    char *s1 = "hel lo world   \n  ";
    char *set = " \n";
    char *trimmed_str = remove_caract(s1, set);

    if (trimmed_str == NULL)
    {
        printf("Error: ft_strtrim returned NULL\n");
        return (1);
    }
	 char *s2 = "SO ./path_to_  the_south_texture";

    printf("Original string: \"%s\"\n", s1);
    printf("Set of characters to remove: \"%s\"\n", set);
    printf("Trimmed string: \"%s\"\n", trimmed_str);
    free(trimmed_str);
    return (0);
}