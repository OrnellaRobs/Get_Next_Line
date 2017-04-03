/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:44:30 by orazafin          #+#    #+#             */
/*   Updated: 2017/04/03 12:25:39 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int         linebreak(char **str, char *buff, char **line, char *line_break)
{
	char *eof;
	char *save;

	save = *str;
	if (!line_break && (eof = ft_strchr(buff, '\n')))
	{
		if (*(eof + 1))
			*str = ft_strdup(eof + 1);
		else
			*str = "";
		*eof = '\0';
		*line = ft_strjoin(save, buff);
		return (1);
	}
	else if (line_break)
	{
		*str = ft_strdup(line_break + 1);
		*line_break = '\0';
		*line = ft_strdup(save);
		return (1);
	}
	*str = "";
	*line = ft_strdup(save);
	return (1);
}

int	get_next_line(int fd, char **line)
{
    static char *str = "";
	char buff[BUFF_SIZE + 1];
	ssize_t read_octet;
	char	*line_break;
	char	*tmp = NULL;

	read_octet = 0;
	if (!(line) || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while (!(line_break = ft_strchr(str, '\n')) && (read_octet = read(fd, buff, BUFF_SIZE)))
	{
		if (read_octet == -1)
			return (-1);
		buff[read_octet] = '\0';
		if (ft_strchr(buff, '\n'))
			return (linebreak(&str, buff, line, line_break));
		tmp = ft_strjoin(str, buff);
		str = tmp;
	}
	if (read_octet == 0 && (ft_strncmp(str, "", 1)))
		return(linebreak(&str, buff, line, line_break));
	if (read_octet == 0)
		*line = "";
	return (0);
}
