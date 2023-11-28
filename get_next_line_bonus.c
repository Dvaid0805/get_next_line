/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:39:34 by dbredykh          #+#    #+#             */
/*   Updated: 2023/11/28 13:17:27 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*del_stash_line(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_stash = NULL;
	if (stash == NULL)
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (free(stash), NULL);
	new_stash = ft_calloc(ft_strlen(stash, 0) - i + 1, sizeof(char));
	if (!new_stash)
		return (free(stash), NULL);
	i++;
	while (stash[i] != '\0')
		new_stash[j++] = stash[i++];
	free(stash);
	if (new_stash[0] == '\0')
		return (free(new_stash), NULL);
	return (new_stash);
}

static char	*fill_line(char *stash)
{
	char	*line;
	size_t	i;
	size_t	len;

	i = 0;
	line = NULL;
	if (!stash || stash[0] == '\0')
		return (NULL);
	len = ft_strlen(stash, 1) + 1;
	if (!len)
		return (NULL);
	line = ft_calloc(sizeof(char), len);
	if (!line)
		return (free(stash), NULL);
	while (stash[i] != '\0' && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] != '\0' && stash[i] == '\n')
		line[i++] = '\n';
	return (line);
}

static char	*read_line(int fd, char *stash)
{
	char	*buff;
	int		buff_flag;

	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	buff_flag = 1;
	while (buff_flag > 0 && !ft_strrchar(buff, '\n'))
	{
		buff_flag = read(fd, buff, BUFFER_SIZE);
		buff[buff_flag] = '\0';
		stash = ft_strjoin(stash, buff);
		if (!stash)
			return (free(stash), NULL);
	}
	if (stash && stash[0] == '\0')
		return (free(stash), free(buff), NULL);
	return (free(buff), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	if (read(fd, NULL, 0) == -1)
	{
		if (stash[fd])
			free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	if (!stash[fd])
	{
		stash[fd] = ft_calloc(sizeof(char), 1);
		if (!stash[fd])
			return (NULL);
	}
	stash[fd] = read_line(fd, stash[fd]);
	line = fill_line(stash[fd]);
	stash[fd] = del_stash_line(stash[fd]);
	return (line);
}
