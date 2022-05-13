/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 01:42:15 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 01:43:29 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uint8_t
	ft_toupper(uint8_t character)
{
	if (ft_islower(character))
		return (character -= 32);
	else
		return (character);
}
