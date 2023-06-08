/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:09:45 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/08 14:42:02 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_bzero(void *s, size_t n)
{
	unsigned char	*new_str;

	new_str = (unsigned char *)s;
	while (n--)
		*new_str++ = '\0';
}

int	ft_strlen(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, char *src, size_t len)
{
	size_t	i;

	i = -1;
	if (!len)
		return (ft_strlen(src));
	while (src[++i] && i < (len - 1))
		dest[i] = src[i];
	dest[i] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dest, char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] && i < len)
		i++;
	while (src[j] && (i + j + 1) < len)
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i < len)
		dest[i + j] = '\0';
	return (i + ft_strlen(src));
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	len;

	len = count * size;
	str = malloc(len);
	if (!str)
		return (NULL);
	ft_bzero(str, len);
	return (str);
}
