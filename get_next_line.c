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

t_file	*ft_create_element(int fd)
{
    t_file *new_elem;

    new_elem = NULL;
    if (!(new_elem = malloc(sizeof(t_file))))
        return (NULL);
    if (new_elem)
    {
        new_elem->fd = fd;
        new_elem->str = "";
        new_elem->next = NULL;
    }
    return (new_elem);
}

void    ft_push_back(t_file **list, int fd)
{
    t_file *tmp;
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

t_file      *select_file(t_file **list, int fd)
{
    t_file *tmp;

    tmp = *list;
    while (tmp)
    {
        if (tmp->fd == fd)
            return (*list);
        tmp = tmp->next;
    }
   ft_push_back(list, fd);
    return (*list);
}

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
    static t_file *list;
    char buff[BUFF_SIZE + 1];
    ssize_t read_octet;
    char	*line_break;
    char	*tmp = NULL;
    t_file *save;

    select_file(&list, fd);
    save = list;
    while (save->fd != fd)
        save = save->next;
    read_octet = 0;
    if (!(line) || (save->fd) < 0 || BUFF_SIZE <= 0)
        return (-1);
    while (!(line_break = ft_strchr(save->str, '\n')) && (read_octet = read(save->fd, buff, BUFF_SIZE)))
    {
        if (read_octet == -1)
            return (-1);
        buff[read_octet] = '\0';
        if (ft_strchr(buff, '\n'))
            return (linebreak(&(save->str), buff, line, line_break));
        tmp = ft_strjoin(save->str, buff);
        save->str = tmp;
    }
    if (read_octet == 0 && (ft_strncmp(save->str, "", 1)))
        return(linebreak(&(save->str), buff, line, line_break));
    if (read_octet == 0)
        *line = "";
    return (0);
}
