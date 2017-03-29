/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:40:17 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/29 09:34:56 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		line_break(char **str, char *tmp, char *buff, char **line)
{
	char *end_line;

	tmp = *str;
	end_line = ft_strchr((const char *)buff, '\n');
	*str = ft_strdup(end_line + 1);
	*end_line = '\0';
	*line = ft_strjoin((char const *)tmp, (char const *)buff);
	printf("--------------------> *line = %s\n", *line);
	// free(tmp);
	return (1);
}

int		end_reading(char **str, char **line)
{
	char *end_line;
	char *cpy;
	int	count_char;

	end_line = ft_strchr((const char *)*str, '\n');
	if (end_line != NULL && *(end_line +1))
	{
		count_char = ft_strlen(*str) - ft_strlen(end_line);
		if (!(cpy = malloc(sizeof(char) * count_char + 1)))
			return -1;
		cpy = ft_strncpy(cpy, *str, count_char);
		*str = ft_strdup(end_line + 1);
		*line = ft_strcpy(*line, cpy);
		printf("--------------------> *line = %s\n", *line);
		free(cpy);
		return (1);
	}
	*line = ft_strdup(*str);
	printf("str = %s\n", *str);
	free(*str);
	printf("str = %s\n", *str);
	printf("--------------------> *line = %s\n", *line);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char *str = NULL;
	char buff[BUFF_SIZE + 1];
	int read_octet;
	char *tmp;

	if (!line || fd < 0 || BUFF_SIZE <= 0)
		return (-1);
	while ((read_octet = read(fd, buff, BUFF_SIZE)) != 0)
	{
		buff[read_octet] = '\0';
		if (ft_strchr((const char *)buff, '\n') != 0)
			return (line_break(&str, tmp, buff, line));
		if (!str)
			str = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str, buff);
			free(str);
			str = tmp;
		}
	}
	return (end_reading(&str, line));
}