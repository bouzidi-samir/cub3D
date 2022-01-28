/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 07:24:57 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/08/21 14:24:56 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	count(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

int	check_line(int fd, char **str)
{
	char	*stock;
	char	buf[BUFFER_SIZE + 1];
	int		b;

	b = read(fd, buf, BUFFER_SIZE);
	if (b < 1)
		return (b);
	buf[b] = '\0';
	stock = ft_strjoin(*str, buf);
	free(*str);
	*str = stock;
	return (b);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		size;
	int		i;
	int		j;

	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	size = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * size + 1);
	if (!dest)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}

void	check_empty(char **str)
{
	if (*str == NULL)
		*str = ft_strdup("");
}

int	get_next_line(int fd, char **line)
{
	static char	*str = NULL;
	char		*buf;
	int			b;	

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, str, 0) < 0)
		return (-1);
	b = 1;
	check_empty(&str);
	while (!ft_strchr(str, '\n') && b)
		b = check_line(fd, &str);
	if (b < 0)
		return (-1);
	else if (b == 0)
		*line = ft_strdup(str);
	else
		*line = ft_substr(str, 0, count(str));
	buf = ft_substr(str, count(str) + 1, ft_strlen(str) - count(str));
	free(str);
	str = buf;
	if (b > 0)
		return (1);
	free(str);
	str = NULL;
	return (0);
}
