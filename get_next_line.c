/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:39:34 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/08 16:12:10 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len;

	if (s1 == NULL)
		return (s2);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = ft_calloc(len, sizeof(char));
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, len + 1);
	ft_strlcat(res, s2, len + 1);
	free(s1);
	free(s2);
	return (res);
}

static void	ft_replace(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
}

static void	*free_line(char *line)
{
	if (line != NULL)
		free(line);
	return (NULL);
}

static int	find_line(char *buf, char **line)
{
	int		i;
	int		j;
	int		resp;
	char	*find_line;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	resp = 0;
	if (buf[i] == '\n')
		resp = 1;
	find_line = ft_calloc(i + resp + 1, 1);
	if (!find_line)
		return (-1);
	while (j < i + resp)
	{
		find_line[j] = buf[j];
		j++;
	}
	*line = ft_strjoin(*line, find_line);
	if (line == NULL)
		return (-1);
	ft_replace(buf, &buf[i + resp]);
	return (resp);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*line;
	int			flag_line;
	ssize_t		read_size;

	line = NULL;
	flag_line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (flag_line == 0)
	{
		flag_line = find_line(buf, &line);
		if (flag_line == -1)
			return (free_line(line));
		if (flag_line == 0)
		{
			read_size = read(fd, buf, BUFFER_SIZE);
			if (read_size == 0 && *line)
				flag_line = 1;
			else if (read_size <= 0)
				return (free_line(line));
			buf[read_size] = '\0';
		}
	}
	return (line);
}
