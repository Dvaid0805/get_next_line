/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 21:23:11 by dbredykh          #+#    #+#             */
/*   Updated: 2023/08/25 20:16:28 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_leaks(void)
{
	system ("leaks -q test");
}

int	main(void)
{
	int		fd;
	char	*line;

	atexit(ft_leaks);
	fd = open("test.txt", 0);
	line = get_next_line(fd);
	printf("main: %s\n", line);
	free(line);
	return (0);
}

/*
	usage of valgrind:
		gcc -g main.c get_next_line_utils.c get_next_line.c
		valgrind --leak-check=yes ./a.out
*/
