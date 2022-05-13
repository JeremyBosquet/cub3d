/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmosca <mmosca@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:24:39 by mmosca            #+#    #+#             */
/*   Updated: 2022/02/28 16:30:28 by mmosca           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static uint8_t
	nb_len(int n)
{
	uint8_t	length;

	length = 1;
	if (n < 0)
		n = (-n);
	while (n > 9)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char
	*ft_itoa(int n)
{
	uint8_t	length;
	char	*str;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	length = nb_len(n);
	if (n < 0)
	{
		n = (-n);
		length++;
	}
	str = ft_calloc((length + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (n > 9)
	{
		str[length - 1] = n % 10 + '0';
		length--;
		n /= 10;
	}
	str[length - 1] = n % 10 + '0';
	length--;
	if (length > 0)
		str[length - 1] = '-';
	return (str);
}
