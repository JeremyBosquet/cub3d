/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:37:35 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 01:38:39 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t
	ft_tolower(uint8_t character)
{
	if (ft_isupper(character))
		return (character += 32);
	else
		return (character);
}
