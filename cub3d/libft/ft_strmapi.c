/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 07:06:33 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/01 07:08:00 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		i;

	if (!s || !f)
		return (NULL);
	ret = ft_strdup(s);
	if (!ret)
		return (NULL);
	i = 0;
	while (ret[i])
	{
		ret[i] = (*f)(i, ret[i]);
		i++;
	}
	return (ret);
}
