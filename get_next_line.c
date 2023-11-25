/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:39:34 by dbredykh          #+#    #+#             */
/*   Updated: 2023/11/25 21:32:36 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*del_stash_line(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	new_stash = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!new_stash)
		return (NULL);
	i++;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

static char	*ft_strjoin(char *stash, char *buff)
{
	char	*str;
	int		i;
	int		j;

	str = malloc(sizeof(char) * (ft_strlen(stash) + ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (stash[i])
	{
		str[i] = stash[i];
		i++;
	}
	while (buff[j])
	{
		str[i] = buff[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(stash);
	return (str);
}

static char	*fill_line(char *stash)
{
	char	*line;
	int		i;

	i = 0;
	while (stash[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] != '\n')
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

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	buff_flag = 1;
	while (buff_flag > 0)
	{
		buff_flag = read(fd, buff, BUFFER_SIZE);
		if (buff_flag == -1)
			return (NULL);
		buff[buff_flag] = '\0';
		if (strrchr(buff, '\n') != NULL)
			buff_flag = -1;
		stash = ft_strjoin(stash, buff);
		if (!stash)
			return (NULL);
	}
	free(buff);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char 	*stash;
	char	        *line;

	stash = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_line(fd, stash);
	line = fill_line(stash);
	stash = del_stash_line(stash);
	return (line);
}

int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	printf ("res: %s\n", get_next_line(fd));
	printf ("res: %s\n", get_next_line(fd));
	return (0);
}
