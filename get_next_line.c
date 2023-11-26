/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:39:34 by dbredykh          #+#    #+#             */
/*   Updated: 2023/11/26 20:17:05 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*del_stash_line(char **stash)
{
	char	*new_stash;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	new_stash = NULL;
	if ((*stash) == NULL || (*stash)[0] == '\0')
		return (NULL);
	while ((*stash)[i] != '\n')
		i++;
	len = ft_strlen(*stash) - i + 1;
	if (len > 0)
	{
		new_stash = ft_calloc(sizeof(char), len);
		if (!new_stash)
			return (free((*stash)), NULL);
		i++;
		while ((*stash)[i])
			new_stash[j++] = (*stash)[i++];
		new_stash[j] = '\0';
	}
	return (free(*stash), new_stash);
}

static char	*fill_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	if (!stash || stash[0] == '\0')
		return (0);
	while (stash[i] && stash[i] != '\n')
		i++;
	if (i > 0)
		line = ft_calloc(sizeof(char), (i + 1 + (stash[i] == '\n')));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*read_line(int fd, char *stash)
{
	char	*buff;
	int		buff_flag;

	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	buff_flag = 1;
	while (buff_flag > 0 && !ft_strrchar(buff, '\n'))
	{
		buff_flag = read(fd, buff, BUFFER_SIZE);
		buff[buff_flag] = '\0';
		if (buff[0] != '\0')
			stash = ft_strjoin(&stash, buff);
	}
	if (stash && stash[0] == '\0')
		return (free(stash), free(buff), NULL);
	return (free(buff), stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	line = NULL;
	if (!stash)
		stash = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = read_line(fd, stash);
	line = fill_line(stash);
	stash = del_stash_line(&stash);
	return (line);
}

/* int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	printf ("res: %s\n", get_next_line(fd));
	printf ("res: %s\n", get_next_line(fd));
	printf ("res: %s\n", get_next_line(fd));
	return (0);
} */
