/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 16:14:50 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/23 17:06:42 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "Libft/libft.h"
# define BUFF_SIZE 3

int		line_break(char *str, char *buff, char *tmp, char **line)
{
	char *end_line;

	end_line = ft_strchr((const char *)buff, '\n');
	if (end_line)
	{
		str = ft_strdup(end_line + 1);
		*end_line = 0;
		*line = ft_strjoin((char const*)tmp, (char const *)buff);
		free(tmp);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char buff[BUFF_SIZE + 1];
	static char *str = NULL;
	int read_octet;
	char *tmp;

	if (!line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	while ((read_octet = read(fd, buff, BUFF_SIZE)))
	{
		if (ft_strchr((const char *)buff, '\n'))
			return (line_break(str, buff, tmp, line));
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
