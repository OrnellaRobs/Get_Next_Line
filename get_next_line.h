/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:37:26 by orazafin          #+#    #+#             */
/*   Updated: 2017/04/06 18:50:42 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8
# include "./Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_file
{
	int				fd;
	char			*str;
	struct s_file	*next;
	char			*tmp;
}					t_file;

int					get_next_line(int fd, char **line);
#endif
