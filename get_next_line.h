/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:16:10 by orazafin          #+#    #+#             */
/*   Updated: 2017/03/14 16:49:45 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//NE PAS OUBLIER D'ENLEVER LA LIBRAIRIE stdio!!!!!!!!!1

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUFF_SIZE 3

#include "../Libft/Libft.h"
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);

#endif
