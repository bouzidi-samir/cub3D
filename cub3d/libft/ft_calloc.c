/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 13:16:17 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/01 11:20:00 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*s;	

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	s = malloc(count * size);
	if (!s)
	{
		return (NULL);
	}	
	ft_bzero(s, count * size);
	return (s);
}
