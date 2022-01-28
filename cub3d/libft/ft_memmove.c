/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 09:07:18 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/01 11:19:05 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*x;
	char	*y;

	i = 0;
	x = (char *)dst;
	y = (char *)src;
	if (dst == src)
		return (dst);
	if (x > y)
	{
		while (i < len--)
			x[len] = y[len];
	}
	else
	{
		while (i < len)
		{
			x[i] = y[i];
			i++;
		}
	}
	return (dst);
}
