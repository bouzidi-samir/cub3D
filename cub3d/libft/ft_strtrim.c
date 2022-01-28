/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 10:33:15 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/03/29 14:20:53 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
	{
		i++;
	}
	len = ft_strlen(&s1[i]);
	while (s1[i + len - 1] && ft_strchr(set, s1[i + len - 1]) != NULL)
	{
		len--;
	}
	return (ft_substr(s1, i, len));
}
