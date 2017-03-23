/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:40:17 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/23 19:15:11 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		line_break(char *str, char *tmp, char *buff, char **line)
{
	char *end_line;

	tmp = str;
	end_line = ft_strchr((const char *)buff, '\n');
	str = ft_strdup(end_line + 1);
	printf("tmp dans line_break = %s\n", tmp);
    *end_line = '\0';
	*line = ft_strjoin((char const *)tmp, (char const *)buff);
	printf("*line = %s\n", *line);
	// free(tmp);
	printf("str dans line_break = %s\n", str);
	return (1);
}
int		get_next_line(int fd, char **line)
{
	static char *str = NULL;
	char buff[BUFF_SIZE + 1];
	int read_octet;
	char *tmp;

	printf("\n");
	printf("str au debut de GNL = %s\n", str);
	if (!fd)
		return (-1);
	while ((read_octet = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[read_octet] = '\0';
		if (ft_strchr((const char *)buff, '\n') != 0)
			return (line_break(str, tmp, buff, line));
		if (!str)
			str = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str, buff);
			free(str);
			str = tmp;
		}
	}
	return (0);
}
