/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjalloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 18:03:09 by mjalloul          #+#    #+#             */
/*   Updated: 2021/12/09 18:10:51 by mjalloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*read_line(char *s, int fd)
{
	int		e;
	char	*p;

	e = 0;
	p = malloc(sizeof(char ) * (BUFFER_SIZE + 1));
	if (!p)
		return (0);
	while (1)
	{
		e = read(fd, p, BUFFER_SIZE);
		if (e == -1 || (e == 0 && s[0] == '\0'))
		{
			free(s);
			s = NULL;
			free(p);
			return (0);
		}
		p[e] = '\0';
		s = ft_strjoin(s, p);
		if (ft_strchr(p, '\n') == 1 || !e)
			break ;
	}
	free(p);
	return (s);
}

char	*get_next_line(int fd)
{
	static char		*s[1024];
	char			*rest;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!s[fd])
		s[fd] = ft_strdup("");
	s[fd] = read_line(s[fd], fd);
	if (s[fd] == NULL)
		return (0);
	line = ft_strdup1(s[fd]);
	rest = ft_strdup(s[fd] + ft_strlen(line));
	free(s[fd]);
	s[fd] = rest;
	return (line);
}
