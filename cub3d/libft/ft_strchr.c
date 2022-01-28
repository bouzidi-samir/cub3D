/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 07:56:27 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/03/26 14:49:59 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cr;
	char	*str;

	i = 0;
	cr = (char) c;
	str = (char *) s;
	while (s[i])
	{
		if (str[i] == cr)
		{	
			return (str + i);
		}
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return (str + i);
	return (NULL);
}
