/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmoussam <zmoussam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 02:50:56 by zmoussam          #+#    #+#             */
/*   Updated: 2021/11/29 18:39:03 by zmoussam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (!alst || !new)
		return ;
	temp = *alst;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}
