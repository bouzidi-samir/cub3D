/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 08:44:06 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/03/26 11:59:32 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	cr;
	char	*str;

	cr = (char) c;
	str = (char *) s;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == cr)
		{	
			return (str + i);
		}
		i--;
	}
	if (s[i] == '\0' && c == '\0')
		return (str + i);
	return (NULL);
}
