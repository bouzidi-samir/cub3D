/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 10:31:07 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/08/21 14:25:33 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*final;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	j = 0;
	final = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2 + 1));
	if (!final)
		return (0);
	while (s1[i])
	{
		final[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		final[i] = s2[j];
		i++;
		j++;
	}
	final[i] = '\0';
	return (final);
}
