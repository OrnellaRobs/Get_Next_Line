/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/30 16:44:30 by orazafin          #+#    #+#             */
/*   Updated: 2017/04/06 19:47:18 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file		*ft_create_element(int fd)
{
	t_file	*new_elem;

	new_elem = NULL;
	if (!(new_elem = malloc(sizeof(t_file))))
		return (NULL);
	if (new_elem)
	{
		new_elem->fd = fd;
		new_elem->str = ft_strnew(0);
		new_elem->next = NULL;
	}
	return (new_elem);
}

static void			ft_push_back(t_file **list, int fd)
{
	t_file	*tmp;

	tmp = *list;
	if (!tmp)
		*list = ft_create_element(fd);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_element(fd);
	}
}

static t_file		*select_file(t_file **list, int fd)
{
	t_file	*tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	ft_push_back(list, fd);
	return (select_file(list, fd));
}

static int			end_of_line(char **str, char *buff, char **line,
	char *line_break)
{
	char	*eol;
	char	*save;

	save = *str;
	if (!line_break && (eol = ft_strchr(buff, '\n')))
	{
		if (*(eol + 1))
			*str = ft_strdup(eol + 1);
		else
			*str = ft_strnew(0);
		*eol = '\0';
		*line = ft_strjoin(save, buff);
		free(save);
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

int					get_next_line(int fd, char **line)
{
	static	t_file	*list;
	char			buff[BUFF_SIZE + 1];
	char			*line_break;
	t_file			*save;
	ssize_t			read_octet;

	read_octet = 0;
	save = select_file(&list, fd);
	if (!(line) || (save->fd) < 0 || BUFF_SIZE <= 0)
		return (-1);
	while (!(line_break = ft_strchr(save->str, '\n')) &&
	(read_octet = read(save->fd, buff, BUFF_SIZE)))
	{
		if (read_octet == -1)
			return (-1);
		buff[read_octet] = '\0';
		if (ft_strchr(buff, '\n'))
			return (end_of_line(&(save->str), buff, line, line_break));
		save->tmp = save->str;
		save->str = ft_strjoin(save->str, buff);
		free(save->tmp);
	}
	if (read_octet == 0 && (ft_strncmp(save->str, "", 1)))
		return (end_of_line(&(save->str), buff, line, line_break));
	return (0);
}
