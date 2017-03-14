/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:40:17 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/14 18:02:19 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		open_file(char const *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	return (fd);
}
//
// int		end_read(char *buff, static char *str, int read_octet)
// {
// 	char *tmp;
// 	char *line_break;
//
// 	if (read_octet != 0)
// 	{
// 		buff[read_octet] = '\0';
// 		line_break = ft_strchr((char const *)str, '\n');
// 		str[line_break] = '\0';
// 		*line = ft_strdup((const char *)str);
// 		if (read_octet != 0)
// 			return (1);
// 	}
// 	return (0);
// }

int		get_next_line(int fd, char **line)
{
	static char *str = NULL;
	char buff[BUFF_SIZE + 1];
	int read_octet;
	char *tmp;
	char *tmp1;

	if (!fd)
		return (-1);
	while ((read_octet = read(fd, buff, BUFF_SIZE)) != 0
	&& (tmp1 = ft_strchr((const char *)buff, '\n')) == 0)
	{
		buff[read_octet] = '\0';
		if (!str)
			str = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin((char const *)str, (char const *)buff);
			free(str);
			str = tmp;
		}
	}
	tmp = str;
	str = ft_strdup(tmp1 + 1);
	*tmp1 = 0;
	*line = ft_strjoin(tmp, tmp1);
	free(tmp);
	printf("%s\n", str);
	return (0);
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
