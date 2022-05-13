/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:49:52 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 16:52:56 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_putnbr(uint16_t fildes, int n)
{
	uint32_t	nb;

	if (n < 0)
	{
		ft_putchar(fildes, '-');
		nb = (-n);
	}
	else
		nb = n;
	while (nb > 9)
		ft_putnbr(fildes, (nb / 10));
	ft_putchar(fildes, (nb % 10 + '0'));
}
