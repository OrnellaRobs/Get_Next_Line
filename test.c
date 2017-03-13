/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:40:17 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/13 17:47:34 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFF_SIZE 2

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;
	int		end;

	i = 0;
	str = (char *)s;
	end = ft_strlen(s);
	if (c == '\0')
		return (&str[end]);
	while ((char)str[i] != '\0')
	{
		if ((char)str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}

int		open_file(char const *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	return (fd);
}

int		end_read(char *buff, static char *str, int read_octet)
{
	char *tmp;
	char *line_break;

	if (read_octet != 0)
	{
		buff[read_octet] = '\0';
		tmp = ft_strjoin((char const *)str, (char const *)buff));
		free(str);
		str = tmp;
		line_break = ft_strchr((char const *)str, '\n');
		str[line_break] = '\0';
		*line = ft_strdup(str);
		if (read_octet != 0)
			return (1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *str = NULL;
	char buff[BUFF_SIZE + 1];
	int read_octet;
	char *tmp;

	if (!fd)
		return (-1);
	while ((read_octet = read(fd, buff, BUFF_SIZE)) != 0 && (ft_strchr((const char *)buff, '\n') == 0)
	{
		buff[read_octet] = '\0';
		tmp = ft_strjoin((char const *)str, (char const *)buff));
		free(str);
		str = tmp;
	}
	return end_red(buff, str, read_octet);
}

int		main(int argc, char const *argv[])
{
	int fd;
	int value;
	char *line;

	if ((fd = open_file(argv[1])) == -1)
		return (-1);
	value = get_next_line(fd, &line);
	return (0);
}
