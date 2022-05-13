/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:11:03 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/03 21:41:33 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list
	*ft_lstnew(char *content, int width)
{
	t_list	*element;

	element = ft_calloc(sizeof(t_list), 1);
	if (!element)
		return (NULL);
	element->line = content;
	element->width = width;
	element->next = NULL;
	return (element);
}
