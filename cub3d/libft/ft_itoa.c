/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbouzidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 07:34:51 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/04/01 09:02:34 by sbouzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(int n)
{
	int		size;
	long	nbr;

	nbr = n;
	size = 1;
	if (nbr < 0)
	{
		size++;
		nbr *= (-1);
	}
	while (nbr >= 10)
	{
		size++;
		nbr /= 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nbr;
	int		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * ft_size(n) + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[0] = '-';
	nbr = n;
	if (nbr < 0)
		nbr *= (-1);
	str[ft_size(n) - i++] = '\0';
	while (nbr >= 10)
	{
		str[ft_size(n) - i++] = (nbr % 10) + '0';
		nbr /= 10;
	}
	str[ft_size(n) - i++] = (nbr % 10) + '0';
	return (str);
}
