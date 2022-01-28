/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samirbouzidi <samirbouzidi@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 07:28:54 by sbouzidi          #+#    #+#             */
/*   Updated: 2021/08/21 14:25:11 by samirbouzid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int				get_next_line(int fd, char **line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int				count(char *str);
int				check_line(int fd, char **str);
void			check_empty(char **str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(char const *s1);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strchr(char const *s, int c);
size_t			ft_strlen(char const *s);

#endif
