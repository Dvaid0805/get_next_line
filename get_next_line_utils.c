/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:34:46 by dbredykh          #+#    #+#             */
/*   Updated: 2023/11/26 14:36:57 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *stash, char *buff)
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

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strrchar(char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i + 1);
		i--;
	}
	return (NULL);
}
