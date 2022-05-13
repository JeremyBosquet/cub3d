/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:04:48 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/03 21:41:33 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*list;

	list = lst;
	if (!list)
		return ;
	while (list->next != 0)
	{
		f(list->line);
		list = list->next;
	}
	f(list->line);
}
