/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:06:46 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/03/22 12:56:53 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	cc;
	unsigned char	*dest;
	unsigned char	*sour;
	size_t			i;

	cc = (unsigned char)c;
	dest = (unsigned char *) dst;
	sour = (unsigned char *) src;
	i = 0;
	while (i < n)
	{
		dest[i] = sour[i];
		if (sour[i] == cc)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
