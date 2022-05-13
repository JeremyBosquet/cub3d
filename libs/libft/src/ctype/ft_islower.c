/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:18:54 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 01:22:29 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool
	ft_islower(uint8_t character)
{
	if (character >= 'a' && character <= 'z')
		return (true);
	else
		return (false);
}
