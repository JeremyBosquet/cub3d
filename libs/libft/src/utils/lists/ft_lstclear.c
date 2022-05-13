/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:01:36 by mmosca            #+#    #+#             */
/*   Updated: 2022/03/03 21:41:33 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*list;
	t_list	*tmp;

	list = *lst;
	if (!list)
		return ;
	while (list->next != 0)
	{
		tmp = list->next;
		ft_lstdelone(list, del);
		list = tmp;
	}
	ft_lstdelone(list, del);
	*lst = NULL;
}
