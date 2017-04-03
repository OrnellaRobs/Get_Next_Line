#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

//NE PAS OUBLIER D'ENLEVER LA LIBRAIRIE stdio + LES LIB DE OPEN ET DE READ !!!!!!!

# define BUFF_SIZE 8
//#include <stdio.h>
#include "Libft/libft.h"
#include <unistd.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <fcntl.h>
#include <stdlib.h>

//int		main(int argc, char const *argv[]);
int		get_next_line(int fd, char **line);

#endif
