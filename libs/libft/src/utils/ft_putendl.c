/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:47:40 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 16:49:31 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_putendl(uint16_t fildes, char *s)
{
	ft_putstr(fildes, s);
	ft_putchar(fildes, '\n');
}
