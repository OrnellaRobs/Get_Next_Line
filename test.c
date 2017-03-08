/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:40:17 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/08 15:10:36 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFF_SIZE 10

int		open_file(char const *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

int get_next_line(int fd, char **line)
{
	int 		read_octet;
	static int	i = 0;

	read_octet = read_file(fd);
	while (i < read_octet)
	{

	}
	return (0);
}

int		read_file(int fd)
{
	char *buff;
	int value;
	int read_octet;

	value = 0;
	read_octet = 0;
	if (!(buff = malloc(sizeof(char *) * BUFF_SIZE + 1)))
		return (-1);
	while ((read_octet = read(fd, buff, BUFF_SIZE)) != 0)
		value += read_octet;
	return (value);
}

int		main(int argc, char const *argv[])
{
	int fd;
	int value;

	if ((fd = open_file(argv[1])) == -1)
		return (-1);
	value = read_file(fd);
	return (0);
}
