/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 10:40:17 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/25 13:23:59 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		line_break(char **str, char *tmp, char *buff, char **line)
{
	char *end_line;

	tmp = *str;
	end_line = ft_strchr((const char *)buff, '\n');
	*str = ft_strdup(end_line + 1);
	printf("str = %s\n", *str);
	*end_line = '\0';
	*line = ft_strjoin((char const *)tmp, (char const *)buff);
	printf("*line = %s\n", *line);
	// free(tmp);
	printf("str dans line_break = %s\n", *str);
	return (1);
}

int		end_reading(char **str, char **line)
{
	char *end_line;
	char *cpy;
	int	count_char;

	printf("str avant seach = %s\n", *str);
	end_line = ft_strchr((const char *)*str, '\n');
	printf("end_line = %s", end_line);
	if (end_line != NULL)
	{
		count_char = ft_strlen(*str) - ft_strlen(end_line);
		if (!(cpy = malloc(sizeof(char) * count_char + 1)))
			return -1;
		cpy = ft_strncpy(cpy, *str, count_char);
		*str = ft_strdup(end_line + 1);
		*line = ft_strcpy(*line, cpy);
		printf("*line = %s\n", *line);
		printf("str = %s\n", *str);
		free(cpy);
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

	printf("str au debut de GNL = %s\n", str);
	if (!fd)
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
