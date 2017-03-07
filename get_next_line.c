/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:15:53 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/07 17:56:39 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static int 		i = 0;
	static int		x = 0;
	int				read_octet;
	char			*buff;
	unsigned int	n;
	int				j;

	line = 0;
	j = 0;
	if (!(buff = malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	while ((i = read(fd, buff, BUFF_SIZE)) != 0 && (*line = buff))
	{
		buff[i] = 0;
		x += i;
	}
}
