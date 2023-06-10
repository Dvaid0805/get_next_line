/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbredykh <dbredykh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:40:11 by dbredykh          #+#    #+#             */
/*   Updated: 2023/06/10 16:48:51 by dbredykh         ###   ########.fr       */
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
	printf("main: %s\n", get_next_line(fd));
	/* close(fd); */
	printf("main: %s\n", get_next_line(fd));
	return (0);
}
