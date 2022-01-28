/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:06:18 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/03/26 11:19:01 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*str2;

	if ((dst == src) || n == 0)
		return (dst);
	if (!dst && !src)
		return (0);
	str = (unsigned char *)src;
	str2 = (unsigned char *)dst;
	while (n > 0)
	{
		*str2++ = *str++;
		n--;
	}
	return (dst);
}
