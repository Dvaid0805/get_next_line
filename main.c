/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:23:11 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/10 22:17:35 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_leaks(void)
{
	system ("leaks -q test");
}
// pa checkear lick de memoria

int	main(void)
{
	int		fd;
	char	*line;

	atexit(ft_leaks);
	fd = open("hola.txt", 0);
	get_next_line(fd);
	printf("main: %s\n", line);
	free(line);
	return (0);
}

/* fd = open("hola.txt", 0); en vez de O_RDONLY */
/* char *line = get_next_line(0);   */
