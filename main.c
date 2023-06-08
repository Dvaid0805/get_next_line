/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:40:11 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/08 15:10:20 by dbredykh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int			fd;
	const char	*filename;
	ssize_t		test;

	filename = "test.txt";
	fd = open(filename, O_RDONLY);
	printf("%s\n", get_next_line(fd));
	close(fd);
	printf("%s\n", get_next_line(fd));
	return (0);
}
