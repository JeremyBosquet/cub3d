/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:12:37 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/03 21:41:33 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint32_t
	ft_lstsize(t_list *list)
{
	uint32_t	length;

	length = 0;
	while (list != 0)
	{
		list = list->next;
		length++;
	}
	return (length);
}
