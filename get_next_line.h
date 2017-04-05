#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8
# include "Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);

typedef struct      s_file
{
	int             fd;
	char            *str;
	struct s_file   *next;
}                   t_file;

#endif
