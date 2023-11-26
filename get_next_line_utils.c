/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:34:46 by dbredykh          #+#    #+#             */
/*   Updated: 2023/11/26 20:19:16 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t size, size_t count)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)malloc(size * count);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (size * count))
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

char	*ft_strjoin(char **stash, char *buff)
{
	char	*str;
	int		i;
	int		j;

	str = ft_calloc(sizeof(char), (ft_strlen(*stash) + ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while ((*stash)[i])
	{
		str[i] = (*stash)[i];
		i++;
	}
	while (buff[j])
	{
		str[i] = buff[j];
		i++;
		j++;
	}
	return (free(*stash), str);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchar(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i + 1);
		i--;
	}
	return (NULL);
}
