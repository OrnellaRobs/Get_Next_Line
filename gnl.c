/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 17:01:42 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/23 18:24:48 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line);

int		open_file(char const *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

int		main(int argc, char const *argv[])
{
	int fd;
	int value;
	char *line;

	argc++;
	if ((fd = open_file(argv[1])) == -1)
		return (-1);
	value = get_next_line(fd, &line);
	printf("value = %d\n", value);
	value = get_next_line(fd, &line);
	printf("value = %d\n", value);
	value = get_next_line(fd, &line);
	printf("value = %d\n", value);
	return (0);
}
