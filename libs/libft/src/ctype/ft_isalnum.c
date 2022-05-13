/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:24:41 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 01:55:42 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool
	ft_isalnum(uint8_t c)
{
	if (ft_isdigit(c) || ft_isupper(c) || ft_islower(c))
		return (true);
	else
		return (false);
}
